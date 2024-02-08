import {useEffect, useContext} from 'react';
import { JoinRoom } from './components/joinRoom';
import GameContext from '../../context/gameContext';
import GameArea from './components/gameArea';
import { GameStatus } from '../../context/gameContext';
import { WaitingRoom } from './components/waitingRoom';
import { gameSocket } from './services/gameSocketService';

function Game() {
	const {gameStatus, roomId, setGameStatus, playerName, setRoomId} = useContext(GameContext);

	useEffect(()=>{
		function processRoomJoined(data:{roomId:number, gameStatus: GameStatus}) {
			setGameStatus(data.gameStatus);
			setRoomId(data.roomId);
		}

		function processErrorJoin(data:{roomId:number, errorMsg:string}) {
			if (data.errorMsg !== 'The room does not exist') {
				window.alert('Error for room ' + data.roomId.toString() + ': ' + data.errorMsg);
			}
			else {
				setGameStatus("OPPONENT_LEFT_ROOM");
			}
		}
		gameSocket.on('room_joined', processRoomJoined);
		gameSocket.on('error_join', processErrorJoin);

		return () => {
			gameSocket.off('room_joined', processRoomJoined);
			gameSocket.off('error_join', processErrorJoin);
		}

	}, [setGameStatus, setRoomId]);

	useEffect(()=> {
		if (roomId !== 0 && gameStatus === 'NOT_IN_GAME') {
			gameSocket.emit("join_room", {roomId:roomId, playerName});
		}

	}, [roomId, gameStatus, playerName])

	return (
		<>
			{ gameStatus === 'NOT_IN_GAME' && <JoinRoom />}
			{ gameStatus === 'IN_WAITING_ROOM' && <WaitingRoom /> }
			{ gameStatus !== 'IN_WAITING_ROOM' && gameStatus !== 'NOT_IN_GAME' && <GameArea />}
		</>
	)
}


export default Game;
