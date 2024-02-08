import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { ChatLister } from "./chatLister.service";
import { ChatModule } from "../chat.module";

@Module({
	imports: [ChatModule],
	providers: [ChatLister],
	exports: [ChatLister],
})

export class ChatListerModule{}
