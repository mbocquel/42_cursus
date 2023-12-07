import { ForbiddenException, Injectable } from '@nestjs/common';
import { GameStatus, PrismaGameService } from 'src/prisma/game/prisma.game.service';

export interface statObject {
	userId: number,
	userLogin: string, 
	userUsername: string | null, 
	numberGames: number,
	numberGamesBasic: number,
	numberGamesAdvanced: number,
	numberWon: number,
	numberLost: number,
	numberWonBasic: number,
	numberLostBasic: number,
	numberWonAdvanced: number,
	numberLostAdvanced: number,
	totalGameDurationInSec: number,
	totalGameDurationBasicInSec: number,
	totalGameDurationAdvancedInSec: number,
	games?: {
		id: number;
    	type: string;
   		game_status: string | null;
    	won: boolean;
		opponentId: any;
		opponentUserName: any;
		opponentLogin: any;
		myScore: number | null;
		myOpponentScore: number | null;
		date_begin: Date;
		durationInSec: number | undefined;
	}[]
}

@Injectable()
export class GameStatsService {
	constructor(private prismaService: PrismaGameService){}
	
	async getGameStatsUserByLogin (login:string) {
		try {
			const user = await this.prismaService.getUserFromLogin(login);
			return (this.getGameStatsUser({user, detail:true}));
		}
		catch (error) {
			throw error;
		}
	}

	async getGameStatsUserById (id:number) {
		try {
			const user = await this.prismaService.getUserFromId(id);
			return (this.getGameStatsUser({user, detail:true}));
		}
		catch (error) {
			throw error;
		}
	}

	async getGameStatsUserByUsername (username:string) {
		try {
			const user = await this.prismaService.getUserFromUsername(username);
			return (this.getGameStatsUser({user, detail:true}));
		}
		catch (error) {
			throw error;
		}
	}

	async getGameStatsUser(param: {user :{id: number, username:string | null, login:string}, detail:boolean}) : Promise<statObject> {
		try {
			const gamesUser = await this.prismaService.game.findMany({
				where: {
					OR: [
						{
							player_one_id: param.user.id
						},
						{
							player_two_id: param.user.id
						},
					  ],
				},
				select: {
                    id:true, 
                    type:true, 
                    game_status:true,
                    winner_id: true,
                    player_one_id: true, 
                    player_two_id: true, 
                    player_one_score: true, 
                    player_two_score: true, 
                    date_begin:true, 
                    date_end: true,
                    player_one: true, 
                    player_two: true
                }
			});
			const gamesUserTimePlayed = gamesUser.map((game) => {
                const opponent = game.player_one_id === param.user.id ? game.player_two : game.player_one;
                return ({
                    id:game.id, 
                    type:game.type, 
                    game_status:game.game_status,
                    won: game.winner_id === param.user.id ? true : false, 
                    opponentId: opponent.id,
                    opponentUserName: opponent.username,
                    opponentLogin:opponent.login,
                    myScore: game.player_one_id === param.user.id ? game.player_one_score : game.player_two_score,
                    myOpponentScore: game.player_one_id === param.user.id ? game.player_two_score : game.player_one_score,
                    date_begin:game.date_begin,
                    durationInSec:game.date_end ? (game.date_end.getTime() - game.date_begin.getTime())/1000 : undefined,
                })
            });
	
			const gameWonByUser = gamesUserTimePlayed.filter((game) => {return (game.won === true)});
			const gameLostByUser = gamesUserTimePlayed.filter((game) => {return (game.won === false)});
			const totalGameDuration = gamesUserTimePlayed.reduce((accumulator, currentValue) => {
				if (typeof(currentValue.durationInSec) === 'undefined'){
					return (accumulator)
				}
				else {
					return (accumulator + currentValue.durationInSec)
				}
			}, 0);
	
			const totalGameDurationBasic = gamesUserTimePlayed.filter((game)=>{return (game.type === 'BASIC')}).reduce((accumulator, currentValue) => {
				if (typeof(currentValue.durationInSec) === 'undefined'){
					return (accumulator)
				}
				else {
					return (accumulator + currentValue.durationInSec)
				}
			}, 0);
	
			const totalGameDurationAdvanced = gamesUserTimePlayed.filter((game)=>{return (game.type !== 'BASIC')}).reduce((accumulator, currentValue) => {
				if (typeof(currentValue.durationInSec) === 'undefined'){
					return (accumulator)
				}
				else {
					return (accumulator + currentValue.durationInSec)
				}
			}, 0);
			
			const dataToReturn : statObject = {
				userId: param.user.id,
				userLogin: param.user.login, 
				userUsername: param.user.username, 
				numberGames: (gameWonByUser.length + gameLostByUser.length),
				numberGamesBasic: (gameWonByUser.filter((game)=>{return (game.type === 'BASIC')}).length + gameLostByUser.filter((game)=>{return (game.type === 'BASIC')}).length),
				numberGamesAdvanced: (gameWonByUser.filter((game)=>{return (game.type === 'ADVANCED')}).length + gameLostByUser.filter((game)=>{return (game.type === 'ADVANCED')}).length),
				numberWon: gameWonByUser.length, 
				numberLost: gameLostByUser.length, 
				numberWonBasic: gameWonByUser.filter((game)=>{return (game.type === 'BASIC')}).length, 
				numberLostBasic: gameLostByUser.filter((game)=>{return (game.type === 'BASIC')}).length, 
				numberWonAdvanced: gameWonByUser.filter((game)=>{return (game.type === 'ADVANCED')}).length,
				numberLostAdvanced: gameLostByUser.filter((game)=>{return (game.type === 'ADVANCED')}).length,
				totalGameDurationInSec: totalGameDuration,
				totalGameDurationBasicInSec:totalGameDurationBasic, 
				totalGameDurationAdvancedInSec: totalGameDurationAdvanced, 
				games: gamesUserTimePlayed
			};
			if (param.detail === false) {
				delete dataToReturn.games;
			}
			return (dataToReturn);
		}
		catch (error) {
			throw (error);
		}
	}

	async getGameStatsAllUsers() {
		const dataToReturn = [];
		const userArray = await this.prismaService.user.findMany({
			select: {
				id:true, 
				username:true, 
				login:true,
			}
		});

		for (let i = 0; i < userArray.length; i++){
			const elem = await this.getGameStatsUser({user:userArray[i], detail:false});
			dataToReturn.push(elem);
		}
		return(dataToReturn);
	}
}
