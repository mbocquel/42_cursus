import React, { useContext, useEffect, useState } from 'react';
import gameContext from '../../../../context/gameContext';
import { gameSocket } from '../../services/gameSocketService';
import { GameStatus } from '../../../../context/gameContext';

interface IJoinRoomProps {
};

export function JoinRoom(props:IJoinRoomProps) {
	const {setRoomId, setGameStatus} = useContext(gameContext);
	const [RecievedRoomID, setRecievedRoomID] = useState(0);

	useEffect(()=>{

		function processNewEmptyRoom(data:{roomId:number}) {
			setRecievedRoomID(data.roomId);
		}
		function processWaitingRoomJoined() {
			setGameStatus('IN_WAITING_ROOM');
		}

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

		gameSocket.on('new_empty_room', processNewEmptyRoom);
		gameSocket.on('waiting_room_joined', processWaitingRoomJoined);
		gameSocket.on('room_joined', processRoomJoined);
		gameSocket.on('error_join', processErrorJoin);

		return () => {
			gameSocket.off('new_empty_room', processNewEmptyRoom);
			gameSocket.off('waiting_room_joined', processWaitingRoomJoined);
			gameSocket.off('room_joined', processRoomJoined);
			gameSocket.off('error_join', processErrorJoin);
		}

	}, [RecievedRoomID, setGameStatus, setRoomId]);

	return (
		<></>
	)
};
