import { IgameParams } from "../Interface/gameParam.interface"

export const gameParams : IgameParams[] = [
	{
		type:'BASIC', 
		ballRadius: 0.007,
		paddleWidth: 0.01,
		paddleHeight: 0.25,
		ballSpeedIncrease: 0.0005,
		paddleSpeed: 0.01,
		goal: 4,
		ballInitPosx: 0.5,
		ballInitPosy: 0.5,
		BallInitDirx: 0.5,
		BallInitDiry: -1,
		BallInitSpeed: 0.006
	}, 
	{
		type:'ADVANCED', 
		ballRadius: 0.007,
		paddleWidth: 0.01,
		paddleHeight: 0.25,
		ballSpeedIncrease: 0.0005,
		paddleSpeed: 0.01,
		goal: 8,
		ballInitPosx: 0.5,
		ballInitPosy: 0.5,
		BallInitDirx: 0.5,
		BallInitDiry: -1,
		BallInitSpeed: 0.006
	}
]