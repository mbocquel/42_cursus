import { Module } from '@nestjs/common';
import { RoomsService } from './rooms.service';
import { PrismaGameService } from 'src/prisma/game/prisma.game.service';
import { GameLogicService } from '../gameLogic/gameLogic.service';

@Module({
	providers: [RoomsService, PrismaGameService, GameLogicService],
	exports: [RoomsService]
})
export class RoomsModule {
	constructor(private roomsService:RoomsService) {}
}
