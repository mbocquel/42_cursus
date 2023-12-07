import React from 'react';

export type GameStatus = 'NOT_IN_GAME' | 'IN_WAITING_ROOM' | 'WAITING_FOR_PLAYER' | 'WAITING_TO_START' | 'STARTING' | 'PLAYING' | 'FINISHED' | 'FINISH_BY_FORFAIT' | 'OPPONENT_LEFT_ROOM';

export interface IGameContextProps {
	roomId:number;
	setRoomId: (roomId:number) => void;
	gameWidth:number;
	setGameWidth: (gameWidth:number) => void;
	gameHeight:number;
	setGameHeight: (gameHeight:number) => void;
	playerName:string;
	setPlayerName: (playerName:string) => void;
	modeGame: string;
	setModeGame: (modeGame:string) => void;
	gameStatus: GameStatus;
	setGameStatus:  (gameStatus: GameStatus) => void;
	matchMe: boolean;
	setMatchMe: (matchMe: boolean) => void;
};

const defaultState:IGameContextProps = {
	roomId: 0,
	setRoomId: () => {},
	gameWidth:800,
	setGameWidth:() => {},
	gameHeight:400,
	setGameHeight: () => {},
	playerName:'',
	setPlayerName: () => {},
	modeGame: '',
	setModeGame: () => {}, 
	gameStatus: 'NOT_IN_GAME',
	setGameStatus:  () => {},
	matchMe: false,
	setMatchMe: () => {}
}; 

export default React.createContext(defaultState);