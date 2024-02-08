import { GatewayModule } from "../gateway/gateway.module";
import { Module } from "@nestjs/common";
import { PrivateConvService } from "./privateConv.service";
import { ChatModule } from "../chat.module";

@Module({
	imports: [],
	providers: [PrivateConvService],
	exports: [PrivateConvService],
})

export class PrivateConvModule {}
