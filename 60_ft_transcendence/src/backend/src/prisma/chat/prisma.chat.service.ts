import { PrismaClient } from '@prisma/client'
import { Injectable } from "@nestjs/common";
import e from 'express';
import { get } from 'http';


export enum ChatType {
	NotExisting = -1,
	Public = 0,
	Private = 1,
	Password = 2,

}

@Injectable()
export class PrismaChatService {
	private prismaService: PrismaClient;

	constructor() {
		this.prismaService = new PrismaClient(); // verifier si on a vraiment besoin de faire ca
												// ou si recuperes tous le me prisma client
	  }

	async getIdOfLogin(login: string){

		const user = await this.prismaService.user.findFirst({
			where: {
				login: login,
			}
		})
		if (user)
			return user.id;
		else
		{
			return 0;
		}
	}

	async retrievChatUser(chatId:number)
	{
		let userAvatar = [];
		const listOfUser = await this.prismaService.user.findMany()
		if (listOfUser)
		{
			for (const element of listOfUser)
			{
				const obj = {
					login : element.login,
					avatar: element.avatar,
				}
				userAvatar.push(obj);
			}
			return userAvatar;
		}
		else
			return null;
	}

	async checkIfDmExist(idSender:number, idReceiver: number)
	{
		const exist =  await this.prismaService.chatChannels.findMany({
			where:{
				type: "DM",
				OR : [
					{
						owner: idSender,
					},
					{
						owner: idReceiver,
					},
				],
			},
			include: {
				channelsUsers:true,
			}
		})
		if (exist)
		{
			for (const element of exist)
			{
				if (element.channelsUsers.find((elem:any) => elem.user_id === idSender && element.owner !== elem.user_id)
					|| element.channelsUsers.find((elem:any) => elem.user_id === idReceiver && element.owner !== elem.user_id))
				{
					return element.id;
				}
			}
			return (-1);
		}
		return (-1);
	}

	async userAlreadyInChat(userId: number, chatId:number)
	{
		const inChat = await this.prismaService.chatChannelsUser.findFirst({
			where:{
				channel_id: chatId,
				user_id: userId,
			}
		})
		if (inChat)
		{
			if (inChat.kicked == true)
			{
				const worked = await this.prismaService.chatChannelsUser.update({
					where: {
						id : inChat.id,
					},
					data : {
						kicked : false
					}
				})
				if (worked)
					return (2);
			}
			if (inChat.banned == true)
				return (3);
			return (1);
		}
		return 0;
	}

	async getIdOfUsername(username: string){

		const user = await this.prismaService.user.findFirst({
			where: {
				username: username,
			}
		})
		if (user)
			return user.id;
		else
		{
			return 0;
		}
	}

	async deleteMessage(idMesage: number)
	{
		const messageExist = await this.prismaService.chatMsgHistory.findFirst({
			where:{
				id:idMesage,
			}
		})
		if (messageExist)
		{
			const messageDelete = await this.prismaService.chatMsgHistory.delete({
				where:{
					id: idMesage,
				}
			})
			if (messageDelete)
				return (true);
			return false;
		}
		return false;

	}
	async updateChatWithPassword(password:string, type:string, chatId:number)
	{
		const updated = await this.prismaService.chatChannels.update({
			where: {
				id: chatId,
			},
			data: {
				password: password,
				type: type,
			}
		})
		if (updated)
			return true;
		else
			return false;
	}

	async retrieveChannelsUsers(chat_id:number)
	{
		const list = await this.prismaService.chatChannelsUser.findMany({
			where: {
				channel_id: chat_id,
				banned:false,
				kicked:false,
			}
		})
		if (list)
			return list;
	}

	async findOldestMember(tabOfUser:any, ownerId:number)
	{

		const getChatChannelsUser = await this.getChatChannelsUser
		let lastId = (tabOfUser.find((element: any) => element.id != ownerId)).id;
		let lastDate:Date = (tabOfUser.find((element: any) => element.id != ownerId)).date_joined;
		for (const element of tabOfUser)
		{

			if (lastDate > element.date_joined && ownerId !== element.id )
			{
				lastDate = element.date_joined;
				lastId = element.id;
			}
		}
		return (lastId)
	}

	async getUserOfChatChannelUserId(chatUserId:number)
	{
		const userId = await this.prismaService.chatChannelsUser.findFirst({
			where:{
				id:chatUserId,
			},
			include:{
				chatChannelsUser:true,
			}
		})

		if (userId)
			return userId.chatChannelsUser;
	}

	async getAllDm(oldUsername: string)
    {
        const arrayOfDm = await this.prismaService.chatChannels.findMany({
            where: {
                type: "DM",
                name: {
                    contains: oldUsername,
                }
            }
        })
        if (arrayOfDm)
        {
            return (arrayOfDm);
        }
    }

    async updateNewUsernameOnDm(arrayOfDm:any, oldUsername:string, newUsername:string)
    {
        for (const element of arrayOfDm)
        {
            const nameParts = element.name.split(' ');
            const indexOfOldUsername = nameParts.indexOf(oldUsername);
            if (indexOfOldUsername !== -1) {
                nameParts[indexOfOldUsername] = newUsername;
                const newName = nameParts.join(' ');
                const worked = await this.prismaService.chatChannels.update({
                    where:{
                        id:element.id,
                    },
                    data:{
                        name: newName,
                    }
                })
            }
        }
    }

	async changeOwner(userId:number, listUsersOfChat:any, chatId:number )
	{

		const idChannelUser = await this.getIdOfChatChannelsUser(userId, chatId);

		if (idChannelUser)
		{
			const oldestChatChannelsUser = await this.findOldestMember(listUsersOfChat,idChannelUser);

			const succeed = await this.prismaService.chatChannelsUser.update({
				where: {
					id:idChannelUser
				},
				data:{
					kicked:true,
					user_role: "user"
				}
			})


			if (succeed && oldestChatChannelsUser)
			{

				const updateChatChannelUser = await this.prismaService.chatChannelsUser.update({
					where:{
						id:oldestChatChannelsUser,
					},
					data:{
						user_role: "owner"
					}
				})
				const userIdOfNewOwner = await this.getUserOfChatChannelUserId(oldestChatChannelsUser);
				if (userIdOfNewOwner)
				{
					const updateChatOwner = await this.prismaService.chatChannels.update({
						where:{
							id:chatId
						},
						data:{
							owner: userIdOfNewOwner.id,
						}
					})
					return (userIdOfNewOwner.username); //login ou username
				}
			}
		}
	}

	async leaveAsOwner(userId:number, chatId:number)
	{
		const listUsersOfChat = await this.retrieveChannelsUsers(chatId)

		if (listUsersOfChat)
		{
			if (listUsersOfChat.length === 1)
			{
				const deleted = await this.prismaService.chatChannels.deleteMany({
					where: {
						id: chatId
					}
				})

				if (deleted)
					return true
			}
			else
			{
				return await this.changeOwner(userId, listUsersOfChat, chatId);

			}
		}
	}

	async userIsblocked(login: string, userBlockedLogin: string)
	{
		const getLogId = await this.getIdOfLogin(login);
		const getBlockedId = await this.getIdOfLogin(userBlockedLogin);
		if (getLogId && getBlockedId)
		{
			const isBlocked = await this.prismaService.blockedUser.findFirst({
				where: {
					user_id: getLogId,
					blocked_user_id: getBlockedId,
				}
			})
			if (isBlocked)
				return true;
		}
		return false;
	}

	async blockUser(login: string, userBlockedLogin:string, date: Date)
	{
		const getLogId = await this.getIdOfLogin(login);
		const getBlockedId = await this.getIdOfLogin(userBlockedLogin);
		if (getLogId && getBlockedId)
		{
			const isBlocked = await this.prismaService.blockedUser.create({
				data: {
					user_id :getLogId,
					blocked_user_id: getBlockedId,
					date_blocked: date,
				}
			})
			if (isBlocked)
				return (true);
		}
		return false;
	}

	async getUserOfId(id: number)
	{
		const user = this.prismaService.user.findFirst({
			where: {
				id: id,
			}
		})
		if (user)
			return user;
	}

	async getListOfBlocked(login:string)
	{
		const getLogId = await this.getIdOfLogin(login);
		if (getLogId)
		{
			const list = await this.prismaService.blockedUser.findMany({
				where :{
					user_id : getLogId,
				},
			})
			const listChanged = [];
			if (list)
			{
				for (const element of list)
				{
					const userBlocked = await this.getUserOfId(element.blocked_user_id)
					if (userBlocked)
					{
						const obj = {
							idUser: element.blocked_user_id,
							username:  userBlocked.username,
							login: userBlocked.login,
						}
						listChanged.push(obj);
					}
				}
				return (listChanged);
			}

		}
	}

	async unblockUser(login: string, userBlockedLogin:string)
	{
		const getLogId = await this.getIdOfLogin(login);
		const getBlockedId = await this.getIdOfLogin(userBlockedLogin);
		if (getLogId && getBlockedId)
		{
			const isBlocked = await this.prismaService.blockedUser.findFirst({
				where: {
					user_id: getLogId,
					blocked_user_id: getBlockedId,
				}
			})
			if (isBlocked)
			{
				const RemoveBlocked = await this.prismaService.blockedUser.delete({
					where :{
						id : isBlocked.id,
					}
				})
				if (isBlocked)
					return (true);
			}

		}
		return false;
	}

	async updateChatTypeNoPass(chatId:number, chatType:string)
	{
		const updated = await this.prismaService.chatChannels.update({
			where: {
				id: chatId,
			},
			data: {
				password: null,
				type: chatType,
			}
		})
		if (updated)
			return true;
		else
			return false;

	}

	async BanUserFromChannel(idLogin: number, chatId: number)
	{
			const recordToDelete = await this.prismaService.chatChannelsUser.findFirst({
			  where: {
				user_id: idLogin,
				channel_id: chatId,
			  },
			});

			if (recordToDelete) {
			  // Use the ID to delete the record
			  const removedUser = await this.prismaService.chatChannelsUser.update({
				where: {
				  id: recordToDelete.id,
				},
				  data: {
					banned: true,
				  } // Use the ID to uniquely identify the record
			  });
			}
	}

	async userHasbeenKickedInChat(user_id:number, chat_id:number) {
		const userExistInChat = await this.prismaService.chatChannelsUser.findFirst({
			where: {
			  user_id: user_id,
			  channel_id: chat_id,
			  kicked:true,
			},
		})
		if (userExistInChat)
		{
			const worked = await this.prismaService.chatChannelsUser.update({
				where: {
					id : userExistInChat.id,
				},
				data : {
					kicked : false
				}
			})
			return true;
		}
		return false;
	}

	async kickUserFromChat(idLogin:number, chatId: number)
	{
			// Fetch the ID of the record to delete based on user_id and channel_id
			const recordToDelete = await this.prismaService.chatChannelsUser.findFirst({
			  where: {
				user_id: idLogin,
				channel_id: chatId,
			  },
			});

			if (recordToDelete) {
			  // Use the ID to delete the record
			  const removedUser = await this.prismaService.chatChannelsUser.update({
				where: {
				  id: recordToDelete.id,
				},
				  data: {
					kicked: true,
				  } // Use the ID to uniquely identify the record
			  });
			  if (removedUser)
			  	return true;
			}
			return false;
		return false;
	}

	async banUserPrism(idLogin:number, chatId : number)
	{
		if (! await this.checkIfUserIsBanned(chatId, idLogin)) // changed
		{
			const banned = await this.prismaService.usersBannedToChats.create({
				data: {
					userId :idLogin,
					chatId : chatId,
				}
			})
			if (banned)
			{
				await this.BanUserFromChannel(idLogin, chatId);
				return true;
			}
		}
		return false;
	}

	async getPasswordOfChat(chat_channels_id: number){
		const chat = await this.prismaService.chatChannels.findFirst({
			where: {
				id: chat_channels_id,
			}
		})
		if (chat)
			return chat.password;
	}

	async checkIfUserIsBanned(chat_channels_id: number, idLogin: number)
	{

			const isBanned = await this.prismaService.usersBannedToChats.findFirst({
				where: {
					userId: idLogin,
					chatId: chat_channels_id,
				}
			})
			if (isBanned)
				return true;
			else
				return false;
		return false;
	}

	async getIdOfChatChannelsUser(idLogin:number , chat_channels_id: number){
		const user = await this.prismaService.chatChannelsUser.findFirst({
			where: {
				user_id: idLogin,
				channel_id: chat_channels_id,
			}
		})
		if (user)
		{

			return user.id;
		}
		else {

		}
	}

	async changeChatUserRole(chat_channels_id: number, loginId: number, user_role: string)
	{
		const user = await this.prismaService.chatChannelsUser.findFirst({
			where: {
				user_id: loginId,
				channel_id: chat_channels_id,
			}
		})
		if (user)
		{

			await this.prismaService.chatChannelsUser.update({
				where: {
					id: user.id,
				},
				data: {
					user_role: user_role,
				}
			})
		}
	}

	async isOwner(login : string, chatId: number)
	{

		const heIsOwner = await this.prismaService.chatChannels.findUnique({
			where: {
				id: chatId,
			  },
			  select: {
				channelOwner: {
				  select: {
					login: true,
				  },
				},
			  },
			});
		if (!heIsOwner)
			return false;
		return heIsOwner.channelOwner.login === login
	}

	async isAdmin(idLogin: number, chatId:number)
	{
			const heIsAdmin = await this.prismaService.chatChannelsUser.findFirst({
				where: {
					channel_id: chatId,
					user_id: idLogin,
				  },
				});
			if (!heIsAdmin)
				return false;
			if (heIsAdmin.user_role === "admin")
				return true;
		return false;
	}

	async RetrieveChatMessage(chat_channels_id: number) {
			// Find the chat channel by its ID

			const chatChannel = await this.prismaService.chatChannels.findUnique({
			  where: {
				id: chat_channels_id,
			  },
			  include: {
				// Include the related chat messages (ChatMsgHistory)
				chatMessages: true,
			  },
			});
			if (chatChannel)
			{

				return chatChannel.chatMessages;
			}
	}

	async getChatChannelsUser(login:string, chatId: number)
	{
		const idOfLogin = await this.getIdOfLogin(login);
		if (idOfLogin)
		{
			const chatUserId = await this.getIdOfChatChannelsUser(idOfLogin, chatId);
			if (chatUserId)
			{
				const user = await this.prismaService.chatChannelsUser.findUnique({
					where: {
						id: chatUserId,
					},
				})
				if (user)
				{
					return user;
				}

			}
		}
	}

	async addChatMessage(chatChanelId: number, loginId: number, message:string, date:Date, serviceMessage: boolean )
	{
		const chat_channels_user_id = await this.getIdOfChatChannelsUser(loginId, chatChanelId);
		if (chat_channels_user_id !== undefined)
		{

			const newMessage = await this.prismaService.chatMsgHistory.create({
				data: {
					date_sent: date,
					message: message,
					chat_channels_id: chatChanelId,
					chat_channels_user_id: chat_channels_user_id,
					serviceMessage: serviceMessage,
				},
			})
		}
		else
		{

		}
	}

	 async addChanelUser(channel_id : number, user_id : number, user_role:string, date_joined:Date, date_left:Date | null)
	{
		if (await this.userHasChatChannelsUser(user_id, channel_id)) {

			return (0);
		}
		else {

			const newMessage = await this.prismaService.chatChannelsUser.create ({
				data: {
					channel_id: channel_id,
					user_id: user_id,
					user_role: user_role,
					date_joined: date_joined,
					date_left: date_left,
					kicked: false,
					banned: false,
				}
			})
			return (newMessage.id)
		}
	}

	async getUsernameWithLogin(loginUser: string)
	{
		const user = await this.prismaService.user.findFirst({
			where: {
				login: loginUser,
			},
		})
		if (user)
			return (user.username);

	}

	async getListOfChatById(loginId: number)
	{
		const userChatChannels = await this.prismaService.chatChannelsUser.findMany({
			where: {
				user_id: loginId,
				banned: false,
				kicked:false,
			},
			include: {
				channel: true,
			},
		})
		return userChatChannels;
	}

	async getListOfChat()
	{
		//ajouter les password protected
		const chatChanel = await this.prismaService.chatChannels.findMany({
			where:{
				type: {
					in: ["public", "protected by password"],
				  },
			}
		})
		return chatChanel;
	}

	async getLastMessages(id:number)
	{
		const lastMessagesOfChat = await this.prismaService.chatMsgHistory.findMany({
			where:{
				chat_channels_id: id,
			},
			orderBy: {
				date_sent: 'desc',
			},
			take: 1,
			}
		)
		return lastMessagesOfChat ? lastMessagesOfChat : null;
	}

	async getOwnerOfChatAvatar(id:number)
	{
		const owner = await this.prismaService.chatChannels.findUnique({
			where:{
				id: id,
			},
			include: {
				channelOwner: true,
			},
		})
		if (owner)
		{
			return owner.channelOwner.avatar;
		}
	}


	async addPrivateMessage(sender_id: number, receiver_id: number, message: string) {
		const newMessage = await this.prismaService.directMsg.create({
			data: {
				message: message,
				sender_id: sender_id,
				receiver_id: receiver_id,
				msg_status: 'unread',
			},
		})
	}

	async findUser(chat_channels_user_id: number) {
		const user = await this.prismaService.chatChannelsUser.findUnique({
			where: {
				id: chat_channels_user_id,
			},
			include: {
				chatChannelsUser: true,
			},
		})
		if (user)
		{
			return user.chatChannelsUser;
		}
	}

	async addDmChat(chatName: string, chatType: string, chatOwnerId: number)
	{
		const alreadyIn = await this.prismaService.chatChannels.findFirst({
			where: {
				type: chatType,
				name: chatName,
			}
		})
		if (!alreadyIn)
		{
			const newChat = await this.prismaService.chatChannels.create({
				data: {
					type: chatType,
					name: chatName,
					password: null,
					channelOwner: {
						connect: { id: chatOwnerId }
					}
				}
			})
			return newChat.id;
		}
	}


	async addChat(chatName: string, chatType: string, chatOwnerId: number, chatPassword: string | null) {
			const newChat = await this.prismaService.chatChannels.create({
				data: {
					type: chatType,
					name: chatName,
					password: chatPassword,
					channelOwner: {
						connect: { id: chatOwnerId }
					}
				}
			})
			return newChat.id;
	}

	async getLastMessagesUsername(chatId: number) {

			const lastMessageUsername = await this.prismaService.chatMsgHistory.findFirst({
			  where: { chat_channels_id : chatId },
			  orderBy: { date_sent: 'desc' },
			  take: 1,
			});
			if (lastMessageUsername)
			{
				const username = await this.findUser(lastMessageUsername.chat_channels_user_id);

				return username;
			}
			return null;
	}


	async checkChatId(idSearched: number) {
		const chat = await this.prismaService.chatChannels.findFirst({
			where: {
				id: idSearched,
			},
		})
		if (chat) {
			if (chat.type === 'public')
				return ChatType.Public;
			else
			{
				if (chat.password !== null)
					return ChatType.Password;
				else
					return ChatType.Private;
			}
		}
		else{
			return ChatType.NotExisting;
		}
	}

	async checkLogin(login: string) {

		const user = await this.prismaService.user.findFirst({
			where: {
				login: login,
			},
		})
		if (user) {
			return true;
		}
		else{
			return false;
		}
	}

	async userHasChatChannelsUser(userId: number, channelId: number) {
		const chatChannelsUser = await this.prismaService.chatChannelsUser.findFirst({
		  where: {
			user_id: userId,
			channel_id: channelId,
		  },
		});

		return !!chatChannelsUser; // Returns true if the record exists, false if it doesn't
	  }
	//---------------------->
}
