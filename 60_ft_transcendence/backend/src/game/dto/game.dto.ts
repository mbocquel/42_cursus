import { TypeGame } from '../Interface/room.interface';
import {
    IsNotEmpty,
    IsNumber,
    IsString,
	IsBoolean,  
  } from 'class-validator';

export class JoinWaitingRoomDto {
	@IsString()
	@IsNotEmpty()
	playerName:string;
	
	@IsString()
	@IsNotEmpty()
	typeGame:TypeGame;
}
export class JoinGameDto {
	@IsNumber()
	@IsNotEmpty()
	roomId:number; 
	
	@IsString()
	@IsNotEmpty()
	playerName:string;
}

export class GiveMeRoomStatusDto {
	@IsNumber()
	@IsNotEmpty()
	roomId:number; 
}

export class PlayerKeyEventDto {
	@IsNumber()
	@IsNotEmpty()
	roomId:number; 

	@IsString()
	@IsNotEmpty()
	key:string;

	@IsNumber()
	@IsNotEmpty()
	idPlayerMove:number; 
}

export class LeavingDto {
	@IsBoolean()
	@IsNotEmpty()
	waitingRoom:boolean;

	@IsString()
	@IsNotEmpty()
	modeGame:TypeGame;

	@IsNumber()
	@IsNotEmpty()
	roomId:number; 
}

export class giveMeARoomDto {
	@IsString()
	@IsNotEmpty()
	typeGame:TypeGame;
}