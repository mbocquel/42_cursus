import { useContext, useState, useEffect, useRef } from 'react';
import { PageContext } from '../../../context/PageContext';
import styles from "./Numbers.module.css";

function RepeatingNumbers() {
  const windowHeightRef = useRef(window.screen.height);


  const forceUpdate = useForceUpdate();
  
  useEffect(() => {
    const handleResize = () => {
      windowHeightRef.current = window.screen.height;
      // Trigger a re-render of the component when window.innerHeight changes
      forceUpdate();
    };

    window.addEventListener('resize', handleResize);

    return () => {
      window.removeEventListener('resize', handleResize);
    };
  }, [forceUpdate]);

  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }

  const { coords, updateCoords } = context;
  const { coordX, coordY } = coords;

  const [localCoordY, setLocalCoordY] = useState(coordY);
  
  const handleUpdateCoords = (a: number, b: number) => {
    setLocalCoordY(b);
    updateCoords({ coordX: a, coordY: b });
  };

  useEffect(() => {
    setLocalCoordY(coordY);
  }, [coordX, coordY]);

  const { zoom, scroll } = context;
  const { scrollX, scrollY } = scroll;

  const [sx, setNewScrollX] = useState(scrollX);
    
  useEffect(() => {
    setNewScrollX(scrollX);
  }, [scrollX, scrollY]);

  const components = [];
  for (let index = 1; index * (20 + (zoom - 100)/8) < windowHeightRef.current; index++) {
    const i = index + sx;
    const dynamicTop = `${(index) * (20 + (zoom - 100)/8) - (20 + (zoom - 100)/8)}px`;
    if (i === localCoordY + 1 || localCoordY === -1)
    {
      components.push(
      <div  key={`y:${i}`}
            style={{
              position: 'absolute',
              top: dynamicTop,
              left: '0px',
              width: '31px',
              height: `${(20 + (zoom - 100)/8)}px`,
              backgroundColor: '#15539E',
              color: 'white',
              fontWeight:'bold',
              outline:'0px solid #104482',}}
            onMouseDown={() => handleUpdateCoords(-1, i - 1)}>
          <div className={styles.numberGroupChild} style={{height: `${(20 + (zoom - 100)/8)}px`,}}/>
          <div className={styles.numbers} style={{height: `${(20 + (zoom - 100)/8)}px`, fontSize: `${14 +((zoom - 100)/32)}px`,}}>{i}</div>
      </div>
    );}
    else
    {
      components.push(
        <div  key={`y:${i}`}
              style={{
                position: 'absolute',
                top: dynamicTop,
                left: '0px',
                width: '31px',
                height: `${(20 + (zoom - 100)/8)}px`,}}
            onMouseDown={() => handleUpdateCoords(-1, i - 1)}>
            <div className={styles.numberGroupChild} style={{height: `${(20 + (zoom - 100)/8)}px`,}} />
            <div className={styles.numbers} style={{height: `${(20 + (zoom - 100)/8)}px`,
          fontSize: `${14 +((zoom - 100)/32)}px`,}}>{i}</div>
        </div>
      );
    }
  }

  return (
    <div >
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

export default RepeatingNumbers;
