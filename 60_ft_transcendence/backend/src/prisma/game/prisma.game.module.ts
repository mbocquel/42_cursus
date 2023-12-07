import { Global, Module } from '@nestjs/common';
import { PrismaGameService } from './prisma.game.service';

@Global()
@Module({
  providers: [PrismaGameService],
  exports: [PrismaGameService],
})
export class PrismaGameModule {}
