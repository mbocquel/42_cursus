import { useContext } from 'react';
import styles from "./Header.module.css";
import style from "./SelectBar.module.css"
import { PageContext } from '../../context/PageContext';
import { GameStatus } from '../../context/gameContext';

import Divider from '@mui/material/Divider';
import { ThemeProvider, createTheme } from '@mui/material/styles';
import ListItemText from '@mui/material/ListItemText';
import Typography from '@mui/material/Typography';
import ContentCut from '@mui/icons-material/ContentCut';
import ContentCopy from '@mui/icons-material/ContentCopy';
import ContentPaste from '@mui/icons-material/ContentPaste';
import CheckBoxOutlineBlankIcon from '@mui/icons-material/CheckBoxOutlineBlank';
import CheckBoxOutlinedIcon from '@mui/icons-material/CheckBoxOutlined';
import ZoomInIcon from '@mui/icons-material/ZoomIn';
import ZoomOutIcon from '@mui/icons-material/ZoomOut';
import RadioButtonUncheckedIcon from '@mui/icons-material/RadioButtonUnchecked';
import RadioButtonCheckedIcon from '@mui/icons-material/RadioButtonChecked';
import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import ListItemButton from '@mui/material/ListItemButton';
 
import { useLogin } from '../user/auth';
import { gameSocket } from '../game/services/gameSocketService';
import gameContext from '../../context/gameContext';
import { useNavigate } from 'react-router-dom';
import { PageUrlContext } from '../../context/PageUrlContext';



function BasicMenu() {
  const navigate = useNavigate();
  const auth = useLogin();
  function File() {
    const context = useContext(PageContext);
	const { roomId, playerName, setGameStatus, setRoomId, setModeGame, modeGame, gameStatus } = useContext(gameContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
	const pageUrlContext = useContext(PageUrlContext)
	if (!pageUrlContext) { throw new Error('useContext must be used within a MyProvider'); }
    const { updateMenu } = context;
	const {page} = pageUrlContext;

    function print() {
      updateMenu('none');
      window.print();
    }
    function closeTab() {
      window.close();
    }

	function newBasicGame (){
		leaveRoom();
		setModeGame('BASIC');
		gameSocket.emit('match_me', {playerName:playerName, typeGame:'BASIC'});
	}

	function newAdvancedGame() {
		leaveRoom();
		setModeGame('ADVANCED');
		gameSocket.emit('match_me', {playerName:playerName, typeGame:'ADVANCED'});
	}

    const leaveRoom = () => {
      const dataToSend = {
        waitingRoom: (gameStatus === 'IN_WAITING_ROOM'),
        modeGame: modeGame,
        roomId: roomId
      };
      gameSocket.emit("i_am_leaving", dataToSend);
      setGameStatus('NOT_IN_GAME');
      setRoomId(0);
      setModeGame('');
      updateMenuChat('none', chat);
    };

    const newGamePossible = (status: GameStatus): boolean => {
      const statusOk = ['NOT_IN_GAME', 'FINISHED', 'FINISH_BY_FORFAIT'];
      if (statusOk.indexOf(status) !== -1) return (true);
      else return (false);
    };

    const leaveRoomPossible = (status: GameStatus): boolean => {
      return (status !== 'NOT_IN_GAME');
    };
    return (
      <List dense onMouseLeave={() => handleClick("none")} sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '64px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        {page === "Game" && newGamePossible(gameStatus) && <ListItemButton>
 				<ListItemText onClick={() => newBasicGame()}>New Basic Game</ListItemText>
 		</ListItemButton>}
 		{page === "Game" && newGamePossible(gameStatus) && <ListItemButton>
 			<ListItemText onClick={() => newAdvancedGame()}>New Advanced Game</ListItemText>
 		</ListItemButton>}
 		{page === "Game" && !leaveRoomPossible(gameStatus) && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}>
 			<ListItemText>Leave room</ListItemText>
 		</ListItem>}
 		{page === "Game" && !newGamePossible(gameStatus) && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}>
 			<ListItemText>New Basic Game</ListItemText>
 		</ListItem>}
 		{page === "Game" && !newGamePossible(gameStatus) && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}>
 			<ListItemText>New Advanced Game</ListItemText>
 		</ListItem>}
 		{page === "Game" && leaveRoomPossible(gameStatus) && <ListItemButton>
 			<ListItemText onClick={() => leaveRoom()}>Leave Room</ListItemText>
 		</ListItemButton>}
		{page === "Game" && <Divider />}
		{page === "Game" && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}><ListItemText>Game</ListItemText></ListItem>}
		{page !== "Game" && <ListItemButton onClick={() => handlePage("Game")}><ListItemText>Game </ListItemText></ListItemButton>}
		{page === "Profile" && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}><ListItemText>Profile</ListItemText></ListItem>}
        {page !== "Profile" && <ListItemButton onClick={() => handlePage("Profile")}><ListItemText>Profile </ListItemText></ListItemButton>}
		{page === "Data" && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}><ListItemText>Data</ListItemText></ListItem>}
        {page !== "Data" && <ListItemButton onClick={() => handlePage("Data")}><ListItemText>Data </ListItemText></ListItemButton>}
		{page === "Contacts" && <ListItem sx={{ color: 'grey' }} style={{ cursor: 'default' }}><ListItemText>Contacts</ListItemText></ListItem>}
        {page !== "Contacts" && <ListItemButton onClick={() => handlePage("Contacts")}><ListItemText>Contacts </ListItemText></ListItemButton>}
        <Divider />
        <ListItemButton onClick={() => handleChat("Chat")}>{chat === "Chat" ? <CheckBoxOutlinedIcon fontSize="small" /> : <CheckBoxOutlineBlankIcon fontSize="small" />} <ListItemText style={{ position: 'relative', left: '10px' }}>Chat </ListItemText></ListItemButton>
        <Divider />
        <ListItemButton onClick={print}><ListItemText>Print </ListItemText></ListItemButton>
        <ListItemButton onClick={auth.logout}><ListItemText>Logout </ListItemText></ListItemButton>
        {window.opener !== null ? <ListItemButton onClick={closeTab}><ListItemText>Exit PongOffice </ListItemText></ListItemButton>
          : <ListItem ><ListItemText sx={{ color: 'grey' }} style={{ cursor: 'default' }}>Exit PongOffice </ListItemText></ListItem>}
      </List>
    );
  }
  function Edit() {
    const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }

    const { coords, updateCoordsMenu } = context;
    const { coordX, coordY } = coords;

    return (
      <List dense onMouseLeave={() => handleClick("none")} sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '64px', left: '45px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        <ListItem  >
          <ContentCopy sx={{ color: 'grey' }} fontSize="small" />
          <ListItemText sx={{ color: 'grey' }} style={{ position: 'relative', left: '10px' }}>Copy</ListItemText>
          <Typography fontSize="12px" color="text.disabled">Ctrl+C</Typography>
        </ListItem>
        <ListItem >
          <ContentCut sx={{ color: 'grey' }} fontSize="small" />
          <ListItemText sx={{ color: 'grey' }} style={{ position: 'relative', left: '10px' }}>Cut</ListItemText>
          <Typography fontSize="12px" color="text.disabled">Ctrl+X</Typography>
        </ListItem>
        <ListItem >
          <ContentPaste fontSize="small" sx={{ color: 'grey' }} />
          <ListItemText sx={{ color: 'grey' }} style={{ position: 'relative', left: '10px' }}>Paste</ListItemText>
          <Typography fontSize="12px" color="text.disabled">Ctrl+V</Typography>
        </ListItem>
        <Divider />
        <ListItemButton onClick={() => updateCoordsMenu({ coordX: -1, coordY: coordY }, 'none')}><ListItemText>Select Row </ListItemText></ListItemButton>
        <ListItemButton onClick={() => updateCoordsMenu({ coordX: coordX, coordY: -1 }, 'none')}><ListItemText>Select Column </ListItemText></ListItemButton>
        <ListItemButton onClick={() => updateCoordsMenu({ coordX: -1, coordY: -1 }, 'none')}><ListItemText>Select All </ListItemText></ListItemButton>
      </List>
    );
  }
  function View() {
    const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
    const { zoom, updateZoom } = context;
    const increment = 10;
    function add_zoom() {
      if (zoom + increment > 200)
        updateZoom(200);

      else
        updateZoom(zoom + increment);
    }
    function reduce_zoom() {
      if (zoom - increment < 50)
        updateZoom(50);

      else
        updateZoom(zoom - increment);
    }
    const { toolbar, updateToolbar } = context;
    function toggleToolbar() {
      updateToolbar(!toolbar);
    }
    return (
      <List dense onMouseLeave={() => handleClick("none")} sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '64px', left: '90px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        <ListItemButton onClick={toggleToolbar}>{toolbar ? <CheckBoxOutlineBlankIcon fontSize="small" /> : <CheckBoxOutlinedIcon fontSize="small" />} <ListItemText style={{ position: 'relative', left: '10px' }}>Toolbar </ListItemText></ListItemButton>
        <Divider />
        <ListItemButton onClick={add_zoom}><ZoomInIcon /><ListItemText style={{ position: 'relative', left: '10px' }}>Zoom In </ListItemText></ListItemButton>
        <ListItemButton onClick={reduce_zoom}><ZoomOutIcon /><ListItemText style={{ position: 'relative', left: '10px' }}>Zoom Out </ListItemText></ListItemButton>
      </List>
    );
  }
  function Styles() {
    const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
    const { dark, updateDark } = context;
    function lightMode(mode: boolean) {
      handleClick("none");
      updateDark(mode);
    }
    return (
      <List dense onMouseLeave={() => handleClick("none")} sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '64px', left: '135px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        <ListItemButton onClick={() => lightMode(false)}>
          {dark ? <RadioButtonUncheckedIcon style={{ height: '15px' }} /> : <RadioButtonCheckedIcon style={{ height: '15px' }} />}
          <ListItemText style={{ position: 'relative', left: '10px' }}>Light </ListItemText>
        </ListItemButton>
        <ListItemButton onClick={() => lightMode(true)}>
          {dark ? <RadioButtonCheckedIcon style={{ height: '15px' }} /> : <RadioButtonUncheckedIcon style={{ height: '15px' }} />}
          <ListItemText style={{ position: 'relative', left: '10px' }}>Dark </ListItemText>
        </ListItemButton>
      </List>
    );
  }
  function Window() {
    function openNewTab() {
      const isLocalhost = window.location.hostname === 'localhost';
      let url;
      if (isLocalhost)
        url = 'http://localhost:3000/';
      else
        url = 'http://' + process.env.REACT_APP_URL_MACHINE + ':3000/';
      window.open(url, '_blank');
    }
    function closeTab() {
      window.close();
    }
    return (
      <List dense onMouseLeave={() => handleClick("none")} sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '64px', left: '190px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        <ListItemButton onClick={openNewTab}><ListItemText>New Window </ListItemText></ListItemButton>
        {window.opener !== null ? <ListItemButton onClick={closeTab}><ListItemText>Close Window </ListItemText></ListItemButton>
          : <ListItem ><ListItemText sx={{ color: 'grey' }} style={{ cursor: 'default' }}>Close Window </ListItemText></ListItem>}
      </List>
    );
  }
  function Font() {
    const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
    const { div, updateDivMenu } = context;
    function changeFont(newFont: string) {
      updateDivMenu({ font: newFont, bold: div.bold, italic: div.italic, underLined: div.underLined, align: div.align }, "none");
    }
    return (
      <List dense sx={{ color: dark ? 'white' : '#111111', }} style={{ position: 'fixed', top: '100px', left: '135px', width: 200, paddingTop: "0px", paddingBottom: "0px", backgroundColor: dark ? '#2f2f2f' : 'white', border: dark ? '1px solid black' : '1px solid grey' }} >
        <ListItemButton onClick={() => changeFont("Arial")}><ListItemText >Arial </ListItemText></ListItemButton>
        <ListItemButton onClick={() => changeFont("Helvetica")}><ListItemText >Helvetica </ListItemText></ListItemButton>
        <ListItemButton onClick={() => changeFont("Times New Roman")}><ListItemText >Times New Roman </ListItemText ></ListItemButton>
        <ListItemButton onClick={() => changeFont("Lato")}><ListItemText >Lato </ListItemText ></ListItemButton>
      </List>
    );
  }
  function BarSwitch() {
    const context = useContext(PageContext);
    if (!context) {
      throw new Error('useContext must be used within a MyProvider');
    }
    switch (context?.menu) {
      case "File":
        return <File />;
      case "Edit":
        return <Edit />;
      case "View":
        return <View />;
      case "Styles":
        return <Styles />;
      case "Window":
        return <Window />;
      case "Font":
        return <Font />;
      default:
        return;
    }
  }
  const context = useContext(PageContext);
  if (!context) {
    throw new Error('useContext must be used within a MyProvider');
  }
  const { chat, dark, updateMenuChat, updateMenu } = context;
  function handleClick(str: string) {
    updateMenu(str);
  }
  function handlePage(str: string) {
    updateMenuChat("none", chat);
    if (str === "Profile")
      navigate("/" + str.toLowerCase() + "/" + auth.user.login);
    else
      navigate("/" + str.toLowerCase());
  }
  function handleChat(str: string) {
    if (str === chat)
      updateMenuChat("none", "none");
    else
      updateMenuChat("none", str);
  }
  const darkTheme = createTheme({
    palette: {
      text: {
        primary: dark ? '#FFFFFF' : '#FF0000',
        secondary: dark ? '#FFFFFF' : '#FF0000',
        disabled: 'grey',
      },
      action: {
        active: 'white',
        selected: 'white',
        disabledBackground: 'white',
        hover: dark ? '#15539e' : '#2f7ddb',
        disabled: 'white',
      },
      background: {
        default: '#2f2f2f',
        paper: '#2f2f2f',
      },
      divider: '#1a1a1a',
    },
  });
  const lightTheme = createTheme({
    palette: {
      text: {
        primary: '#FF0000',
        secondary: 'white',
        disabled: 'light-grey',
      },
      action: {
        active: 'white',
        selected: 'white',
        disabledBackground: 'black',
        hover: '#2f7ddb',
        disabled: 'black',
      },
      background: {
        default: 'white',
        paper: 'white',
      },
      divider: '#1a1a1a',
    },
  });
  return (
    <ThemeProvider theme={dark ? darkTheme : lightTheme}>
      <div className={dark ? style.file : style.fileLight} style={{ left: '0px', width: '45px' }} onMouseEnter={() => handleClick("File")}>
        <div className={dark ? style.file1 : style.file1Light} style={{ width: '45px' }}>File</div>
      </div>
      <div className={dark ? style.file : style.fileLight} style={{ left: '45px', width: '45px' }} onMouseEnter={() => handleClick("Edit")}>
        <div className={dark ? style.file1 : style.file1Light} style={{ width: '45px', }}>Edit</div>
      </div>
      <div className={dark ? style.file : style.fileLight} style={{ left: '90px', width: '45px' }} onMouseEnter={() => handleClick("View")}>
        <div className={dark ? style.file1 : style.file1Light} style={{ width: '45px', }}>View</div>
      </div>
      <div className={dark ? style.file : style.fileLight} style={{ left: '135px', width: '55px' }} onMouseEnter={() => handleClick("Styles")}>
        <div className={dark ? style.file1 : style.file1Light} style={{ width: '55px', }}>Styles</div>
      </div>
      <div className={dark ? style.file : style.fileLight} style={{ left: '190px', width: '65px' }} onMouseEnter={() => handleClick("Window")}>
        <div className={dark ? style.file1 : style.file1Light} style={{ width: '65px', }}>Window</div>
      </div>
      {BarSwitch()}
    </ThemeProvider>
  );
}

export function SelectBar() {
  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }
  const { menu, dark, updateMenu } = context;

  return (
    <div>
      <div className={styles.textBar}>
        <div className={dark ? styles.textBar1 : styles.textBar1Light} />
        {menu !== 'none' && menu !== 'Font' && <div onMouseEnter={() => updateMenu("none")} style={{ position: 'fixed', width: '100%', height: '100%' }} />}
        <BasicMenu />
      </div>
    </div>);
}
