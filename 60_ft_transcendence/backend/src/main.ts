import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import * as fs from 'fs';
import { CorsOptions } from '@nestjs/common/interfaces/external/cors-options.interface';
import { PrismaChatService } from './prisma/chat/prisma.chat.service';
import { ValidationPipe } from '@nestjs/common';


async function bootstrap() {

  // const httpsOptions = {
  //   key: fs.readFileSync('/etc/ssl/pong-selfsigned.key'),
  //   cert: fs.readFileSync('/etc/ssl/pong-selfsigned.crt'),
  // };
  const app = await NestFactory.create(AppModule);

  // Define your CORS options here
 /*  const corsOptions: CorsOptions = {
    origin: 'http://${process.env.REACT_APP_URL_MACHINE}:3000', // Replace with your React app's URL
    methods: 'GET,HEAD,PUT,PATCH,POST,DELETE',
    credentials: true, // If you need to handle cookies or authentication
  }; */
  // Enable CORS using the provided options

  app.enableCors();
  app.useGlobalPipes(new ValidationPipe(
    {whitelist: true,}
  ));

  await app.listen(4000);
}
bootstrap();
