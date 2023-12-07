import { Module } from '@nestjs/common';
import { GatewayModule } from 'src/chat/gateway/gateway.module';
import { addFriendController } from './friend.controller';

@Module({
  imports:[GatewayModule],
  controllers: [addFriendController],
  providers: [],
  exports: [],
})
export class FriendModule {}
