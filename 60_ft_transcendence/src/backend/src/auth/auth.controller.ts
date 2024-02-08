import { Body, Controller, Post } from "@nestjs/common";
import { AuthService } from "./auth.service";
import { LoginDto } from "../user/dto";

@Controller("auth")
export class AuthController {
  constructor(private authService: AuthService) {}

  // @Post("login")
  // login(@Body() dto: LoginDto) {
  //   return this.authService.login(dto);
  // }
}
