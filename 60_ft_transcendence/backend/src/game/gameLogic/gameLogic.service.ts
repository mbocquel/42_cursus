import { Injectable } from "@nestjs/common";
import { PrismaGameService } from "src/prisma/game/prisma.game.service";
import { Room } from "../Interface/room.interface";
import { Ball } from "../Interface/ball.interface";
import { Socket } from "socket.io";
import { IPlayer } from "../Interface/player.interface";
import { IgameParams } from "../Interface/gameParam.interface";
import { Iobstacles } from "../Interface/obstacle.interface";

export type colisionOb = 'NO' | 'HORIZONTALE_TOP' | 'HORIZONTALE_BTM' | 'VERTICALE_LEFT' | 'VERTICALE_RIGHT';

@Injectable()
export class GameLogicService {

	constructor(private prismaService: PrismaGameService){}

	colisionPaddle(playerPosY: number, ball:Ball, pong:IgameParams, sidePlayer:string):boolean {
		const ballTop:number = ball.pos.y - pong.ballRadius;
		const ballBtm:number = ball.pos.y + pong.ballRadius;
		const ballLeft:number = ball.pos.x - pong.ballRadius;
		const ballRight:number = ball.pos.x + pong.ballRadius;
	
		const paddleTop:number =  playerPosY - pong.paddleHeight/2;
		const paddleBtm:number = playerPosY + pong.paddleHeight/2;
		
		const paddleLeft:number = sidePlayer === 'left' ? 0 : 1 - pong.paddleWidth;
		const paddleRight:number = sidePlayer === 'left' ? pong.paddleWidth : 1;
	
		return (ballRight > paddleLeft && ballTop < paddleBtm && ballLeft < paddleRight && ballBtm > paddleTop)
	}

	colisionObstacle(obstacle: Iobstacles, ball: Ball): boolean {
		const obstacleTop:number =  obstacle.posy;
		const obstacleBtm:number = obstacle.posy + obstacle.height;
		const obstacleLeft:number = obstacle.posx;
		const obstacleRight:number = obstacle.posx + obstacle.width;
	
		return (ball.pos.x > obstacleLeft && ball.pos.y < obstacleBtm && ball.pos.x < obstacleRight && ball.pos.y > obstacleTop)
	}

	colisionObstacles(room: Room, ball:Ball): number {
		const col = room.obstacles.map((ob) => {
			return (this.colisionObstacle(ob, ball));
		})
		return(col.indexOf(true));
	}

	sideColisionObstacle(ballOldPos:{x:number, y:number}, obstacle: Iobstacles) : colisionOb[] {
		const obstacleTop:number =  obstacle.posy;
		const obstacleBtm:number = obstacle.posy + obstacle.height;
		const obstacleLeft:number = obstacle.posx;
		const obstacleRight:number = obstacle.posx + obstacle.width;

		if (ballOldPos.x <= obstacleLeft && ballOldPos.y <= obstacleTop) return ['VERTICALE_LEFT', 'HORIZONTALE_TOP'];
		if (ballOldPos.x > obstacleLeft && ballOldPos.x < obstacleRight && ballOldPos.y <= obstacleTop) return ['NO', 'HORIZONTALE_TOP'];
		if (ballOldPos.x >= obstacleRight && ballOldPos.y <= obstacleTop) return ['VERTICALE_RIGHT', 'HORIZONTALE_TOP'];
		if (ballOldPos.x <= obstacleLeft && ballOldPos.y > obstacleTop && ballOldPos.y < obstacleBtm) return ['VERTICALE_LEFT', 'NO'];
		if (ballOldPos.x >= obstacleRight && ballOldPos.y > obstacleTop && ballOldPos.y < obstacleBtm) return ['VERTICALE_RIGHT', 'NO'];
		if (ballOldPos.x <= obstacleLeft && ballOldPos.y >= obstacleBtm) return ['VERTICALE_LEFT', 'HORIZONTALE_BTM'];
		if (ballOldPos.x > obstacleLeft && ballOldPos.x < obstacleRight && ballOldPos.y >= obstacleBtm) return ['NO', 'HORIZONTALE_BTM'];
		if (ballOldPos.x >= obstacleRight && ballOldPos.y >= obstacleBtm) return ['VERTICALE_RIGHT', 'HORIZONTALE_BTM'];
		return ['NO', 'NO'] 
	}

	moveBalls(room:Room) : Room {
		room.balls = room.balls.map((ball) => {
			if(room.gameStatus !== 'PLAYING') return (ball);
			if (!ball.active){
				if (ball.startingCountDownStart === null) {
					ball.startingCountDownStart = new Date();
				}
				const newDate = new Date();
				const timePassed = (newDate.getTime() - ball.startingCountDownStart.getTime())/1000
				if (timePassed >= ball.startingCountDown) {
					ball.active = true;
				}
				return (ball);
			}
			const ballOldPos = {
				x: ball.pos.x,
				y: ball.pos.y
			};
			ball.pos.x += (ball.speed / Math.sqrt(ball.dir.x**2 + ball.dir.y**2)) * ball.dir.x;
			ball.pos.y += (ball.speed / Math.sqrt(ball.dir.x**2 + ball.dir.y**2)) * ball.dir.y;
	
			/*Top or bottom collision*/
			if (ball.pos.y > 1 - room.gameParam.ballRadius) {
				ball.pos.y = 1 - room.gameParam.ballRadius;
				ball.dir.y = - ball.dir.y;
			}
			else if (ball.pos.y < room.gameParam.ballRadius) {
				ball.pos.y = room.gameParam.ballRadius;
				ball.dir.y = - ball.dir.y;
			}
			/* Collision avec les obstacles */
			if (this.colisionObstacles(room, ball) !== -1) {
				const obstacle = room.obstacles[this.colisionObstacles(room, ball)];
				const sideCol = this.sideColisionObstacle(ballOldPos,obstacle);
				if (sideCol[0] === 'VERTICALE_RIGHT') {
					ball.dir.x = - ball.dir.x;
					ball.pos.x = obstacle.posx + obstacle.width;
				}
				else if (sideCol[0] === 'VERTICALE_LEFT') {
					ball.dir.x = - ball.dir.x;
					ball.pos.x = obstacle.posx;
				}
				if (sideCol[1] === 'HORIZONTALE_TOP') {
					ball.dir.y = - ball.dir.y;
					ball.pos.y = obstacle.posy;
				}
				else if (sideCol[1] === 'HORIZONTALE_BTM') {
					ball.dir.y = - ball.dir.y;
					ball.pos.y = obstacle.posy + obstacle.height;
				}
				obstacle.lives -= 1;
				if (obstacle.lives <= 0) {
					room.obstacles = room.obstacles.filter((ob) => {return ob != obstacle});
				}
			}

			/* Paddle colision*/
			let playerWithBallPosY = (ball.pos.x <= 1 / 2) ? room.playerLeft?.roomState.find((r) => r.room === room)?.posY! : room.playerRight?.roomState.find((r) => r.room === room)?.posY!;
			let sidePlayer:string = (ball.pos.x <= 1 / 2) ? 'left' : 'right';
			let direction = (ball.pos.x <= 1 / 2) ? 1 : -1;
			if (this.colisionPaddle(playerWithBallPosY, ball, room.gameParam, sidePlayer)) {
				let colisionY = (ball.pos.y - (playerWithBallPosY)) / (room.gameParam.paddleHeight / 3);
				let ang = colisionY * (Math.PI / 4);
				ball.dir.x = direction * Math.cos(ang);
				ball.dir.y = Math.sin(ang);
				ball.speed += room.gameParam.ballSpeedIncrease;
			}
			return (ball);
		});
		return (room);		
	}

	movePlayerOnEvent(param :{room: Room, key:string, idPlayerMove:number, client:Socket}) {
		let player:IPlayer | null;
		if (param.client !== param.room.playerLeft?.socket && param.client !== param.room.playerRight?.socket) return ;
		player = (param.client === param.room.playerLeft?.socket ? param.room.playerLeft : param.room.playerRight);
		if (!player) return ;
		let playerRoomParam = player.roomState.find((r) => r.room === param.room);
		if (typeof(playerRoomParam) === 'undefined') return;
		playerRoomParam.idPlayerMove = param.idPlayerMove;
		switch (param.key){
			case 'KeyW':
				playerRoomParam.posY = Math.max(param.room.gameParam.paddleHeight / 2, playerRoomParam.posY - param.room.gameParam.paddleSpeed);
				break;
			case 'KeyS':
				playerRoomParam.posY = Math.min(1 - param.room.gameParam.paddleHeight / 2,  playerRoomParam.posY + param.room.gameParam.paddleSpeed);
				break;
			case 'Space':
				playerRoomParam.readyToPlay = true;
				break;
			default:
				return; 
		}
	}

	updateRoomGameStatus(room:Room) : Room {
		if (room.gameStatus === 'FINISHED' || !room.playerLeft || !room.playerRight ) return (room);
		const playerLeftRoomStatus = room.playerLeft.roomState.find(r => r.room === room);
		const playerRightRoomStatus = room.playerRight.roomState.find(r => r.room === room);
		if (typeof(playerLeftRoomStatus) === 'undefined' || typeof(playerRightRoomStatus) ===  'undefined') return (room);
		if (room.gameStatus === 'WAITING_FOR_PLAYER' && room.playerLeft && room.playerRight ) {
			room.gameStatus = 'WAITING_TO_START';
		}
		else if (room.gameStatus === 'WAITING_TO_START' && playerLeftRoomStatus.readyToPlay && playerRightRoomStatus.readyToPlay) {
			room.gameStatus = 'STARTING';
		}
		else if (room.gameStatus === 'STARTING' && room.startingCount >= 3) {
			room.gameStatus = 'PLAYING';
			room.startingCount = 0;
			room.startingCountDownStart = null;
		}
		else if (room.gameStatus === 'STARTING') {
			if (room.startingCountDownStart === null) {
				room.startingCountDownStart = new Date();
			}
			const newDate = new Date();
			room.startingCount = (newDate.getTime() - room.startingCountDownStart.getTime()) / 1000;
		}
		return (room);
	}

	newBalls(nbBalls: number, room: Room) : Ball[] {
		const newId:number = nbBalls;
		const balls: Ball[] = [];
		let startingCountDown:number = 0;
		for (let i = 0; i< nbBalls; i++) {
			balls.push({
				id: i + 1, 
				pos: {x:room.gameParam.ballInitPosx,  y:room.gameParam.ballInitPosy},
				dir: {
					x: Math.random() > 0.5 ? (Math.random() * 0.8) + 0.2 : -((Math.random() * 0.8) + 0.2 ), 
					y: (Math.random() * 2) - 1
				},
				speed: room.gameParam.BallInitSpeed, 
				startingCountDownStart: null,
				startingCountDown: startingCountDown,
				active:false
			});
			startingCountDown += Math.random() * 5 + 1;
		}
		return (balls);
	}

	checkballsPositions(room: Room) : Room {
		let ballsOut = room.balls.filter((ball) => {return ((ball.pos.x > 1 || ball.pos.x < 0))});
		if (ballsOut.length === 0) return (room);
		ballsOut.forEach((ball) => {
			let sidePlayer:string = (ball.pos.x <= 1 / 2) ? 'left' : 'right';
			sidePlayer === 'left' ? room.scoreRight++ : room.scoreLeft++;
		});
		if (room.scoreRight >= room.gameParam.goal || room.scoreLeft >= room.gameParam.goal) {
			room.gameStatus = 'FINISHED';
			this.prismaService.finishGame(room, null);
		}
		room.balls = room.balls.map((ball)=> {
			if (!(ball.pos.x > 1 || ball.pos.x < 0)) return (ball);
			else {
				ball.pos = {x:room.gameParam.ballInitPosx,  y:room.gameParam.ballInitPosy};
				ball.dir = {
					x: Math.random() > 0.5 ? (Math.random() * 0.8) + 0.2 : -((Math.random() * 0.8) + 0.2 ), 
					y: (Math.random() * 2) - 1
				};
				ball.speed = room.gameParam.BallInitSpeed;
				return ball;
			}
		})
		return (room);
	}

	playGameLoop(rooms : Room[]) : Room[] {
		const newRooms: Room[] = rooms.map((room) => {
			room = this.updateRoomGameStatus(room);
			room = this.moveBalls(room);
			room = this.checkballsPositions(room);
			return (room);
		});
		return (newRooms);
	}
}