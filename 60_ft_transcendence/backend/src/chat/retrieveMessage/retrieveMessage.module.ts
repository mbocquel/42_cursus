import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { RetrieveMessageService } from "./retrieveMessage.service";
import { ChatModule } from "../chat.module";

@Module({
	imports: [ChatModule],
	providers: [RetrieveMessageService],
	exports: [RetrieveMessageService],
})

export class RetrieveMessageModule {}
