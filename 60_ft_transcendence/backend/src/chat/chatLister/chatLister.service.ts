import { Injectable } from "@nestjs/common";
import {MyGateway } from "../gateway/gateway.service";
import { PrismaChatService} from "../../prisma/chat/prisma.chat.service";
import { Socket } from "socket.io";
@Injectable()
export class ChatLister{
	constructor(private prismaService:PrismaChatService){
	}

	async isPartOfRoom(socket: Socket, chatId:number)
	{
		const isPartOfRoom = chatId.toString() in socket.rooms
		if (!isPartOfRoom)
		{
			socket.join(chatId.toString());
		}
	}

	async listChatOfUser(idLogin: number, sock: Socket)
	{
		const chatList = [];
		const retrieveChat = await this.prismaService.getListOfChatById(idLogin);
		if (retrieveChat !== undefined)
		{
			for (const chatUser of retrieveChat)
			{
				const lastMessagesOfChat = await this.prismaService.getLastMessages(chatUser.channel_id);
				let lastMessageUsername = null;
				let date = null;
				let lastMessage = null;
				let message = null;
				await this.isPartOfRoom(sock,chatUser.channel.id);
				if (lastMessagesOfChat !== undefined && lastMessagesOfChat && lastMessagesOfChat.length > 0)
				{
					lastMessage = lastMessagesOfChat[0];

					date = lastMessage.date_sent;
					message = lastMessage.message;
					lastMessageUsername =  await this.prismaService.getLastMessagesUsername(chatUser.channel_id);
				}
				const chatType = {
					id: chatUser.channel.id,
					channelName: chatUser.channel.name,
					username: lastMessageUsername?.username,
					status: chatUser.user_role,
					msg: message,
					dateSend: date,
					type: chatUser.channel.type,
					userId: lastMessageUsername?.id,
					userLogin: lastMessageUsername?.login,
				}
				chatList.push(chatType);
			}
			sock.emit('ListOfChatOfUser', chatList);
		}
	}

	async listAllPublicChat(sock: Socket)
	{
		const chats = await this.prismaService.getListOfChat();

		sock.emit('chatList', chats);
	}
}

