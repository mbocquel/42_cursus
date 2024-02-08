import { Module } from "@nestjs/common";
import { JwtModule } from "@nestjs/jwt";
import { FtAuthController } from "./ft_auth.controller";
import { FtAuthService } from "./ft_auth.service";
import { PrismaModule } from "src/prisma/prisma.module";
import { FortytwoStrategy } from "./ft_auth.strategy";
import { HttpModule } from "@nestjs/axios";
import { TwoFAModule } from "src/twoFA/twoFA.module";
import { TwoFAService } from "src/twoFA/twoFA.service";

@Module({
  imports: [JwtModule.register({}), PrismaModule, HttpModule, TwoFAModule],
  controllers: [FtAuthController],
  providers: [TwoFAService,FtAuthService, FortytwoStrategy],
})
export class FtAuthModule {}
