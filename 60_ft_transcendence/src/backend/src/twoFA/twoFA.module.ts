import { Module } from '@nestjs/common';
import { TwoFAController } from './twoFA.controller';
import { TwoFAService } from './twoFA.service';
import { PrismaModule } from 'src/prisma/prisma.module';
import { TwoFAStrategy } from './twoFA.strategy';
import { HttpModule } from '@nestjs/axios';

@Module({
  imports: [ PrismaModule, HttpModule],
  controllers: [TwoFAController],
  providers: [TwoFAService, TwoFAStrategy]
})
export class TwoFAModule {}