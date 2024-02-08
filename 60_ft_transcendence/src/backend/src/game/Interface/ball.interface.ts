export interface Ball {
	id:number;
	pos: {x:number, y:number};
	dir: {x:number, y:number};
	speed:number;
	startingCountDownStart: Date | null;
	startingCountDown: number;
	active:boolean;
}