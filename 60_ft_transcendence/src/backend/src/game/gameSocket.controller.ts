import { Body, Controller, Post, Get, Param } from "@nestjs/common";
import { JwtGuard } from '../auth/guard';
import { UseGuards } from "@nestjs/common";
import { RoomsService } from "./rooms/rooms.service";
import { PlayersService } from "./players/players.service";
import { giveMeARoomDto } from "./dto/game.dto";

@UseGuards(JwtGuard)
@Controller('game')
export class gameSocketControler {
	constructor(private roomsService: RoomsService, private playerService: PlayersService){}

	@Post('newRoom')
	giveMeARoom(@Body() data:giveMeARoomDto)
	{		
		const newRoomId = this.roomsService.createEmptyRoom(data.typeGame);
		const responseData = {
			roomId:newRoomId?.id
		}
		return (responseData);
	}
	
	@Get()
	print_state() {
		this.roomsService.displayInfo();
		this.playerService.consoleLogPlayers();
	}
}
