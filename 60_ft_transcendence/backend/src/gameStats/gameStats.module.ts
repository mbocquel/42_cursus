import { Module } from '@nestjs/common';
import { gameStatsControler } from './gameStats.controller';
import { PrismaModule } from 'src/prisma/prisma.module';
import { GameStatsService } from './gameStats.service';
@Module({
  imports:[PrismaModule],
  controllers: [gameStatsControler],
  providers: [GameStatsService],
})
export class GameStatsModule {}