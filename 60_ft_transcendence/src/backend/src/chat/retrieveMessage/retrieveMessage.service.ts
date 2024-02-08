import { Injectable } from "@nestjs/common";
import { PrismaChatService } from "../../prisma/chat/prisma.chat.service";
import { parse } from "path";
import { Socket } from "socket.io";


@Injectable()
export class RetrieveMessageService {
	constructor(private prismaService:PrismaChatService){
	}

	async retrieveMessage(chat_id: number, NumToDisplay: number, sock : Socket)
	{
		const messageHistory = [];
		if (chat_id !== undefined)
		{
			const messageReceived = await this.prismaService.RetrieveChatMessage(chat_id);

			if (messageReceived !== undefined)
			{
				for (const element of messageReceived) {
					const user = await this.prismaService.findUser(element.chat_channels_user_id);
					if (user)
					{
						const msg = {
							msg: element.message,
							username: user.username,
							date: element.date_sent,
							id: element.id,
							login: user.login,
							chatId: element.chat_channels_id,
							serviceMessage: element.serviceMessage,
							userId: user.id,
						}
						messageHistory.push(msg);
					}
				};
				sock.emit('chatMsgHistory', messageHistory);
			}
		}
	}
}
