import { Global, Module } from '@nestjs/common';
import { PrismaChatService } from './prisma.chat.service';

@Global()
@Module({
  providers: [PrismaChatService],
  exports: [PrismaChatService],
})
export class PrismaChatModule {}
