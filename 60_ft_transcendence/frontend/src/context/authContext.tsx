import React, { createContext, useContext, useEffect, useState } from "react";
import ChatContext from "../context/chatContext";
import chatContext from "../context/chatContext";
import ConnectionContext from "./authContext";

export interface IConnected {
	username: string,
	setUsername: (username: string) => void;
}

const defaultState:IConnected = {
	username: '',
	setUsername: () => {},
}

export default React.createContext(defaultState);