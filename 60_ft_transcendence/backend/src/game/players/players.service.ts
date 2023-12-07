import { Injectable } from '@nestjs/common';
import { IPlayer } from '../Interface/player.interface';
import { Socket } from 'socket.io';

@Injectable()
export class PlayersService {

	private players: IPlayer[] = [];

	create(player: IPlayer) {
		this.players.push(player);
	};

	remove(clientSocket: Socket) {
		this.players = this.players.filter((p) => {return p.socket !== clientSocket;});
	};

	findAll(): IPlayer[] {
		return this.players;
	};

	findOne(socket: Socket): IPlayer | null {
		const player = this.players.find((element) => element.socket === socket);
		if (typeof(player) === 'undefined') {
			return null;
		}
		return player
	};

	consoleLogPlayers() {
		console.log("Players : ",this.players);
	}	
}
