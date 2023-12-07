import { Module } from "@nestjs/common";
import { ConfigModule } from "@nestjs/config";
import { ChatModule } from "./chat/chat.module";
import { AuthModule } from "./auth/auth.module";
import { UserModule } from "./user/user.module";
import { PrismaModule } from "./prisma/prisma.module";
import { AppService } from "./app.service";
import { AppController } from "./app.controller";
import { FtAuthModule } from "./ft_auth/ft_auth.module";
import { MutedUserModule } from "./chat/mutedUser/mutedUser.module";
import { GameSocketModule } from "./game/gameSocket.module";
import { PlayersModule } from "./game/players/players.module";
import { RoomsModule } from "./game/rooms/rooms.module";
import { GameLogicModule } from "./game/gameLogic/gameLogic.module";
import { FriendModule } from "./friend/friend.module";
import { GameStatsModule } from "./gameStats/gameStats.module";

@Module({
  imports: [
    ConfigModule.forRoot({
      isGlobal: true,
    }),
    AuthModule,
    FtAuthModule,
    UserModule,
    PrismaModule,
    ChatModule,
    MutedUserModule,
    GameSocketModule,
    PlayersModule,
    RoomsModule,
    GameLogicModule,
    FriendModule,
    GameStatsModule,
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
