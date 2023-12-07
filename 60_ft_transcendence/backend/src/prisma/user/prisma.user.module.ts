import { Global, Module } from '@nestjs/common';
import { PrismaUserService } from '../user/prisma.user.service';

@Global()
@Module({
    imports : [],
  providers: [PrismaUserService],
  exports: [PrismaUserService],
})
export class PrismaUserModule {}
