import { Body, Controller, Post, Get, Param,Delete } from "@nestjs/common";
import { PrismaChatService } from "src/prisma/chat/prisma.chat.service";
import { MyGateway } from "../gateway/gateway.service";
import { JoinChatService } from "../joinChat/joinChat.service";
import { JwtGuard } from "src/auth/guard";
import { getDate } from "../utils/utils.service";
import { UseGuards, ParseIntPipe } from "@nestjs/common";
import { PrivateConvService } from "../privateConv/privateConv.service";
import { ChatLister } from "../chatLister/chatLister.service";
import * as argon from 'argon2';
import { CreateChatService } from "../createchat/createchat.service";
import { PrismaFriendService } from "src/prisma/friend/prisma.friend.service";
import { BanKickLeaveDto,
	BlockUserDto,
	ChangeChatTypeDto,
	ChatListOfUserDto,
	CreateChatDto,
	InviteUserDto, IsBlockedUserDto, JoinChatDto, PrivateConvDto, SetAdminDto, UnblockUserDto, UpdateDmNameDto } from "../../user/dto/chat.dto";
import { MessageBody } from "@nestjs/websockets";


@UseGuards(JwtGuard)
@Controller('chatOption')
export class ChatOptController {
	constructor(private prismaChatService:PrismaChatService,
		private gateway: MyGateway, private joinChatservice : JoinChatService,
		private privateConv: PrivateConvService,
		private createChatService: CreateChatService,
		private  prismaFriendService: PrismaFriendService) {}

	@Post('setAdmin')
	async setUserAsAdmin(@Body() dto: SetAdminDto){
		const id = await this.prismaChatService.getIdOfLogin(dto.login);

		if (id && (await this.prismaChatService.isAdmin(id, dto.chatId)) === false)
		{

			await this.prismaChatService.changeChatUserRole(dto.chatId, id, "admin");
			return true;
		}
		else
		{
			return false;
		}
	}

	@Get('userInGame/:login')
	async getIfUserInGame(
		@Param('login') login: string,
	){
		return this.prismaFriendService.getIfUserInGame(login);
	}

	@Post('newPrivateConv')
	async onNewPrivateConv(@Body() dto: PrivateConvDto)
	{
		const idReceiver = await this.prismaChatService.getIdOfLogin(dto.loginReceiver);
		const connect = this.gateway.getSocketsArray().find((elem) => elem.idOfLogin === dto.idSender);
		if (connect && idReceiver)
		{
			const exist = await this.prismaChatService.checkIfDmExist(dto.idSender, idReceiver)
			if (exist == -1)
			{
				const receiverSocket = this.gateway.getSocketsArray().find((elem) => elem.idOfLogin === idReceiver);
				if (receiverSocket)
				{
					const usernameSender = await this.prismaChatService.getUsernameWithLogin(connect.login);
					const usernameReceiver = await this.prismaChatService.getUsernameWithLogin(receiverSocket.login);
					if (usernameReceiver && usernameSender)
					{
						const allGood = await this.privateConv.setDirectConv(usernameSender, connect.idOfLogin, usernameReceiver, connect.sock, receiverSocket.sock);
						const chatlister = new ChatLister(this.prismaChatService);
						chatlister.listChatOfUser(connect.idOfLogin, connect.sock);
						return {id: allGood};
					}
				}
				else
				{
					const usernameSender = await this.prismaChatService.getUsernameWithLogin(connect.login);
					const usernameReceiver = await this.prismaChatService.getUsernameWithLogin(dto.loginReceiver);
					if (usernameReceiver && usernameSender)
					{
						const allGood = await this.privateConv.setDirectConv(usernameSender, connect.idOfLogin, usernameReceiver, connect.sock, null);
						const chatlister = new ChatLister(this.prismaChatService);
						chatlister.listChatOfUser(connect.idOfLogin, connect.sock);
						return {id: allGood};
					}
				}
			}
			else
				return {id: exist}
		}
	}

	@Post("updateDmName")
    async updateDmName(
        @Body() dto:UpdateDmNameDto
    )
    {
        const arrayOfDm = await this.prismaChatService.getAllDm(dto.OldUsername);
        if (arrayOfDm)
        {
            await this.prismaChatService.updateNewUsernameOnDm(arrayOfDm, dto.OldUsername, dto.newUsername)
        }
    }



	@Post('inviteUser')
	async inviteUser(@Body() dto:InviteUserDto)
	{
		if (await this.prismaChatService.isOwner(dto.ownerLogin, dto.chat_id))
		{
			const id = await this.prismaChatService.getIdOfUsername(dto.username)
			if ( id > 0)
			{
				const worked = await this.prismaChatService.userAlreadyInChat(id, dto.chat_id)
				if (worked === 0)
				{
					if (await this.prismaChatService.addChanelUser(dto.chat_id, id, "user", getDate(), null))
					{
						const connect = this.gateway.getSocketsArray().find((elem) => elem.idOfLogin === id);
						if (connect)
							connect.sock.join(dto.chat_id.toString());
						return ({message: "ok"});
					}
					return ({message: "issue while adding new user"})
				}
				else if ( worked == 1)
					return ({message: `User ${dto.username} is already in this channel`});
				else if ( worked == 3)
					return ({message: `User ${dto.username} has been banned from this channel`});
				else
				{
					const connect = this.gateway.getSocketsArray().find((elem) => elem.idOfLogin === id);
					if (connect)
						connect.sock.join(dto.chat_id.toString());
					return ({message: "ok"});
				}
			}
			else
				return ({message: `User ${dto.username} doesn't exist`})
		}
		else
			return({message: "You cannot invite anyone if you don't own the channel"})
	}

	@Post('blockUser')
	async blockUser(@Body() dto: BlockUserDto)
	{
		return await this.prismaChatService.blockUser(dto.login, dto.blockedLogin, getDate());
	}

	@Post('unblockUser')
	async unblockUser(@Body() dto: UnblockUserDto)
	{
		return await this.prismaChatService.unblockUser(dto.login, dto.blockedLogin);
	}

	@Post('isBlocked')
	async isBlockUser(@Body() dto: IsBlockedUserDto)
	{
		return await this.prismaChatService.userIsblocked(dto.login, dto.blockedLogin);
	}

	@Post('banUser')
	async banUser(@Body() dto:BanKickLeaveDto){

		const idLogin = await this.prismaChatService.getIdOfLogin(dto.login);
		if (idLogin)
		{
			const isOwner = await this.prismaChatService.isOwner(dto.login, dto.chatId);
			if (!isOwner)
			{

				const banWorks = await this.prismaChatService.banUserPrism(idLogin, dto.chatId);
				if (banWorks)
				{
					const SockArray = this.gateway.getSocketsArray()
					const targetSocket = SockArray.find((socket) => socket.login === dto.login);
					if (targetSocket)
					{

						await this.gateway.onChatListOfUser(targetSocket.login, targetSocket.sock);
						targetSocket.sock.leave(dto.chatId.toString())
						return true
					}
				}
				return false;
			}
			else
				return {isOwner};
		}
		return (false);
	}

	@Get(':login/banned/:chatId')
	async isUserBanned(
		@Param('login') login: string,
		@Param('chatId', ParseIntPipe) chatId: number,
	) {

		const SockArray = this.gateway.getSocketsArray()
		const targetSocket = SockArray.find((socket) => socket.login === login);
		if (targetSocket)
		{
			const isBanned = await this.prismaChatService.checkIfUserIsBanned(chatId, targetSocket.idOfLogin);

			return { isBanned };
		}
	}

	@Post('kickUser')
	async kickUser(@Body() dto:BanKickLeaveDto) {

		const SockArray = this.gateway.getSocketsArray()
		const targetSocket = SockArray.find((socket) => socket.login === dto.login);
		if (targetSocket)
		{
			const isOwner = await this.prismaChatService.isOwner(dto.login, dto.chatId);
			if (!isOwner)
			{

				const kicked = await this.prismaChatService.kickUserFromChat(targetSocket.idOfLogin, dto.chatId);
				if (kicked)
				{

					await this.gateway.onChatListOfUser(dto.login, targetSocket.sock);
					targetSocket.sock.leave(dto.chatId.toString())
					return true
				}
				return false;
			}
			else
				return {isOwner}
		}
		else
		{
			const idLogin = await this.prismaChatService.getIdOfLogin(dto.login);
			if (idLogin)
			{
				const isOwner = await this.prismaChatService.isOwner(dto.login, dto.chatId);
				if (!isOwner)
				{
						const kicked = await this.prismaChatService.kickUserFromChat(idLogin, dto.chatId);
						if (kicked)
						{
							return true
						}
						return false;
				}
				else
					return {isOwner}
			}
			return false
		}
	}

	@Post('leaveChat')
	async onLeaveChat(@Body() dto:BanKickLeaveDto)
	{
		const id = await this.prismaChatService.getIdOfLogin(dto.login);
		if (id)
		{
			if (!await this.prismaChatService.isOwner(dto.login, dto.chatId))
			{

				const succeed = await this.prismaChatService.kickUserFromChat(id, dto.chatId);
				if (succeed)
					return (true);
			}
			else
			{
				const newOwner = await this.prismaChatService.leaveAsOwner(id,dto.chatId);
				return {username: newOwner};
			}
		}
	}

	@Post('changeType')
	async changeChatType(@Body() dto:ChangeChatTypeDto)
	{
		let worked;
		const isOwner = await this.prismaChatService.isOwner(dto.login, dto.chatId);
		if (isOwner)
		{
			if (dto.password.length > 0)
			{
				const hashed_password = await argon.hash(dto.password,);
				worked = await this.prismaChatService.updateChatWithPassword(hashed_password, dto.type, dto.chatId);
			}
			else
			{
				worked = await this.prismaChatService.updateChatTypeNoPass(dto.chatId, dto.type);
			}
			return( worked);
		}
		else
			return ("Not Owner")
	}

	@Post('createChat')
	async onCreateChat(@Body() dto: CreateChatDto)
	{
		const targetSocket = this.gateway.getSocketsArray().find((socket) => socket.login === dto.login);
		if (targetSocket !== undefined)
		{
			const idCreated = await this.createChatService.createChat(dto.login, targetSocket.idOfLogin , dto.chatPassword, dto.chatName, dto.chatType, targetSocket.sock);
			if (idCreated)
			{
				return {id: idCreated};
			}
			else
				return {id: -1};
		}
		return {id: -1};
	}

	@Get("retrieveCommonsChatUser/:chatId")
	async retrieveCommonsChatUser(
		@Param('chatId',ParseIntPipe) chatId: number,
	) {
		const listOfUsers = await this.prismaChatService.retrievChatUser(chatId)
		if (listOfUsers)
			return listOfUsers;
		else
			return [];
	}


	@Get("listOfBlockedUser/:login")
	async listOfBlockUser(
		@Param('login') login: string,
	) {
		const listBlocked = await this.prismaChatService.getListOfBlocked(login)
		if (listBlocked)
			return listBlocked;
		else
			return false;
	}

	@Get(':login/info/:chatId')
	async userInfo(
		@Param('login') login: string,
		@Param('chatId', ParseIntPipe) chatId: number,
	) {

		const userInfo = this.prismaChatService.getChatChannelsUser(login, chatId);

		if (userInfo)
			return userInfo;
	}


	@Post('joinChat')
	async joinChat(@Body() dto: JoinChatDto)
	{
		const SockArray = this.gateway.getSocketsArray();
		const targetSocket = SockArray.find((socket) => socket.login === dto.login);
		if (targetSocket !== undefined)
		{
			const value =  await this.joinChatservice.joinChat(targetSocket.idOfLogin, dto.chat_id, "user", dto.password, targetSocket.sock);
			const chatlister = new ChatLister(this.prismaChatService);
			chatlister.listChatOfUser(targetSocket.idOfLogin, targetSocket.sock);
			return value;
		}
		return false;
	}

	@Delete('deleteMessage/:idMessage')
	async onDeleteMessage (
		@Param('idMessage', ParseIntPipe) idMessage: number,
	)
	{
		return await this.prismaChatService.deleteMessage(idMessage);
	}
}
