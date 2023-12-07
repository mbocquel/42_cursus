import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { JoinChatService } from "./joinChat.service";
import { ChatModule } from "../chat.module";

@Module({
	imports: [ChatModule],
	providers: [JoinChatService],
	exports: [JoinChatService],
})

export class JoinChatModule{}

