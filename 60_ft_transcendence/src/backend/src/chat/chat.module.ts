import { Module } from '@nestjs/common';
import { JoinChatService } from './joinChat/joinChat.service';
import { MyGateway } from './gateway/gateway.service';
import {GatewayModule} from './gateway/gateway.module'
import { RetrieveMessageService } from './retrieveMessage/retrieveMessage.service';
import { MutedUserService } from './mutedUser/mutedUser.service';
import { ChatOptModule } from './chatOption/chatOption.module'
import { MutedUserModule } from './mutedUser/mutedUser.module';

@Module({
  imports:[GatewayModule, ChatOptModule],
  providers: [],
  exports: [],
})
export class ChatModule {}
