import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { ChatOptController } from "./chatOption.controller";
import { JoinChatService } from "../joinChat/joinChat.service";
import { PrivateConvModule } from "../privateConv/privateConv.module";
import { CreateChatService } from "../createchat/createchat.service";
import { CreateChatModule } from "../createchat/createchat.module";


@Module({
	imports:[GatewayModule,PrivateConvModule, CreateChatModule],
	controllers: [ChatOptController],
	providers: [JoinChatService]
})

export class ChatOptModule{}
