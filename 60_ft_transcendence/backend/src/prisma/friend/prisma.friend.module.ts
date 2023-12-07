import { Global, Module } from '@nestjs/common';
import { PrismaFriendService } from './prisma.friend.service';

@Global()
@Module({
  providers: [PrismaFriendService],
  exports: [PrismaFriendService],
})
export class PrismaFriendModule {}
