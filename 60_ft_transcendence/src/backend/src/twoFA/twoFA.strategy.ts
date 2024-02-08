import { Injectable } from "@nestjs/common";
import { PassportStrategy } from "@nestjs/passport";
import { Strategy } from "passport";
import { ConfigService } from "@nestjs/config";
import { PrismaUserService } from "src/prisma/user/prisma.user.service";

@Injectable()
export class TwoFAStrategy extends PassportStrategy(Strategy, "twofa") {
  constructor(
    private config: ConfigService,
    private prisma: PrismaUserService
  ) {
    super({});
  }
  async validate() {}
}
