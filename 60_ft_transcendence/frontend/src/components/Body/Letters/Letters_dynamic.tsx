import React, { useContext, useState, useEffect, useRef } from 'react';
import { PageContext } from '../../../context/PageContext';
import styles from "./Letters.module.css";

export function convertToLetters(n : number) : string {

  let string = "";
  if (n === 0 || n === 26)
    string = "A";
  let j = n;
  if (j >= 26)
    j = j - 26;
  for (; j > 0; j = Math.floor(j / 26)) {
    string = String.fromCharCode((j%26)+65) + string;
  }
  if (n >= 26 && n < 52)
    string = "A" + string;
  return (string);
}

function RepeatingLetters() {
  const windowWidthRef = useRef(window.screen.width);

  const forceUpdate = useForceUpdate();

  useEffect(() => {
    const handleResize = () => {
      windowWidthRef.current = window.screen.width;
      // Trigger a re-render of the component when window.innerWidth changes
      forceUpdate();
    };

    window.addEventListener('resize', handleResize);

    return () => {
      window.removeEventListener('resize', handleResize);
    };
  }, [forceUpdate]);

  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider');}

  const { coords, updateCoords } = context;
  const { coordX, coordY } = coords;

  const [localCoordX, setLocalCoordX] = useState(coordX);

  const handleUpdateCoords = (a: number, b: number) => {
    setLocalCoordX(a);
    updateCoords({ coordX: a, coordY: b });
  };

  useEffect(() => {
    setLocalCoordX(coordX);
  }, [coordX, coordY]);

  const components = [];

  const { scroll, dark } = context;
  const { scrollX, scrollY } = scroll;
  const [sy, setNewScrollY] = useState(scrollY);
  const { zoom } = context;
    
  useEffect(() => {
    setNewScrollY(scrollY);
  }, [scrollX, scrollY]);

  for (let i = 0; i * (80 + (zoom - 100)/2) < windowWidthRef.current; i++) {
    const n = i + sy;
    const dynamicLeft = `${(i) * (80 + (zoom - 100)/2)}px`;
    let string = "";
    if (n === 0 || n === 26)
      string = "A";
    let j = n;
    if (j >= 26)
      j = j - 26;
    for (; j > 0; j = Math.floor(j / 26)) {
      string = String.fromCharCode((j%26)+65) + string;
    }
    if (n >= 26 && n < 52)
      string = "A" + string;
    if (n  === localCoordX || localCoordX === -1)
    {
      components.push(
      <div  key={`x:${i}+${string}`}
            style={{
              fontSize: '14px',
              position: 'absolute',
              top: '0px',
              left: dynamicLeft,
              width: `${(80 + (zoom - 100)/2)}px`,
              height: '24px',}}
            onMouseDown={() => handleUpdateCoords(i + sy, -1)}>
          <div className={styles.background } style={{
          width: `${(80 + (zoom - 100)/2)}px`,
          backgroundColor: '#15539E',
          fontWeight:'bold',
        }}>{string}</div>
          <div className={styles.letter} style={{
            width: `${(80 + (zoom - 100)/2)}px`,
          }}/>
      </div>);
    }
    else
    {
      components.push(
        <div  key={`x:${i}+${string}`}
              style={{
                fontSize: '14px',
                position: 'absolute',
                top: '0px',
                left: dynamicLeft,
                width: `${(80 + (zoom - 100)/2)}`,
                height: '24px',
              }}
              onMouseDown={() => handleUpdateCoords(i + sy, -1)}>
            <div className={dark ? styles.background : styles.backgroundLight} style={{width: `${(80 + (zoom - 100)/2)}px`,}}>{string}</div>
            <div className={styles.letter} />
        </div>);
    }

    
  }
  return (
    <div>
        {components}
    </div>
  );
}

function useForceUpdate() {
  const [, setTick] = useState(0);
  const forceUpdate = () => {
    setTick((tick) => tick + 1);
  };
  return forceUpdate;
}

export default RepeatingLetters;
