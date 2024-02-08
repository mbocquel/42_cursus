import { Injectable } from '@nestjs/common';
import { Room, TypeGame} from '../Interface/room.interface';
import { IPlayer } from '../Interface/player.interface';
import { Socket } from 'socket.io';
import { PrismaGameService } from 'src/prisma/game/prisma.game.service';
import { GameLogicService } from '../gameLogic/gameLogic.service';
import { OnModuleInit } from '@nestjs/common';
import { gameMaps } from '../DefaultData/gameMaps';
import { gameParams } from '../DefaultData/gameParams';

@Injectable()
export class RoomsService  implements OnModuleInit{
	constructor(private prismaService: PrismaGameService, private gameLogicService: GameLogicService){}

	private rooms: Room[] = [];
	private roomMaxId:number = 1;
	private waitingRoomBasic: IPlayer[] = [];
	private waitingRoomAdvanced: IPlayer[] = [];

	async onModuleInit() {}

	displayInfo() {
		console.log("-------------------------------------------------");
		console.log("-------------     DISPLAY INFO     --------------");
		console.log("-------------------------------------------------");
		console.log("gameParams : ", gameParams);
		console.log("gameMaps : ", gameMaps);
		console.log("Rooms : ", this.rooms);
		console.log("Waiting Room ADVANCED :", this.waitingRoomAdvanced);
		console.log("Waiting Room BASIC :", this.waitingRoomBasic);
	}

	async createRoom(playerLeft:IPlayer, playerRight:IPlayer, typeGame:TypeGame) {
		const room = this.createEmptyRoom(typeGame);
		if (!room) return null;
		room.gameStatus = 'WAITING_TO_START';
		room.playerLeft = playerLeft;
		room.playerRight = playerRight;
		playerLeft.roomState.push(
			{
				room:room,
				posY:0.5,
				readyToPlay:false,
				idPlayerMove:-1,
			}
		)
		playerRight.roomState.push(
			{
				room:room,
				posY:0.5,
				readyToPlay:false,
				idPlayerMove:-1,
			}
		)
		await this.addNewBddGame(room);
		room.playerLeft.socket.emit('room_joined', {roomId: room.id, gameStatus:room.gameStatus });
		room.playerRight.socket.emit('room_joined', {roomId: room.id, gameStatus:room.gameStatus});
		return (room);
	};

	createEmptyRoom(typeGame:TypeGame) : Room | null {
		const gameParam = gameParams.find((gp) => {return (gp.type === typeGame)});
		if (typeof(gameParam) === 'undefined')  {
			return null
		};
		const newRoom: Room = {
			id:this.roomMaxId,
			balls: [],
			obstacles: [],
			ballHasLeft: false,
			playerLeft:null,
			playerRight:null,
			scoreLeft:0,
			scoreRight:0,
			gameStatus:'WAITING_FOR_PLAYER',
			createdOn: new Date(),
			finishOn: null,
			startingCountDownStart: null,
			startingCount: 0,
			bddGameId:0,
			typeGame:typeGame,
			gameParam: gameParam
		}
		this.roomMaxId++;
		if (newRoom.typeGame === 'ADVANCED' && gameMaps.length) {
			const map = gameMaps[Math.floor(Math.random() * gameMaps.length)];
			newRoom.obstacles = map.obstacles;
			newRoom.balls = this.gameLogicService.newBalls(map.nbBalls, newRoom);
		}
		else {
			newRoom.balls = this.gameLogicService.newBalls(1, newRoom);
		}
		this.rooms.push(newRoom);
		return (newRoom);
	};

	async joinWaitingRoom(player:IPlayer, typeGame:TypeGame) {
		const waitingPlayers = (typeGame === 'ADVANCED' ? this.waitingRoomAdvanced.filter((p) => {return (p.idBdd !== player.idBdd)}) : this.waitingRoomBasic.filter((p) => {return (p.idBdd !== player.idBdd)}));
		if (waitingPlayers.length === 0) {
			if (typeGame === 'ADVANCED') {
				this.waitingRoomAdvanced.push(player);
			}
			else {
				this.waitingRoomBasic.push(player);
			}
			player.socket.emit('waiting_room_joined');
		}
		else {
			const playerToRemoveFromWaitingRoom = waitingPlayers[0];
			await this.createRoom(playerToRemoveFromWaitingRoom, player, typeGame);
			if (typeGame === 'ADVANCED') {
				this.waitingRoomAdvanced = this.waitingRoomAdvanced.filter(p => {return (p !== playerToRemoveFromWaitingRoom)});
			}
			else {
				this.waitingRoomBasic = this.waitingRoomBasic.filter(p => {return (p !== playerToRemoveFromWaitingRoom)});
			}
		}
	}

	removePlayerFromWaitingRooms(player:IPlayer) {
		this.waitingRoomAdvanced = this.waitingRoomAdvanced.filter((waitingPlayer) => {return (waitingPlayer !== player)});
		this.waitingRoomBasic = this.waitingRoomBasic.filter((waitingPlayer) => {return (waitingPlayer !== player)});
	}

	removePlayerFromBasicWaitingRoom(player:IPlayer) {
		this.waitingRoomBasic = this.waitingRoomBasic.filter((waitingPlayer) => {return (waitingPlayer !== player)});
	}

	removePlayerFromAdvancedWaitingRoom(player:IPlayer) {
		this.waitingRoomAdvanced = this.waitingRoomAdvanced.filter((waitingPlayer) => {return (waitingPlayer !== player)});
	}

	removeRoom(room: Room) {
		this.rooms = this.rooms.filter((r) => {return r !== room;});
	};

	getAllRoom(): Room[] {
		return this.rooms;
	};

	findRoomsOfPlayer(player: IPlayer | null): Room[] | null {
		if (!player) return null;
		const room = this.rooms.filter((element) => {return(element.playerLeft === player || element.playerRight === player)});
		if (room.length === 0) {
			return null;
		}
		return room;
	};

	findRoomOfPlayerBySocket(socket: Socket): Room | null {
		const room = this.rooms.find((element) => (element.playerLeft?.socket === socket || element.playerRight?.socket === socket));
		if (typeof(room) === 'undefined') {
			return null;
		}
		return room;
	};

	findRoomById(idToFind:number) : Room | null {
		const room = this.rooms.find(element => element.id === idToFind);
		if (typeof(room) === 'undefined') {
			return null;
		}
		return room;
	};

	async addPlayerToRoom(player:IPlayer, roomId:number) {
		let room = this.findRoomById(roomId);
		if (room === null) {
			player.socket.emit('error_join', {roomId: roomId, errorMsg: 'The room does not exist'});
			return;
		}
		if (room.playerLeft === player || room.playerRight === player) {
			player.socket.emit('error_join', {roomId: room.id, errorMsg: 'Player already in room'});
			return;
		}
		if (room.playerLeft != null  && room.playerRight != null) {
			player.socket.emit('error_join', {roomId: room.id, errorMsg: 'The Room is full'});
			return;
		}
		if (room.playerLeft === null) {
			room.playerLeft = player;
		}
		else {
			room.playerRight = player;
		}
		player.roomState.push(
			{
				room:room,
				posY:0.5,
				readyToPlay:false,
				idPlayerMove:-1,
			}
		)
		if (room.playerRight && room.playerLeft) {
			room.gameStatus = 'WAITING_TO_START';
			await this.addNewBddGame(room);
		}
		player.socket.emit('room_joined', {roomId: room.id});
	};

	async addNewBddGame(room:Room) {
		const roomToUpdate = room;
		const bddGame = await this.prismaService.addNewGame(room).then(
			(bddGame) => {
				if (bddGame) {
					roomToUpdate.bddGameId = bddGame.id;
				}
			}
		);
	}

	getNumberOfPlayersInRoom(room:Room):number {
		if (room.playerLeft === null && room.playerRight === null) return 0;
		if (room.playerLeft === null || room.playerRight === null) return 1;
		return 2;
	};

	getSideOfPlayer(room:Room, player:IPlayer):string {
		if (player === room.playerLeft) return 'left';
		if (player === room.playerRight) return 'right';
		else return 'none';
	};

	async removePlayerFromRoom(player:IPlayer, roomId:number) {
		let room = this.findRoomById(roomId);
		if (room === null || (room.playerLeft !== player && room.playerRight !== player)) return ;
		if (this.getNumberOfPlayersInRoom(room) != 2){
			this.removeRoom(room);
		}
		if (room.gameStatus !== 'FINISHED') {
			room.gameStatus = 'FINISH_BY_FORFAIT';
			this.prismaService.finishGame(room, player);
			room.playerLeft = (room.playerLeft === player ? null : room.playerLeft);
			room.playerRight = (room.playerRight === player ? null : room.playerRight)
		}
		this.sendRoomStatus(room);
	};

	sendRoomStatus(room: Room) {
		const data_to_send = {
			idRoom:room.id,
			gameParam: {
				ballRadius: room.gameParam.ballRadius,
				paddleWidth: room.gameParam.paddleWidth,
				paddleHeight: room.gameParam.paddleHeight,
				paddleSpeed: room.gameParam.paddleSpeed,
				goal: room.gameParam.goal,
			},
			playerLeft:{
				name:room.playerLeft?.name,
				socketId: room.playerLeft?.socket.id,
			},
			playerRight:{
				name:room.playerRight?.name,
				socketId: room.playerRight?.socket.id,
			},
			balls:room.balls,
			obstacles:room.obstacles,
			gameStatus:room.gameStatus
		};
		room.playerLeft?.socket.emit('room_status', data_to_send);
		room.playerRight?.socket.emit('room_status', data_to_send);
	}

	broadcastGameState() {
		this.rooms.forEach(room => {
			const data = {
				roomId:room.id,
				balls:room.balls,
				obstacles:room.obstacles,
				playerLeft:{
					name:room.playerLeft?.name,
					posY:room.playerLeft?.roomState.find((r) => r.room === room)?.posY,
					socket_id: room.playerLeft?.socket.id,
					readyToPlay:room.playerLeft?.roomState.find((r) => r.room === room)?.readyToPlay,
					idPlayerMove:room.playerLeft?.roomState.find((r) => r.room === room)?.idPlayerMove
				},
				playerRight:{
					name:room.playerRight?.name,
					posY:room.playerRight?.roomState.find((r) => r.room === room)?.posY,
					socket_id: room.playerRight?.socket.id,
					readyToPlay:room.playerRight?.roomState.find((r) => r.room === room)?.readyToPlay,
					idPlayerMove:room.playerRight?.roomState.find((r) => r.room === room)?.idPlayerMove
				},
				scoreLeft:room.scoreLeft,
				scoreRight:room.scoreRight,
				gameStatus:room.gameStatus,
				startingCount: room.startingCount
			};
			room.playerLeft?.socket.emit('game_state', data);
			room.playerRight?.socket.emit('game_state', data);
		});
		//Remove room that are finished from the array of roomService of players
		this.rooms.forEach((room)=> {
			if (!(room.gameStatus === 'FINISHED' || room.gameStatus === 'FINISH_BY_FORFAIT')) return;
			if (room.playerLeft) {
				room.playerLeft.roomState = room.playerLeft.roomState.filter((roomState) => {return (roomState.room !== room)});
			}
			if (room.playerRight) {
				room.playerRight.roomState = room.playerRight.roomState.filter((roomState) => {return (roomState.room !== room)});
			}
		});
		this.rooms = this.rooms.filter((room) => { return !(room.gameStatus === 'FINISHED' || room.gameStatus === 'FINISH_BY_FORFAIT')});
	}

	playGameLoop() {
		const newRooms: Room[] = this.rooms.map((room) => {
			room = this.gameLogicService.updateRoomGameStatus(room);
			room = this.gameLogicService.moveBalls(room);
			room = this.gameLogicService.checkballsPositions(room);
			return (room);
		});
		this.rooms = newRooms;
	}

	handlePlayerKeyEvent(data:{roomId: number, key:string, idPlayerMove:number, client:Socket}){
		const room = this.findRoomById(data.roomId)
		if (room) {
			this.gameLogicService.movePlayerOnEvent({room, key:data.key, idPlayerMove:data.idPlayerMove, client:data.client});
		}
	}
}
