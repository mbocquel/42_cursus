import {useEffect, useState, useContext} from "react";
import { Canvas } from "../canvas";
import gameContext from '../../../../context/gameContext';
import printMenu from "./printMenu";
import printGame from "./printGame";
import { gameSocket } from "../../services/gameSocketService";
import { IPlayer } from "./interfacesGame";
import { IBall } from "./interfacesGame";
import { IObstacles } from "./interfacesGame";
import { PageContext } from "../../../../context/PageContext";

function GameArea(props:any) {
	const {roomId, gameWidth, gameHeight, playerName, gameStatus, setGameStatus} = useContext(gameContext);
	const [timeLastFrame, setTimeLastFrame] = useState(new Date());
	const [idPlayerMove, setIdPlayerMove] = useState(0);
	const [myPlayerMoves, setMyPlayerMoves] = useState<{idPlayerMove: number, dy:number}[]>([]);
	const [mySide, setMySide] = useState('');

	const [pong, setPong] = useState({
		ballRadius: 0,
		paddleWidth: 0,
		paddleHeight: 0,
		netWidth: 0.005,
		netHeight: 0.05,
		netInterval: 0.025,
		backColor: '#000000',
		ballColor: '#f2c546',
		netColor: 'rgba(255,255,255,0)',
		scoreColor: 'rgba(255,255,255,0)',
		scoreFont: 'helvetica',
		scoreFontDecoration: 'bold',
		scoreFontPx: 0.07,
		nameFont: 'helvetica',
		nameFontDecoration: 'bold',
		nameFontPx: 0.03,
		nameColor: 'rgba(255,255,255,0)',
		ballInitSpeed: 0,
		ballInitDir: {x: 0.5, y: -1},
		ballSpeedIncrease: 0,
		paddleSpeed: 0,
		play: false,
		menuBackColor: 'rgba(255,255,255,0)',
		menuTextColor: '#000000',
		menuFont: 'helvetica',
		menuFontDecoration: 'bold',
		menuFontPx: 0.08,
		goal: 0,
		endgame: false,
		startingCount:0
	});

	const styleCanvas = {width:gameWidth, height:gameHeight, backgroundColor: pong.backColor};

	const [frontEndPlayerLeft, setFrontEndPlayerLeft] = useState({
		posY: 0.5,
		score: 0,
		scorePos: {x: 1 / 4, y: 1 / 5},
		upArrowDown:false,
		downArrowDown:false,
		name:"",
		namePos:{x: 1 / 4, y: 0.9},
		color:'#aaaaaa',
		socketId: '',
		readyToPlay:false
	});

	const [frontEndPlayerRight, setFrontEndPlayerRight] = useState({
		posY: 0.5,
		score: 0,
		scorePos: {x: 3 / 4, y: 1 / 5},
		upArrowDown:false,
    	downArrowDown:false,
		name: "",
		namePos: {x: 3 / 4, y: 0.9},
		color: '#aaaaaa',
		socketId: '',
		readyToPlay:false
	});

	const [balls, setBalls] = useState<IBall[]>([{
		id:0,
		pos: {x: 1 / 2, y: 1 / 2},
		speed: pong.ballInitSpeed,
		dir: pong.ballInitDir,
		startingCountDownStart: null,
		startingCountDown: 0,
		active:false
	}]);

	const [obstacles, setObstacles] = useState<IObstacles[]>([]);

	useEffect(() => {
		gameSocket.emit("give_me_room_status", {roomId});
	},[roomId]);

	useEffect(() => {
		function onRoomStatus(data:any) {
			if(data.idRoom !== roomId) return;
			setPong((prev) => ({...prev,
				ballRadius: data.gameParam.ballRadius,
				paddleWidth: data.gameParam.paddleWidth,
				paddleHeight: data.gameParam.paddleHeight,
				paddleSpeed:data.gameParam.paddleSpeed,
				goal:data.gameParam.goal
			}));
			setGameStatus(data.gameStatus);
			setBalls(data.balls);
			if (typeof(data.playerLeft.name) !== 'undefined' && typeof(data.playerLeft.socketId) !== 'undefined') {
				setFrontEndPlayerLeft((prev) => ({...prev,
				name: data.playerLeft.name,
				socketId: data.playerLeft.socketId}));
				if (data.playerLeft.socketId === gameSocket.id) setMySide('left');
			}
			else {
				setFrontEndPlayerLeft((prev) => ({...prev,
					name: '',
					socketId: ''}))
			}
			if (typeof(data.playerRight.name) !== 'undefined' && typeof(data.playerRight.socketId) !== 'undefined') {
				setFrontEndPlayerRight((prev) => ({...prev,
				name: data.playerRight.name,
				socketId: data.playerRight.socketId}));
				if (data.playerRight.socketId === gameSocket.id) setMySide('right');
			}
			else {
				setFrontEndPlayerRight((prev) => ({...prev,
					name: '',
					socketId: ''}))
			}
		}
		gameSocket.on('room_status', onRoomStatus);

		return () => {
			gameSocket.off('room_status', onRoomStatus);
		}

	}, [playerName, roomId, mySide, setGameStatus]);



	useEffect(()=>{
		function updatePendingMoves(data:any){
			let idLimit:number;
			idLimit = (mySide === 'left' ?  data.playerLeft.idPlayerMove : data.playerRight.idPlayerMove);
			const myNewPlayerMove = myPlayerMoves.filter((val) => {return (val.idPlayerMove > idLimit)});
			setMyPlayerMoves(myNewPlayerMove);
		}

		function onGameState(data:any) {
			if(data.roomId !== roomId) return;
			setBalls(data.balls);
			setObstacles(data.obstacles);
			updatePendingMoves(data);
			let myPosY:number = (mySide === 'left' ? data.playerLeft.posY : data.playerRight.posY);
			let otherPlayerPosY:number = (mySide === 'left' ? data.playerRight.posY : data.playerLeft.posY );
			myPlayerMoves.forEach((playerMove) => {
				myPosY += playerMove.dy;
			});
			if (mySide === 'left') {
				setFrontEndPlayerLeft((prev) => ({ ...prev, posY: myPosY, score: data.scoreLeft, readyToPlay:data.playerLeft.readyToPlay}));
				setFrontEndPlayerRight((prev) => ({ ...prev, posY: otherPlayerPosY, score: data.scoreRight, readyToPlay:data.playerRight.readyToPlay}));
			}
			else {
				setFrontEndPlayerRight((prev) => ({ ...prev, posY: myPosY, score: data.scoreRight, readyToPlay:data.playerRight.readyToPlay}));
				setFrontEndPlayerLeft((prev) => ({ ...prev, posY: otherPlayerPosY, score: data.scoreLeft, readyToPlay:data.playerLeft.readyToPlay}));
			}
			setPong((prev) => ({ ...prev, startingCount: data.startingCount}));
			setGameStatus(data.gameStatus)
		}

		gameSocket.on('game_state', onGameState);
		return () => {
			gameSocket.off('game_state', onGameState);
		}

	}, [myPlayerMoves, mySide, roomId, setGameStatus]);

	useEffect(() => {
		const handleKey = (event: KeyboardEvent) => {
			let move:boolean = false;
			if (event.type === 'keydown') {
				move = true;
			}
			switch (event.code){
				case 'KeyW':
					mySide === 'left' ? setFrontEndPlayerLeft((prev) => ({...prev, upArrowDown: move})) : setFrontEndPlayerRight((prev) => ({...prev, upArrowDown: move}))
					break;
				case 'KeyS':
					mySide === 'left' ? setFrontEndPlayerLeft((prev) => ({...prev, downArrowDown: move})) : setFrontEndPlayerRight((prev) => ({...prev, downArrowDown: move}))
					break;
				case 'ArrowUp':
					mySide === 'left' ? setFrontEndPlayerLeft((prev) => ({...prev, upArrowDown: move})) : setFrontEndPlayerRight((prev) => ({...prev, upArrowDown: move}))
					break;
				case 'ArrowDown':
					mySide === 'left' ? setFrontEndPlayerLeft((prev) => ({...prev, downArrowDown: move})) : setFrontEndPlayerRight((prev) => ({...prev, downArrowDown: move}))
					break;
				case 'Space':
					gameSocket.emit('keyevent', {roomId: roomId, key:'Space', idPlayerMove:idPlayerMove});
					break;
				default:
					return;
			}
		};

		window.addEventListener('keydown', handleKey);
		window.addEventListener('keyup', handleKey);
		return (() => {
			window.removeEventListener('keydown', handleKey)
			window.removeEventListener('keyup', handleKey)
		});
	}, [frontEndPlayerLeft.posY, frontEndPlayerRight.posY, mySide, idPlayerMove, roomId]);

	function moveMyPlayerImediately() {
		const now = new Date();
		const timePastSinceLastFrame = now.getTime() - timeLastFrame.getTime();
		if (timePastSinceLastFrame < 15) return;
		setTimeLastFrame(now);

		if (gameStatus !== 'PLAYING') return;

		let MyPlayer:IPlayer;
		MyPlayer = (mySide === 'left' ? frontEndPlayerLeft : frontEndPlayerRight);
		let MyPlayerMove = {
			idPlayerMove : idPlayerMove,
			dy:0
		};
		if (MyPlayer.upArrowDown || MyPlayer.downArrowDown) {
			const previousPosY = MyPlayer.posY;
			if (MyPlayer.upArrowDown) {
				MyPlayer.posY = Math.max(pong.paddleHeight / 2, MyPlayer.posY - pong.paddleSpeed);
				gameSocket.emit('keyevent', {roomId: roomId, key:'KeyW', idPlayerMove:idPlayerMove});
			}
			if (MyPlayer.downArrowDown) {
				MyPlayer.posY = Math.min(1 - pong.paddleHeight / 2,  MyPlayer.posY + pong.paddleSpeed);
				gameSocket.emit('keyevent', {roomId: roomId, key:'KeyS', idPlayerMove:idPlayerMove});
			}
			MyPlayerMove.dy = MyPlayer.posY - previousPosY;
			myPlayerMoves.push(MyPlayerMove);
			setMyPlayerMoves(myPlayerMoves);
			setIdPlayerMove(idPlayerMove + 1);
		}
	};

	const context = useContext(PageContext);
	if (!context) { throw new Error('useContext must be used within a MyProvider'); }
	const { game, updateGame } = context;
	function render(context:CanvasRenderingContext2D):void {
		if (game.player1 !== frontEndPlayerLeft.name || game.player2 !== frontEndPlayerRight.name || game.points1 !== frontEndPlayerLeft.score || game.points2 !== frontEndPlayerRight.score)
			updateGame({player1: frontEndPlayerLeft.name, player2: frontEndPlayerRight.name, points1: frontEndPlayerLeft.score, points2: frontEndPlayerRight.score});
		moveMyPlayerImediately();
		context.clearRect(0, 0, context.canvas.width, context.canvas.height)
		printGame({context:context, pong:pong, playerLeft:frontEndPlayerLeft, playerRight:frontEndPlayerRight, balls:balls, obstacles: obstacles, gameWidth:gameWidth, gameHeight:gameHeight});
		printMenu({pong:pong, gameStatus: gameStatus, context:context, gameWidth:gameWidth, gameHeight:gameHeight, frontEndPlayerLeft:frontEndPlayerLeft, frontEndPlayerRight:frontEndPlayerRight,});
	}

	return (
		<>
			<Canvas draw = {render} style={styleCanvas} />
			<div><strong>You play on the {mySide} !</strong></div>
			<div>Status {gameStatus?.toString()} for Room {roomId?.toString()}</div>
			<div>PaddleSpeed {pong?.paddleSpeed}</div>
		</>
	);
};

export default GameArea
