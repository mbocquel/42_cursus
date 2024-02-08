import {useContext} from 'react';
import { CreateStyledCell } from '../CreateStyledCell';
import gameContext from '../../../context/gameContext';
import { gameSocket } from '../../game/services/gameSocketService';

export default function GameGrid() {
	const { roomId, playerName, setGameStatus, setRoomId, setModeGame, modeGame, gameStatus} = useContext(gameContext);
	function newBasicGame (){
		leaveRoom();
		setModeGame('BASIC');
		gameSocket.emit('match_me', {playerName:playerName, typeGame:'BASIC'});
	}

	function newAdvancedGame() {
		leaveRoom();
		setModeGame('ADVANCED');
		gameSocket.emit('match_me', {playerName:playerName, typeGame:'ADVANCED'});
	}

    const leaveRoom = () => {
      const dataToSend = {
        waitingRoom: (gameStatus === 'IN_WAITING_ROOM'),
        modeGame: modeGame,
        roomId: roomId
      };
      gameSocket.emit("i_am_leaving", dataToSend);
      setGameStatus('NOT_IN_GAME');
      setRoomId(0);
      setModeGame('');
    };

  	return (
		<div key={"game"}>
		{gameStatus === 'NOT_IN_GAME' && <CreateStyledCell coordX={1} coordY={1} width={2} height={1} text={'New Basic Game'} fontSize={12} className={'title_game'} onClick={newBasicGame} />}
		{gameStatus === 'NOT_IN_GAME' && <CreateStyledCell coordX={3} coordY={1} width={2} height={1} text={'New Advanced Game'} fontSize={12} className={'title_game'} onClick={newAdvancedGame}/>}
		{gameStatus === 'IN_WAITING_ROOM' && <CreateStyledCell coordX={5} coordY={1} width={2} height={1} text={'Leave Waiting Room'} fontSize={12} className={'title_game'} onClick={leaveRoom}/>}
		</div>);
}
