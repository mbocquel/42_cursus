import { Module } from '@nestjs/common';
import { PrismaGameService } from 'src/prisma/game/prisma.game.service';
import { GameLogicService } from './gameLogic.service';

@Module({
	providers: [PrismaGameService, GameLogicService],
	exports: [GameLogicService]
})
export class GameLogicModule {
	constructor(private roomsService:GameLogicService) {}
}
