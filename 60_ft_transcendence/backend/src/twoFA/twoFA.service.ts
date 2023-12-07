import { BadRequestException, Injectable } from "@nestjs/common";
import * as speakeasy from "speakeasy";
import * as qrcode from "qrcode";
import { PrismaUserService } from "src/prisma/user/prisma.user.service";
import { User } from "@prisma/client";

@Injectable()
export class TwoFAService {
  constructor(private prisma: PrismaUserService) {}

  async setup(login: string) {
    const secret = speakeasy.generateSecret({ name: `PongOffice ${login}` });
    const user = await this.prisma.setTfaSecret({
      login,
      secret: secret.ascii,
    });
    if (secret.otpauth_url) {
      const qrcode_url = await qrcode.toDataURL(secret.otpauth_url);
      return { qrcode_url };
    }
  }

  async validate(login: string, token: string) {
    let verified = false;
    let user = await this.prisma.getUserByLogin(login);
    if (user && user.tfa_secret) {
      verified = speakeasy.totp.verify({
        secret: user.tfa_secret,
        encoding: "ascii",
        token,
      });
    }
    user = await this.prisma.setTfaActivated({ login, verified });
    user.tfa_secret = "nope";
    return user;
  }

  async authenticate(login: string, token: string) {
    let verified = false;
    let user = await this.prisma.getUserByLogin(login);
    if (user && user.tfa_secret) {
      verified = speakeasy.totp.verify({
        secret: user.tfa_secret,
        encoding: "ascii",
        token,
      });
    }
    return verified;
  }

  async cancel(login: string) {
    const verified = false;
    let user = await this.prisma.getUserByLogin(login);
    if (user) {
      user = await this.prisma.setTfaActivated({ login, verified });
      user.tfa_secret = "nope";
    }
    return user;
  }
}
