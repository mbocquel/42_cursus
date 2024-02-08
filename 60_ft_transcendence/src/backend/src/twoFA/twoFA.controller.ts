import { Controller, Get, UseGuards, Body, Post } from "@nestjs/common";
import { AuthGuard } from "@nestjs/passport";
import { TwoFAService } from "./twoFA.service";
import { twoFADto } from "./dto/twoFA.dto";
import { GetUser } from "src/auth/decorator";

@UseGuards(AuthGuard("jwt"))
@Controller("twofa")
export class TwoFAController {
  constructor(private twofaService: TwoFAService) {}

  @Get("setup")
  setup(@GetUser("login") login: string) {
    const qr_url = this.twofaService.setup(login);
    return qr_url;
  }

  @Post("validate")
  validate(@GetUser("login") login: string, @Body() dto: twoFADto) {
    const user = this.twofaService.validate(login, dto.token);
    return user;
  }

  @Get("cancel")
  cancel(@GetUser("login") login: string) {
    const user = this.twofaService.cancel(login);
    return user;
  }
}
