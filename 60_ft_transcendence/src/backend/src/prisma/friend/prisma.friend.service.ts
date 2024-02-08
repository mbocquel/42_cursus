import { Injectable } from "@nestjs/common";
import { PrismaClient } from '@prisma/client'
import { OnModuleInit } from "@nestjs/common";
import { PrismaChatService } from "../chat/prisma.chat.service";
import { NotFoundException } from "@nestjs/common";

@Injectable()
export class PrismaFriendService extends PrismaClient{

	async getIdOfLogin(login: string){ // this need to be removed

		const user = await this.user.findFirst({
			where: {
				login: login,
			}
		})
		if (user)
			return user.id;
	}

	async addFriend(idLogin: number, newFriend: string)
	{

			const idFriend = await this.getIdOfLogin(newFriend);

			if (idFriend && await this.alreadyFriend(idLogin, idFriend) === false)
			{

				const created = await this.friend.create ({
					data : {
						user_id: idLogin,
						friend_id: idFriend,
					}
				})

				return created;
			}
	}

	async alreadyFriend(idLogin: number, idFriend:number)
	{
		const friend = await this.friend.findFirst({
			where :{
				user_id: idLogin,
				friend_id: idFriend,
			}
		})
		if (friend)
			return true
		return false
	}

	async getFriendRelationId(idLogin: number, idFriend:number)
	{
		const friend = await this.friend.findFirst({
			where :{
				user_id: idLogin,
				friend_id: idFriend,
			}
		})
		if (friend)
			return friend.id
		return false
	}

	async idFriendToDelete(idLogin: number, idFriend:number)
	{
		const friend = await this.friend.findFirst({
			where :{
				user_id: idLogin,
				friend_id: idFriend,
			}
		})
		if (friend)
			return friend.id
		return false
	}

	// async alreadyFriend(idLogin: number, idFriend:number)
	// {

	// 	const friend = await this.friend.findFirst({
	// 		where :{
	// 			user_id: idLogin,
	// 			friend_id: idFriend,
	// 		}
	// 	})

	// 	if (friend)
	// 		return friend.id
	// 	 return undefined
	// }

	async deleteFriend(idLogin:number, idFriend:number)
	{
			const friendToDelete = await this.getFriendRelationId(idLogin, idFriend);

			if (friendToDelete)
			{
				const deleted = await this.friend.delete({
				where :{
					id: friendToDelete
				}
				})
				if (deleted)
					return true
			}
			return false
	}

	async getIfUserInGame(login: string) {
		const idOfLogin = await this.getIdOfLogin(login);
		if (idOfLogin)
		{
			const inGame = await this.game.findFirst({
				where: {
					game_status:"ONGOING",
					OR: [
						{
							player_one_id: idOfLogin,
						},
						{
							player_two_id:idOfLogin,
						}
					]
				}
			})
			if (inGame)
				return ({
					login: login,
					inGame: true
				});
			else {
				return ({
					login: login,
					inGame: false
				});
			}
		}
		else throw new NotFoundException('User not Found, try something else...');
	}

	async checkInGame(id: number) {
		const inGame = await this.game.findFirst({
			where: {
				game_status:"ONGOING",
				OR: [
					{
						player_one_id: id,
					},
					{
						player_two_id:id,
					}
				]
			}
		})
		if (inGame)
			return true;
		return false;
	}


	async getLoginOfId(id:number)
	{
		const login = this.user.findFirst({
			where: {
				id: id,
			}
		})
		if (login)
			return (login);
	}
	async listAllFriends(login:string)
	{
		const idOfLogin = await this.getIdOfLogin(login);
		if (idOfLogin)
		{
			const listsFriends = await this.friend.findMany({
				where:{
					user_id: idOfLogin
				}
			})
			if (listsFriends)
				return listsFriends;
		}
	}
	// async removeFriend(login: string, friendToRemove: string)
	// {
	// 	const idLogin
	// }
}
