// import styles from "../pages/Desktop1.module.css";
import styles from "./Body.module.css";
import Numbers from "./Numbers/Numbers_dynamic";
import Letters from "./Letters/Letters_dynamic";
import Grid from "./Grid/Grid_dynamic";
import { PageContext } from "../../context/PageContext";
import { useContext, useState, useEffect } from 'react';
import Game from "../game/Game";
import { PageUrlContext } from "../../context/PageUrlContext";



export function Body() {
  const context = useContext(PageContext);
  const url_context = useContext(PageUrlContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }

  const { scroll, dark, toolbar, updateCoords, updateScroll } = context;

  const { scrollX, scrollY } = scroll;
  const [sx, setNewScrollX] = useState(scrollX);
  const [sy, setNewScrollY] = useState(scrollY);

  const handleUpdateCoords = (a: number, b: number) => {
    updateCoords({ coordX: a, coordY: b });
  };

  const handleUpdateScroll = (event: any) => {
    let i = 0;
    if (event.deltaY < 0)
      i = -1;
    if (event.deltaY > 0)
      i = 1;
    if (event.shiftKey && !event.ctrlKey && sy + i >= 0)
      updateScroll({scrollX: sx, scrollY:sy + i})
    else if (sx + i >= 0 && !event.ctrlKey)
      updateScroll({ scrollX: sx + i, scrollY: sy});
  };
  useEffect(() => {
    setNewScrollX(scrollX);
    setNewScrollY(scrollY);
  }, [scrollX, scrollY]);

  return (
      <div className={styles.body} onWheel={handleUpdateScroll} >

        <div className={styles.grid} style={{top: toolbar ? '89px' : '166px' }}>
          <Grid />
        </div>

        <div className={dark ? styles.up : styles.upLight} style={{top: toolbar ? '65px' : '142px' }} onMouseDown={() => handleUpdateCoords(-1, -1)}/>
        <div className={dark ? styles.rightLettersFrame : styles.rightLettersFrameLight} style={{top: toolbar ? '89px' : '166px' }}>
          <div className={dark ? styles.rightLettersBackground : styles.rightLettersBackgroundLight} />
          <Numbers />
        </div>
        <div className={styles.letters} style={{top: toolbar ? '65px' : '142px' }}>
          <Letters />
        </div>
        <div className={styles.racketPlayer2}>
          <div className={dark ? styles.rightScrollZone : styles.rightScrollZoneLight} />
        </div>
        <div className={styles.racketPlayer1}>
          <div className={dark ? styles.rightScrollZone : styles.rightScrollZoneLight} />
        </div>
		    { url_context?.page === "Game" && <Game />}
      </div>
  )
}
