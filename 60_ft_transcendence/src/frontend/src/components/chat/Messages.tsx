import { useEffect, useRef } from 'react';
import Message from "./Message";
import "./Messages.scss";
import { useContext, useState } from 'react';
import chatContext, { WebsocketContext } from "../../context/chatContext";
import { useLogin } from "../../components/user/auth";
import { usePrevious } from "@uidotdev/usehooks";

type ChatMessage = {
	msg: string;
	username: string;
	login: string;
	date: string;
	id: number;
	chatId: number;
	serviceMessage: boolean;
	userId: number;
}

const Messages = (props: {chatId: number, isOwner: boolean, setIsOwner: Function, isAdmin: boolean, setIsAdmin: Function, isDM: boolean}) => {
	const auth = useLogin();
	const [render, setRender] = useState(false);
	const socket = useContext(WebsocketContext);
	const { blockedUsers } = useContext(chatContext)
	const [chatHistory, setChatHistory] = useState<ChatMessage[]>([]);
	const [chatMessages,setChatMessages] = useState<ChatMessage[]>([]);
	const [invite, setInvite] = useState(false);
	const previousLen = usePrevious(chatMessages.length);

	useEffect(() => {
			socket.on('chatMsgHistory', (chatHistoryReceive : ChatMessage[]) => {
			if (chatHistoryReceive.find((element) => element.serviceMessage === true && props.isDM === true && element.msg.search("game invitation received") !== -1))
				setInvite(true);
			if (chatHistoryReceive.find((element) => element.serviceMessage === true && props.isDM === true && element.msg.search("Challenge accepted !") !== -1))
				setInvite(false);
			setChatHistory(chatHistoryReceive);
			setRender(true);
		});
		socket.on('newMessage', (chatHistoryReceive :{msg: string, username: string, login: string, date: Date, id: number, idOfChat:number, serviceMessage: boolean, userId: number}) => {
			let newDateString = chatHistoryReceive.date.toString();
			newDateString = newDateString.slice(newDateString.indexOf("T") + 1, newDateString.indexOf("T") + 9);
			const add : ChatMessage = {msg: chatHistoryReceive.msg, username: chatHistoryReceive.username, login: chatHistoryReceive.login, date: newDateString, id: chatHistoryReceive.id, chatId: chatHistoryReceive.idOfChat, serviceMessage: chatHistoryReceive.serviceMessage, userId: chatHistoryReceive.userId}
			if (add.serviceMessage === true && props.isDM === true && add.msg.search("game invitation received") !== -1)
				setInvite(true);
			if (add.serviceMessage === true && props.isDM === true && add.msg.search("Challenge accepted !") !== -1)
				setInvite(false);
			setChatMessages((prevMessages) => [...prevMessages, add]);
			if (blockedUsers.find(element => element.idUser === chatHistoryReceive.userId) === undefined)
				socket.emit("chatListOfUser",auth.user.login);
			if (props.isAdmin === false && add.serviceMessage === true && add.msg === auth.user.username + " is now an administrator of this channel")
				props.setIsAdmin(true);
			else if (props.isOwner === false && add.serviceMessage === true && add.msg.indexOf(auth.user.username + " now owns this channel") !== -1)
				props.setIsOwner(true);
				
		});
		return () => {

			socket.off('chatMsgHistory');
			socket.off('newMessage');
		}
	}, [auth.user.login, auth.user.username, blockedUsers, props, socket])

	useEffect(() => {
		if (render === true)
		{
			for (const element of chatHistory)
				{
					let newDateString = element.date.toString();
					newDateString = newDateString.slice(newDateString.indexOf("T") + 1, newDateString.indexOf("T") + 9);
					const add : ChatMessage = {msg: element.msg, username: element.username, login: element.login, date: newDateString, id: element.id, chatId: element.chatId, serviceMessage: element.serviceMessage, userId: element.userId}
					setChatMessages((prevMessages) => [...prevMessages, add]);
				}
			setRender(false);
		}
	}, [chatHistory, render]);

	useEffect(() => {
		setChatMessages([]);
	}, [props.chatId])

	const endRef = useRef<HTMLDivElement>(null);

	useEffect(() => {
		if (chatMessages.length > 0) {
			if (previousLen === chatMessages.length - 1) {
				endRef.current?.scrollIntoView({
					behavior: "smooth",
					block: "end",
				});
			} else {
				endRef.current?.scrollIntoView({
					behavior: "auto",
					block: "end",
				});
			}
		}
	}, [chatMessages.length, previousLen]);

	return (
        <div className='messages'>
			{chatMessages.length === 0 ? (
				<div></div>
				) : (
					<div className='messageArray'>
						{chatMessages.map((message) => {
							if (blockedUsers.find(element => element.idUser === message.userId) === undefined) {
							return (
							<div key={message.date + message.id} className="messageUnit">
								{message.chatId === props.chatId && (
									 <Message date={message.date}
									 	username={message.username}
										login={message.login} msg={message.msg}
										isOwner={props.isOwner}
										isAdmin={props.isAdmin}
										chatId={props.chatId}
										service={message.serviceMessage}
										isDM={props.isDM}
										msgId={message.id} setInvite={setInvite} invite={invite}/>
								)}
							</div>)
							} else {
								return(<div key={message.date + message.id}></div>);
							}
			  			})}
			  		</div>
				)}
				<div ref={endRef} />
		</div>
    )
}


export default Messages;
