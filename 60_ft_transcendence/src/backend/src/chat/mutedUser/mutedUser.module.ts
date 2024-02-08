import { GatewayModule } from "../gateway/gateway.module";
import { Module, Global } from "@nestjs/common";
import { MutedUserService } from "./mutedUser.service";
import { ChatModule } from "../chat.module";

@Global()
@Module({
	imports: [],
	providers: [MutedUserService],
	exports: [MutedUserService],
})

export class MutedUserModule{}

