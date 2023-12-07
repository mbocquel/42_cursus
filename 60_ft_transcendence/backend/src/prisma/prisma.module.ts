import { Global, Module } from '@nestjs/common';
import { PrismaService } from './prisma.service';
import { PrismaChatModule } from './chat/prisma.chat.module';
import { PrismaFriendModule } from './friend/prisma.friend.module';
import { PrismaGameModule } from './game/prisma.game.module';
import { PrismaUserModule } from './user/prisma.user.module';

@Global()
@Module({
	imports: [PrismaChatModule, PrismaFriendModule, PrismaGameModule, PrismaUserModule],
	providers: [PrismaService]
})
export class PrismaModule {}
