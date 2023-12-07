import Footer from '../components/Footer/Footer'
import Header from '../components/Header/Header';
import { Body } from '../components/Body/Body';
import { useEffect, useRef } from "react";
import styles from "./Desktop1.module.css";
import { useContext, useState } from 'react';
import { PageContext } from '../context/PageContext';
import ChatComponent from '../components/chat/ChatComponent';
import { WebsocketContext } from "../context/chatContext";
import { useLogin } from "../components/user/auth";
import { gameSocket } from '../components/game/services/gameSocketService';
import { GameStatus } from '../context/gameContext';
import GameContext, { IGameContextProps } from '../context/gameContext';

function Desktop1() {

	const auth = useLogin();
	const [roomId, setRoomId] = useState(0);
	const [playerName, setPlayerName] = useState('');
	const [gameWidth, setGameWidth] = useState(0);
	const [gameHeight, setGameHeight] = useState(0);
	const [modeGame, setModeGame] = useState('');
	const [gameStatus, setGameStatus] = useState<GameStatus>('NOT_IN_GAME');
	const [matchMe, setMatchMe] = useState(false);

	const gameContextValue: IGameContextProps = {
		roomId,
		setRoomId,
		gameWidth,
		setGameWidth,
		gameHeight,
		setGameHeight,
		playerName,
		setPlayerName,
		modeGame,
		setModeGame,
		gameStatus,
		setGameStatus,
		matchMe,
		setMatchMe
	};

	//GET HEIGHT
	const socket = useContext(WebsocketContext);

	const windowHeighthRef = useRef(window.innerHeight);

	function DisplayChat() {
		const context = useContext(PageContext);
		if (!context) {
			throw new Error('useContext must be used within a MyProvider');
		}
		const { chat } = context;

		if (chat === "Chat" || chat.search("New DM") !== -1)
			return (<ChatComponent newDM={chat} />);
		else
			return (<div />);
	}

	useEffect(() => {
		const handleResize = () => {
			windowHeighthRef.current = window.innerHeight;
			// Trigger a re-render of the component when window.innerWidth changes
			//forceUpdate();
		};
		window.addEventListener('resize', handleResize);
		return () => {
			window.removeEventListener('resize', handleResize);
		};
	}, []);

	useEffect(() => {
		gameSocket.connect();
		return (() => {
			gameSocket.disconnect();
		})
	}, [auth]);

	useEffect(() => {
		socket.connect();
		return (() => {
			socket.disconnect();
		})
	}, [socket]);

	useEffect(() => {
		if (auth.user.login) {
			setPlayerName(auth.user.login);
			socket.emit("newChatConnection", auth.user.login);
		}
	}, [auth.user.login, socket]);

	return (
		<div className={styles.desktop1} style={{ height: windowHeighthRef.current }}>
			<GameContext.Provider value={gameContextValue}>
				<Body />
				<Header />
				<Footer />
				<DisplayChat />
			</GameContext.Provider>
		</div>
	);
}

export default Desktop1;
