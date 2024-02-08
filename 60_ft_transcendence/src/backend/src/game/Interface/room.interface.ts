import { Ball } from "./ball.interface";
import { IPlayer } from "./player.interface";
import { IgameParams } from "./gameParam.interface";
import { Iobstacles } from "./obstacle.interface";

export type GameStatus = 'IN_WAITING_ROOM' | 'WAITING_FOR_PLAYER' | 'WAITING_TO_START' | 'STARTING' | 'PLAYING' | 'FINISHED' | 'FINISH_BY_FORFAIT';

export type TypeGame = 'BASIC' | 'ADVANCED';

export interface Room {
	id:number;
	balls:Ball[];
	obstacles:Iobstacles[];
	ballHasLeft:boolean;
	playerLeft:IPlayer | null;
	playerRight:IPlayer | null;
	scoreLeft:number;
	scoreRight:number;
	gameStatus:GameStatus;
	createdOn: Date;
	finishOn: Date | null;
	startingCountDownStart: Date | null;
	startingCount: number;
	bddGameId:number;
	typeGame:TypeGame;
	gameParam: IgameParams;
  }