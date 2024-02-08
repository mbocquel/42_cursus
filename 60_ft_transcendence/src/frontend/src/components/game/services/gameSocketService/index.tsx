import { io, Socket } from "socket.io-client";

export const gameSocket: Socket = io(
  "http://" + process.env.REACT_APP_URL_MACHINE + ":4000/game_socket",
  {
    // we need this socket to not connect until someone il log
    transports: ["websocket"],
    withCredentials: true,
    autoConnect: false,
  }
);
