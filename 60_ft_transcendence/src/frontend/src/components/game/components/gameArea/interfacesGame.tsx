import { GameStatus } from "../../../../context/gameContext";

export interface IPoint {
	x:number;
    y:number;
};

export interface IBall {
	id: number;
	pos: IPoint;
	speed: number;
	dir: IPoint;
	startingCountDownStart: Date | null;
	startingCountDown: number;
	active:boolean;
};

export interface IObstacles {
	id: number;
    posx: number;
    posy: number;
    width: number;
    height: number;
    img: string | null;
    lives: number;
    gameMapsId: number | null;
}

export interface IGameParam {
    ballRadius: number;
    paddleWidth: number;
    paddleHeight: number;
    netWidth:number;
    netHeight:number;
    netInterval:number;
    backColor: string;
    ballColor: string;
    netColor: string;
    scoreFont:string;
    scoreFontPx:number;
    scoreFontDecoration:string;
    scoreColor: string;
    nameFont:string;
    nameFontDecoration:string;
    nameFontPx:number;
    nameColor:string;
    ballInitSpeed: number;
    ballInitDir: IPoint;
    ballSpeedIncrease: number;
    paddleSpeed:number;
    menuBackColor:string;
    menuTextColor:string;
    menuFont:string;
    menuFontDecoration:string;
    menuFontPx:number;
    play:boolean;
    goal:number;
    endgame:boolean;
	startingCount : number;
};

export interface IPlayer {
	posY: number;
    score: number;
    scorePos: IPoint;
    upArrowDown:boolean;
    downArrowDown:boolean;
    name:string;
    namePos: IPoint;
    color:string;
	socketId: string;
	readyToPlay:boolean;
};
