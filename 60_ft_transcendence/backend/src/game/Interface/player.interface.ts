import { Socket } from "socket.io";
import { Room } from "./room.interface";

export interface IRoomState {
	room:Room;
	posY:number;
	readyToPlay:boolean;
	idPlayerMove:number;
}

export interface IPlayer {
	name:string;
	socket: Socket;
	roomState: IRoomState[];
	idBdd:number;
}