import { Body, Controller, Post, Get, Param,Delete } from "@nestjs/common";
import { PrismaChatService } from "src/prisma/chat/prisma.chat.service";
import { PrismaFriendService } from "src/prisma/friend/prisma.friend.service";
import { MyGateway } from "src/chat/gateway/gateway.service";
import { JwtGuard } from '../auth/guard';
import { GetUser } from '../auth/decorator';
import { UseGuards,ParseIntPipe } from "@nestjs/common";

@UseGuards(JwtGuard)
@Controller('friend')
export class addFriendController {
	constructor(private prismaFriendService: PrismaFriendService, private gateway: MyGateway)
	{}

	@Post('addFriend')
	async addFriend(@Body() dto:{login:string, friendToAdd:string})
	{

		const SockArray = this.gateway.getSocketsArray()
		const targetSocket = SockArray.find((socket) => socket.login === dto.login);
		if (targetSocket)
		{
			await this.prismaFriendService.addFriend(targetSocket.idOfLogin, dto.friendToAdd);
		}
	}

	@Get(':myLogin/:loginFriend/isMyFriend')
	async checkIfFriend (
		@Param('myLogin') myLog:string,
		@Param('loginFriend') friendLog: string,
	)
	{
		const idLog = await this.prismaFriendService.getIdOfLogin(myLog);
		const idFriend = await this.prismaFriendService.getIdOfLogin(friendLog);
		if (idLog && idFriend)
		{
			const friend = await this.prismaFriendService.alreadyFriend(idLog, idFriend);

			return friend;
		}
	}

	@Delete('deleteFriend/:idFriend/:idUser')
	async deleteFriend(
		@Param('idFriend', ParseIntPipe) idFriend:number,
		@Param('idUser', ParseIntPipe) idUser:number)
	{

		const succeed = await this.prismaFriendService.deleteFriend(idUser, idFriend)
		if (succeed)
		{

		}
	}

	@Get('listFriends/:login')
	async listFriend (
		@Param('login') login:string
	)
	{
		const listFriends = [];
		let connected;

		const list = await this.prismaFriendService.listAllFriends(login);
		if (list)
		{
			const SockArray = this.gateway.getSocketsArray();
			for (const element of list)
			{
				const getLoginOfId = await this.prismaFriendService.getLoginOfId(element.friend_id);
				if (getLoginOfId)
				{
					const connect = SockArray.find((item) => item.idOfLogin === element.friend_id);
					if (connect)
					{
						const inGame = await this.prismaFriendService.checkInGame(getLoginOfId.id);
						if (inGame)
							connected = "in Game";
						else
							connected = "online";
					}
					else
						connected = "offline";
					const friend = {
						avatar: getLoginOfId.avatar,
						username: getLoginOfId.username,
						connected: connected,
						id: getLoginOfId.id,
						login: getLoginOfId.login,
					}
					listFriends.push(friend);
				}
			}
		}
		return listFriends;
	}
}
