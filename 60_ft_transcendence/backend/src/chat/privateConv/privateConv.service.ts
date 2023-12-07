import { Injectable } from "@nestjs/common";
import { PrismaChatService } from "../../prisma/chat/prisma.chat.service";
import { parse } from "path";
import { Socket } from "socket.io";
import { getDate } from "../utils/utils.service";

@Injectable()
export class PrivateConvService {
	constructor(private prismaService:PrismaChatService){
	}

	async setDirectConv(creatorUsername:string, creatorId:number, creatorReceiver: string, sockSender:Socket, sockReceiver: Socket | null)
	{
		const ChatCreated = await this.createDirectConv(creatorUsername, creatorId, creatorReceiver);
		if (ChatCreated)
		{
			const added = await this.prismaService.addChanelUser(ChatCreated, creatorId, "user", getDate(), null)
			if (added)
			{
				const IdReceiver = await this.prismaService.getIdOfUsername(creatorReceiver)
				if (IdReceiver)
				{
					const added2 = await this.prismaService.addChanelUser(ChatCreated, IdReceiver, "user", getDate(), null)
					if (added2)
					{
						this.addSocketToRoom(ChatCreated, sockSender, sockReceiver)
						return (ChatCreated);
					}
					return (ChatCreated);
				}
			}
		}
		return (ChatCreated); 
	}

	async addSocketToRoom(chat_id: number, senderSock: Socket, receiverSock: Socket | null) {
		senderSock.join(chat_id.toString());
		if (receiverSock)
			receiverSock.join(chat_id.toString());
	}

	async createDirectConv(creator:string,creatorId:number, receiver: string)
	{
			const idOfChat = await this.prismaService.addDmChat(creator + " " + receiver, "DM", creatorId);
			return idOfChat;
	}

}
