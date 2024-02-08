import { Module } from "@nestjs/common";
import { MyGateway } from "./gateway.service";
import { JoinChatModule } from "../joinChat/joinChat.module";
import { forwardRef } from "@nestjs/common";
import { ChatModule } from "../chat.module";
import { MutedUserService } from "../mutedUser/mutedUser.service";
import { MutedUserModule } from "../mutedUser/mutedUser.module";
import { ChatOptModule } from "../chatOption/chatOption.module";
import { ChatOptController } from "../chatOption/chatOption.controller";
import { PrivateConvModule } from "../privateConv/privateConv.module"

@Module({
	imports : [PrivateConvModule],
	providers: [MyGateway],
	exports: [MyGateway],
})
export class GatewayModule{}
