import React, { useState, useEffect, useRef } from 'react';
import { useContext } from 'react';
import { PageContext } from '../../../context/PageContext';

import GameGrid from '../../Sheets/GameGrid/GameGrid';
import Profile from '../../Sheets/Profile/Profile';
import { Data } from '../../Sheets/Data/Data';
import { Contacts } from '../../Sheets/Contacts/Contacts';
import gameContext from '../../../context/gameContext';
import { PageUrlContext } from '../../../context/PageUrlContext';
import { SmartCell } from './SmartCell';


function PageSwitch() {
  //GET SCROLL VALUE
  const context = useContext(PageContext);
  const url_context = useContext(PageUrlContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }
  const { scroll, zoom, toolbar } = context;
  const { scrollX, scrollY } = scroll;
  const [sx, setNewScrollX] = useState(scrollX);
  const [sy, setNewScrollY] = useState(scrollY);

  useEffect(() => {
    setNewScrollX(scrollX);
    setNewScrollY(scrollY);
  }, [scrollX, scrollY]);

  return (
    <div key={'switch'}>
	  {url_context?.page === "Game" && <GameGrid key={"game"}/>}
      {url_context?.page === "Profile" && <Profile key={"profile"}/>}
      {url_context?.page === "Data" && <Data key={"data1"} sx={sx} sy={sy} zoom={zoom} />}
      {url_context?.page === "Contacts" && <Contacts key={"contacts1"} sx={sx} sy={sy} zoom={zoom} toolbar={toolbar} />}
    </div>
  );
}

function Grid() {
  //GET SCROLL VALUE
  const url_context = useContext(PageUrlContext);
  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }
  
  const { zoom, coords, scroll, toolbar } = context;

  const { scrollX, scrollY } = scroll;
  const [sx, setNewScrollX] = useState(scrollX);
  const [sy, setNewScrollY] = useState(scrollY);

  const { coordX, coordY } = coords;
  const [x, setNewCoordX] = useState(coordX);
  const [y, setNewCoordY] = useState(coordY);

  const { modeGame, gameStatus } = useContext(gameContext);

  //HANDLE WINDOW RESIZE
  const windowHeightRef = useRef(window.screen.height);
  const windowWidthRef = useRef(window.screen.width);

  const forceUpdate = useForceUpdate();

  useEffect(() => {
    setNewScrollX(scrollX);
    setNewScrollY(scrollY);
  }, [scrollX, scrollY]);

  useEffect(() => {
    const handleResize = () => {
      windowWidthRef.current = window.screen.width;
      windowHeightRef.current = window.screen.height;
      // Trigger a re-render of the component when window.innerWidth changes
      forceUpdate();
    };
    window.addEventListener('resize', handleResize);
    return () => {
      window.removeEventListener('resize', handleResize);
    };
  }, [forceUpdate]);

  useEffect(() => {
    setNewCoordX(coordX);
    setNewCoordY(coordY);
  }, [coordX, coordY]);

  const components = [];
  for (let i: number = sy; (i - sy) * (80 + ((zoom - 100)) / 2) < windowWidthRef.current; i++) {
    for (let j: number = sx; (j - sx) * (20 + ((zoom - 100)) / 8) < windowHeightRef.current; j++) {
      components.push(
        <SmartCell i={i} j={j} key={i+" "+j}/>)
    }
  }
  let x_square = x - sy;
  if (x === -1)
    x_square = 0;
  let y_square = y - sx;
  if (y === -1)
    y_square = 0;
  components.push(
    <div key={"highlight_cell"} style={{
      position: 'absolute',
      left: `${x_square * (80 + ((zoom - 100) / 2))}px`,
      top: `${y_square * (20 + ((zoom - 100) / 8))}px`,
      width: `${80 + ((zoom - 100) / 2)}px`,
      height: `${20 + ((zoom - 100) / 8)}px`,
      border: '1px solid #15539E',
      outline: '1px solid #15539E',
      pointerEvents: 'none',
    }} />);
  if (y_square !== -1 && x_square !== -1)
    components.push(<div key={"bluesquare"} style={{ position: 'relative', top: `${(y_square * (20 + (zoom - 100) / 8)) + (18 + (zoom - 100) / 8)}px`, left: `${((x_square * (80 + (zoom - 100) / 2)) + (77 + (zoom - 100) / 2))}px`, width: '5px', height: '5px', backgroundColor: '#15539E', }}></div>);

  components.push(PageSwitch());

  //HIGHLIGHT COLUMN, LINE OR EVERYTHING
  let div_width = `${(80 + ((zoom - 100) / 2))}px`;
  let div_height = `${(20 + ((zoom - 100) / 8))}px`;
  let div_top = `${y_square * (20 + ((zoom - 100) / 8))}px`;
  let div_left = `${x_square * (80 + ((zoom - 100) / 2))}px`;
  if (x === -1 && y === -1) {
    div_height = '100%';
    div_width = '100%';
    div_top = '0px';
    div_left = '0px';
  }
  else if (x === -1) {
    div_width = '100%';
    div_left = '0px';
  }
  else if (y === -1) {
    div_height = '100%';
    div_top = '0px';
  }
  if (x === -1 || y === -1)
    components.push(
      <div key={"highlight_column"} style={{
        position: 'absolute',
        top: div_top,
        left: div_left,
        width: div_width,
        height: div_height,
        outline: '0.5px solid #15539E',
        backgroundColor: 'rgba(21, 83, 158, 0.3)',
        pointerEvents: 'none',
      }} />)

  components.push(
    <div key={'waiting room'} style={{ position: 'fixed', top: toolbar ? '89px' : '166px', left: 'calc(1% + 31px)', color: '#000000' }}>
      {(gameStatus === 'IN_WAITING_ROOM') && url_context?.page === "Game" && modeGame === 'BASIC' &&
        <div
          key={`basic waiting room`}
          style={{
            position: 'absolute',
            top: (scroll.scrollX > 1) ? '-100px' : `${(20 + (zoom - 100) / 8) * (1 - scroll.scrollX)}px`,
            left: `${0 + (80 + (zoom - 100) / 2) * (1 - scroll.scrollY)}px`,
            width: `${(80 + (zoom - 100) / 2) * 5}px`,
            height: `${(20 + (zoom - 100) / 8) * 1}px`,
            fontSize: `${12 + ((zoom - 100) / 16)}px`,
            backgroundColor: 'white',
            textAlign: 'center',
            border: '1px solid black',
          }}>
          You are in the waiting room to join a <b>basic</b> game!
        </div>}
      {(gameStatus === 'IN_WAITING_ROOM') && url_context?.page === "Game" && modeGame === 'ADVANCED' && <div
        key={`advanced waiting room`}
        style={{
          position: 'absolute',
          top: (scroll.scrollX > 1) ? '-100px' : `${(20 + (zoom - 100) / 8) * (1 - scroll.scrollX)}px`,
          left: `${0 + (80 + (zoom - 100) / 2) * (1 - scroll.scrollY)}px`,
          width: `${(80 + (zoom - 100) / 2) * 5}px`,
          height: `${(20 + (zoom - 100) / 8) * 1}px`,
          fontSize: `${12 + ((zoom - 100) / 16)}px`,
          backgroundColor: 'white',
          textAlign: 'center',
          border: '1px solid black',
        }}>
        You are in the waiting room to join an <b>advanced</b> game!
      </div>}
    </div>)

  
  return (
    <div key={'grid'}>
      {components}
    </div>);
}
function useForceUpdate() {
  const [, setTick] = useState(0);
  const forceUpdate = () => {
    setTick((tick) => tick + 1);
  };
  return forceUpdate;
}

export default Grid;
