import {
  ForbiddenException,
  ImATeapotException,
  Injectable,
} from "@nestjs/common";
import { JwtService } from "@nestjs/jwt";
import { ConfigService } from "@nestjs/config";
import { LoginDto } from "../user/dto";
import { PrismaUserService } from "src/prisma/user/prisma.user.service";
import { FtUser } from "src/ft_auth/dto/FtUser.dto";

@Injectable()
export class AuthService {
  constructor(
    private jwt: JwtService,
    private config: ConfigService,
    private prismaUser: PrismaUserService
  ) {}

  // async login(dto: LoginDto) {
  //   let user = await this.prismaUser.getUserByLogin(dto.login);
  //   const logo: FtUser = {
  //     login: dto.login,
  //     username: dto.login,
  //     email: dto.login + "@student.42.fr",
  //   };
  //   if (!user) {
  //     user = await this.prismaUser.createUser(logo);
  //   }
  //   if (!user) {
  //     throw new ImATeapotException("For real: I'm a Teapot");
  //   }
  //   return this.signToken(user.login);
  // }

  // async signToken(
  //   login: string
  // ): Promise<{ login: string; access_token: string }> {
  //   const payload = {
  //     sub: login,
  //   };
  //   const access_token = await this.jwt.signAsync(payload, {
  //     expiresIn: "59m",
  //     secret: this.config.get("JWT_SECRET"),
  //   });
  //   return { login, access_token };
  // }
}
