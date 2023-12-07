import { Injectable } from '@nestjs/common';
import { PassportStrategy } from '@nestjs/passport';
import { Strategy } from 'passport-oauth2';
import { ConfigService } from '@nestjs/config';
import { FtAuthService } from './ft_auth.service';

@Injectable()
export class FortytwoStrategy extends PassportStrategy(
  Strategy,
  'oauth2',
) {
  constructor(private config: ConfigService, private ftAuthService: FtAuthService) {
    super(
      {
        authorizationURL: config.get('FORTYTWO_AUTHOR_URL'),
        tokenURL: config.get('FORTYTWO_TOKEN_URL'),
        clientID: config.get('FORTYTWO_CLIENTID'),
        clientSecret: config.get('FORTYTWO_CLIENTSECRET'),
        callbackURL: config.get('FORTYTWO_CALLBACK_URL'),
        scope: 'public',
      },
      async function (
        accessToken: string,
        refreshToken: string,
        profile: any,
        cb: any,
      ) {
        return await ftAuthService.fetchUser(accessToken, cb);
      },
    );
  }
}
