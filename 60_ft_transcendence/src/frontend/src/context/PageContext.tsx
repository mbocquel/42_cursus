import React, { createContext, useState, ReactNode } from 'react';

type SharedData = {
  menu: string;
  chat: string;
  zoom: number;
  toolbar: boolean;
  dark: boolean;
  coords: { coordX: number; coordY: number };
  scroll: { scrollX: number; scrollY: number };
  game: { player1: string; player2: string; points1: number; points2: number };
  div: { font: string; bold: boolean; italic: boolean; underLined: boolean; align: string};
  matchMe : {matchMe:boolean, gameMode:string};
  updateMenu: (menu: string) => void;
  updateChat: (chat: string) => void;
  updateZoom: (zoom: number) => void;
  updateToolbar: (newTool: boolean) => void;
  updateDark: (newDark: boolean) => void;
  updateMenuChat: (menu: string, chat: string) => void;
  updateCoords: (newCoords: { coordX: number; coordY: number }) => void;
  updateCoordsMenu: (newCoords: { coordX: number; coordY: number }, newMenu: string) => void;
  updateScroll: (newScroll: { scrollX: number; scrollY: number }) => void;
  updateGame: (newGame: { player1: string; player2: string; points1: number; points2: number }) => void;
  updateDiv: (newDiv: { font: string; bold: boolean; italic: boolean; underLined: boolean; align: string }) => void;
  updateDivMenu: (newDiv: { font: string; bold: boolean; italic: boolean; underLined: boolean; align: string }, menu: string) => void;
  updateMatchMe: (matchMe : {matchMe:boolean, gameMode:string}) => void;
};

const PageContext = createContext<SharedData | undefined>(undefined);

type MyProviderProps = {
  children: ReactNode;
};

function PageProvider({ children }: MyProviderProps) {
  const [sharedData, setSharedData] = useState({
    menu:'none',
    chat:'none',
    zoom:125,
    toolbar:false,
    dark: window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches,
    coords: { coordX: 0, coordY: 0 },
    scroll: { scrollX: 0, scrollY: 0 },
    game: {player1: "player1", player2: "player2", points1: 0, points2: 0},
    div: {font: "Arial, sans-serif", bold: false, italic: false, underLined: false, align: "left"},
	matchMe : {matchMe:false, gameMode:'BASIC'},
  });

  const updateMenu = (newData: string) => {
    setSharedData({ ...sharedData, menu: newData });
  };
  const updateChat = (newData: string) => {
    setSharedData({ ...sharedData, chat: newData });
  };
  const updateZoom = (newData: number) => {
    setSharedData({ ...sharedData, zoom: newData });
  };
  const updateToolbar = (newData: boolean) => {
    setSharedData({ ...sharedData, toolbar: newData });
  };
  const updateDark = (newDark: boolean) => {
    setSharedData({ ...sharedData, dark: newDark });
  };
  const updateMenuChat = (newMenu: string, newChat: string) => {
    setSharedData({ ...sharedData, menu: newMenu, chat: newChat});
  };
  const updateCoords = (newCoords: { coordX: number; coordY: number }) => {
    setSharedData({ ...sharedData, coords: { ...newCoords } });
  };
  const updateCoordsMenu = (newCoords: { coordX: number; coordY: number }, newMenu: string) => {
    setSharedData({ ...sharedData, coords: { ...newCoords }, menu: newMenu});
  };
  const updateScroll = (newScroll: { scrollX: number; scrollY: number }) => {
    setSharedData({ ...sharedData, scroll: { ...newScroll } });
  };
  const updateGame = (newGame: { player1: string; player2: string; points1: number; points2: number}) => {
    setSharedData({ ...sharedData, game: { ...newGame } });
  };
  const updateDiv = (newDiv: { font: string; bold: boolean; italic: boolean; underLined: boolean; align: string}) => {
    setSharedData({ ...sharedData, div: { ...newDiv } }); 
  };
  const updateDivMenu = (newDiv: { font: string; bold: boolean; italic: boolean; underLined: boolean; align: string}, newMenu: string) => {
    setSharedData({ ...sharedData, menu: newMenu, div: { ...newDiv },  }); 
  };
  const updateMatchMe = (newMatchMe: {matchMe:boolean, gameMode:string}) => {
    setSharedData({ ...sharedData, matchMe: newMatchMe });
  };

  return (
    <PageContext.Provider value={{ ...sharedData, updateMenu, updateChat, updateZoom, updateToolbar, updateDark, updateMenuChat, updateCoords, updateCoordsMenu, updateScroll, updateGame, updateDiv, updateDivMenu, updateMatchMe}}>
      {children}
    </PageContext.Provider>
  );
}

export { PageProvider, PageContext };