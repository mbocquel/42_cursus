import { SelectBar } from './SelectBar';
import { Tooltip } from "@mui/material";
import styles from "./Header.module.css";
import { useContext } from "react";
import { PageContext } from '../../context/PageContext';
import { useLogin } from '../user/auth';
import { GameBar } from './GameBar';
import gameContext from "../../context/gameContext";
import CloseIcon from '@mui/icons-material/Close';
import ArrowDropDownIcon from '@mui/icons-material/ArrowDropDown';
import { useNavigate } from 'react-router-dom';
import { DivSelector } from './DivSelector';
import { convertToLetters } from '../Body/Letters/Letters_dynamic';
import { useState, useEffect } from 'react';

function Header() {
  const auth = useLogin();
  const [image, setImage] = useState("");

  const context = useContext(PageContext);
  if (!context) {
    throw new Error('useContext must be used within a MyProvider');
  }
  const { dark, toolbar, menu , coords, updateMenu } = context;
  function handleClick(str : string) {
    updateMenu(str);
  }
  function printGameMenu() : boolean {
    if ('NOT_IN_GAME' === gameStatus || 'IN_WAITING_ROOM' === gameStatus || 'WAITING_FOR_PLAYER' === gameStatus)
      return (false);
    return (true);
  }
  const {gameStatus} = useContext(gameContext);
  const navigate = useNavigate();

  useEffect(() => {
    const fetchImage = async () => {
      const bearer = auth.getBearer();
      const res = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/avatar/` + auth.user.avatar, {
        method: "GET",
        headers: { Authorization: bearer },
      });
      const imageBlob = await res.blob();
      const imageObjectURL = URL.createObjectURL(imageBlob);
      setImage(imageObjectURL);
    };
    if (auth.user.avatar) {
      try {
        fetchImage().catch((e) => console.error("Failed to fetch the avatar"));
      } catch (e) {
        console.error(e);
      }
    }
  }, [auth]);

  return <header className={styles.headerFrame} style={{ height: toolbar ? '65px' : '142px' }}>
        <div className={dark ? styles.headerBackground : styles.headerBackgroundLight} style={{ height: toolbar ? '65px' : '142px' }}/>
        <div className={styles.line3}>
        {(printGameMenu()) ? <GameBar /> : <input className={dark ? styles.bar : styles.barLight} id="useless input"/> }
          <div className={styles.menu}>
            <div className={dark ? styles.menuBackground : styles.menuBackgroundLight} />
            <div className={styles.buttpn}>
              <div className={dark ? styles.buttonBackground : styles.buttonBackgroundLight} />
              <ArrowDropDownIcon  sx={{fontSize:'22px'}} className={dark ? styles.buttonChild : styles.buttonChildLight} />
            </div>
            <div className={styles.frameText}>
              <div className={dark ? styles.basicSansCs : styles.basicSansCsLight}>{convertToLetters(coords.coordX)}{coords.coordY+1 !== 0 ? coords.coordY+1 : ""}</div>
            </div>
          </div>
        </div>
        <div className={styles.line2}>
          <div className={styles.menu2}>
            <div className={dark ? styles.menuBackground : styles.menuBackgroundLight} />
            <div className={styles.buttpn}>
              <div onClick={() => (menu === "Font" ? updateMenu("none") : updateMenu("Font"))} className={dark ? styles.buttonBackground : styles.buttonBackgroundLight} />
              <ArrowDropDownIcon sx={{fontSize:'22px'}} className={dark ? styles.buttonChild : styles.buttonChildLight} />
            </div>
            <div className={styles.frameText}>
              <div className={dark ? styles.basicSansCs : styles.basicSansCsLight}>{context?.div.font}</div>
            </div>
          </div>
          <DivSelector/>
        </div>
        <SelectBar     />
        <div className={styles.titleBar} onMouseEnter={() => handleClick("none")}>
          <div className={dark ? styles.titleBarBackground : styles.titleBarBackgroundLight} />
          <div className={dark ? styles.untitled1 : styles.untitled1Light}>Untitled 1 - PongOffice Calc</div>
          <div className={styles.user} onClick={() => navigate("/profile/" + auth.user.login)}>
            <img className={styles.userChild} alt="" src={ image} style={{cursor:"pointer"}}/>
            <span className={dark ?  styles.user1 :  styles.user1Light}>{auth.user.username}</span>
            <Tooltip className={dark ? styles.crossButton : styles.crossButtonLight}title="Log out" arrow>
              <CloseIcon onClick={auth.logout} style={{fontSize:"18px", cursor:"pointer"}}/>
              {/* <img className={styles.crossIcon} alt="" src="/cross.svg" style={{cursor:"pointer", right: "8px"}}/> */}
            </Tooltip>
          </div>
        </div>
      </header>;
}

export default Header;
