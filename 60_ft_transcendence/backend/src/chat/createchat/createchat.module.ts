import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { CreateChatService } from "./createchat.service";
import { ChatModule } from "../chat.module";

@Module({
	imports: [],
	providers: [CreateChatService],
	exports: [CreateChatService],
})

export class CreateChatModule{}

