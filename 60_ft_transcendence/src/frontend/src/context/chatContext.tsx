import React, { createContext } from 'react';
import { io, Socket } from 'socket.io-client';
import { Channel } from '../components/chat/ChatComponent';

export const socket = io('http://' + process.env.REACT_APP_URL_MACHINE + ':4000/chat', {
	// we need this socket to not connect until someone il log
	transports: [ "websocket" ],
	withCredentials: true,
	autoConnect:false
});
export const WebsocketContext = createContext<Socket>(socket);

export const WebsocketProvider = WebsocketContext.Provider;


export interface IChatContext {
	allChannels: Channel[],
	setAllChannels: (allChannels: Channel[]) => void;
	activeChannel: Channel,
	setActiveChannel: (activeChannel: Channel) => void;
	needToUpdate: string,
	setNeedToUpdate: (str: string) => void;
	blockedUsers: {idUser: number, username: string, login: string}[];
	setBlockedUsers: (blocked: {idUser: number, username: string, login: string}[]) => void;
	allAvatarsURL: {login:string, avatar:string}[];
	setAllAvatarsURL: (allAvatars: {login:string, avatar:string}[]) => void;
	allAvatarsImg: {login:string,imageObjectURL:string| undefined}[];
	setAllAvatarsImg: (allAvatars: {login:string,  imageObjectURL:string | undefined}[]) => void;
};

const defaultState:IChatContext = {
	allChannels: [],
	setAllChannels: () => {},
	activeChannel: {
		id: -1,
		channelName: "PongOffice Chat",
		type: "",
		status: "",
		username: null,
		dateSend: null,
		msg: null,
		userId: null,
		userLogin: "",
	},
	setActiveChannel: () => {},
	needToUpdate: "",
	setNeedToUpdate: () => {},
	blockedUsers: [],
	setBlockedUsers: () => {},
	allAvatarsURL: [],
	setAllAvatarsURL: () => {},
	allAvatarsImg: [],
	setAllAvatarsImg: () => {}
};

export default React.createContext(defaultState);
