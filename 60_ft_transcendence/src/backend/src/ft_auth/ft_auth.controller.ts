import {
  Controller,
  Get,
  UseGuards,
  Req,
  Res,
  Body,
  Post,
} from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
import { FtAuthService } from './ft_auth.service';
import { Request, Response } from 'express';
import { TfaToken } from './dto/TfaToken.dto';

@Controller('ft_auth')
export class FtAuthController {
  constructor(private ftAuthService: FtAuthService) {}

  @UseGuards(AuthGuard('oauth2'))
  @Get('login')
  login(@Req() req: Request) {}

  @UseGuards(AuthGuard('oauth2'))
  @Get('callback')
  ftAuthRedirect(@Req() req: Request, @Res() res: Response) {
   return this.ftAuthService.loginCb(req, res);
  }

  @Post('token')
  ftAuthToken(@Body('key') key:string){
    return this.ftAuthService.provideTokenByKey(key);
  }

  @Post('tfatoken')
  ftAuthTfaToken(@Body() tfa_token: TfaToken){
    return this.ftAuthService.provideTokenByKeyAndTfa(tfa_token);
  }
}
