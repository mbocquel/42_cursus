import { Body, Controller, Post, Get, Param } from "@nestjs/common";
import { GameStatsService } from "./gameStats.service";

import { JwtGuard } from '../auth/guard';
import { UseGuards } from "@nestjs/common";

@UseGuards(JwtGuard)
@Controller('gameStats')
export class gameStatsControler {
	constructor(private gameStatsService: GameStatsService){}

	@Get('/login/:login')
	async getGameStatsUserByLogin(
		@Param('login') login: string,
	){
		return this.gameStatsService.getGameStatsUserByLogin(login);
	}

	@Get('/username/:username')
	async getGameStatsUserByUsername(
		@Param('username') username: string,
	){
		return this.gameStatsService.getGameStatsUserByUsername(username);
	}

	@Get('/id/:id')
	async getGameStatsUserById(
		@Param('id') id: string,
	){
		return this.gameStatsService.getGameStatsUserById(parseInt(id));
	}

	@Get()
	async getGameStatsAllUsers(){
		return this.gameStatsService.getGameStatsAllUsers();
	}

}
