import { Navigate, useNavigate } from "react-router-dom";
import { useLocation } from 'react-router-dom';
import { useState } from "react";
import { useLogin } from "../../user/auth";
import { PageContext } from "../../../context/PageContext";
import { useContext, useRef, useEffect } from "react";
import { CreateStyledCell } from "../CreateStyledCell";
import { useParams } from "react-router-dom";

function alternateLine(size: number) {
  const lines = [];
  for (let i = 0; i < size; i++) {
    if (i % 2 !== 0)
      lines.push(
        <CreateStyledCell key={i}
          coordX={15 + i} coordY={1} width={8} height={1}
          text={''} fontSize={0} className={"linePair"} />);
    else
      lines.push(<CreateStyledCell key={i}
        coordX={15 + i} coordY={1} width={8} height={1}
        text={''} fontSize={0} className={"lineUnpair"} />)
  }
  return (<div key={'alternateLines' + size}>{lines}</div>);
}

export function AddLine(props: {
  game: { id: number; type: string; game_status: string | null; won: boolean; opponentId: any; opponentUserName: any; opponentLogin: any; myScore: number | null; myOpponentScore: number | null; date_begin: Date; durationInSec: number | undefined; },
  index: number
}) {
  const navigate = useNavigate();
  return (
    <div key={props.index}>
      <CreateStyledCell coordX={(props.index)} coordY={7} width={1} height={1} text={props.game.type} fontSize={12} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={2} width={1} height={1} text={(props.game.game_status === 'FINISH_BY_FORFAIT' ? 'FORFAIT' : props.game.game_status) || ''} fontSize={12} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={3} width={1} height={1} text={props.game.won ? "WIN" : "LOST"} fontSize={12} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={4} width={1} height={1} text={props.game.opponentUserName.toString()} fontSize={12} className={"dataItemButton"} onClick={() => navigate(`/profile/${props.game.opponentLogin}`)} />
      <CreateStyledCell coordX={(props.index)} coordY={5} width={1} height={1} text={props.game.myScore?.toString() || ''} fontSize={12} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={6} width={1} height={1} text={props.game.myOpponentScore?.toString() || ''} fontSize={12} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={1} width={1} height={1} text={props.game.date_begin.toString().slice(0, 10)} fontSize={11} className={"dataItem"} />
      <CreateStyledCell coordX={(props.index)} coordY={8} width={1} height={1} text={Math.floor(props.game.durationInSec || 0)?.toString() + 's'} fontSize={12} className={"dataItem"} />
    </div>);
}

function Profile() {

  const { login_url } = useParams();
  const [sizeOfList, setSizeOfList] = useState(0);
  const [twoFa, setTwoFa] = useState(false);

  const empty_user = {
    id: 0,
    username: "",
    first_name: "",
    last_name: "",
    login: "",
    email: "",
    avatar: "",
    role: "",
    password: "",
    game_won: 0,
    game_lost: 0,
    game_played: 0,
  };

  interface statObject {
    userId: number,
    userLogin: string,
    userUsername: string | null,
    numberGames: number,
    numberGamesBasic: number,
    numberGamesAdvanced: number,
    numberWon: number,
    numberLost: number,
    numberWonBasic: number,
    numberLostBasic: number,
    numberWonAdvanced: number,
    numberLostAdvanced: number,
    totalGameDurationInSec: number,
    totalGameDurationBasicInSec: number,
    totalGameDurationAdvancedInSec: number,
    games?: {
      id: number;
      type: string;
      game_status: string | null;
      won: boolean;
      opponentId: any;
      opponentUserName: any;
      opponentLogin: any;
      myScore: number | null;
      myOpponentScore: number | null;
      date_begin: Date;
      durationInSec: number | undefined;
    }[]
  }

  const empty_gameUser: statObject = {
    userId: 0,
    userLogin: '',
    userUsername: '',
    numberGames: 0,
    numberGamesBasic: 0,
    numberGamesAdvanced: 0,
    numberWon: 0,
    numberLost: 0,
    numberWonBasic: 0,
    numberLostBasic: 0,
    numberWonAdvanced: 0,
    numberLostAdvanced: 0,
    totalGameDurationInSec: 0,
    totalGameDurationBasicInSec: 0,
    totalGameDurationAdvancedInSec: 0,
    games: [],
  }
  const location = useLocation();
  const [image, setImage] = useState("");
  const [friend, setFriend] = useState(false);
  const auth = useLogin();
  const [user, setUser] = useState(empty_user);
  const [gameUser, setGameUser] = useState(empty_gameUser);
  const [redirect, setRedirect] = useState(false);




  //RESIZE WINDOW
  const [edit, setEdit] = useState(false);

  const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
	const { scroll, toolbar, zoom, updateChat, chat } = context;
	const windowWidthRef = useRef(window.innerWidth);
	  const forceUpdate = useForceUpdate();


  function calculate_edit_Y() {
    const result = Math.floor((windowWidthRef.current - (windowWidthRef.current / 100 * 2 + 31)) / (80 + (zoom - 100) / 2) - 1);
    return (result > 4 ? result : 5);
  }

  function isAuth() {
    return (user.login === auth.user.login || (!login_url));
  }

  useEffect(() => {
    async function checkIfAlreadyFriend() {
      try {
        const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/friend/${auth.user.login}/${user.login}/isMyFriend`, {
          method: "GET",
          headers: { Authorization: auth.getBearer()},
          });
        if (!response.ok) {
          throw new Error("Request failed");
        }
        const data = await response.json();
        if (data)
          setFriend(data);
      }
      catch(error) {
        console.error("Error while checking if user is friend", error);
      }
    }
    if (user.id !== 0)
      checkIfAlreadyFriend();
  },[user, auth, location.pathname]);

  useEffect(() => {
    setSizeOfList(gameUser?.games?.length || 0);
  }, [gameUser])

  useEffect(() => {
	let myuser = auth.user.login;
	if (login_url) {
		myuser = login_url; 
	}
    const fetchUser = async (login: string) => {
      const bearer = auth.getBearer();
      const data = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/` + login, {
        method: "GET",
        headers: { Authorization: bearer },
      });
      const newUser = await data.json();
      if (newUser.message) {
        setRedirect(true);
      }
      else {
        setUser(newUser);
      }
    };
	try {
		if (!login_url)
		{
			myuser = auth.user.login
		}
		if (myuser !== "") {
			fetchUser(myuser);
		}
  	} catch (e) {
	console.error(e);
  	}
  }, [auth, login_url, user.login, location.pathname]);

  useEffect(() => {

    const fetchImage = async () => {
      const bearer = auth.getBearer();
      const res = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/avatar/` + user.avatar, {
        method: "GET",
        headers: { Authorization: bearer },
      });
      const imageBlob = await res.blob();
      const imageObjectURL = URL.createObjectURL(imageBlob);
      setImage(imageObjectURL);
    };
    const fetchGameUser = async () => {
      try {
        const bearer = auth.getBearer();
        const data = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/gameStats/login/${user.login}`, {
          method: "GET",
          headers: { Authorization: bearer },
        });
        const newUser = await data.json();
        if (data) {
          setGameUser(newUser);
        }
      }
      catch (e) {
		console.error(e);
	  }
    }
    if (user.avatar) {
      try {
        fetchImage();
      } catch (e) {
        console.error(e);
      }
    }
	  else {
		  setImage("");
    }
    try {
      if (user.login)
        fetchGameUser();
    } catch (e) {
      console.error(e);
    }
  }, [user, login_url, auth, location.pathname]);

  useEffect(() => {
    const handleResize = () => {
      windowWidthRef.current = window.innerWidth;
      forceUpdate();
    };
    window.addEventListener('resize', handleResize);
    return () => {
      window.removeEventListener('resize', handleResize);
    };
  }, [forceUpdate]);

  const fetchUser = async (login: string) => {
    const bearer = auth.getBearer();
    const data = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/` + login, {
      method: "GET",
      headers: { Authorization: bearer },
    });
    const newUser = await data.json();
    if (newUser.message) {
      setRedirect(true);
    }
    else {
      setUser(newUser);
    }
  };

  async function addToFriends(login:string) {
		const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json',
			Authorization: auth.getBearer()},
			body: JSON.stringify({ login: auth.user.login, friendToAdd: login})
		};
		try {
			const test = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/friend/addFriend/`, requestOptions)
      if (test)
        await fetchUser(login);
    }
		catch (error) {
			console.error("Error while adding friend", error);
		}
	}

  async function sendDM(login: string) {
    if (chat === "none") {
      const requestOptions = {
        method: 'post',
        headers: {
          'Content-Type': 'application/json',
          Authorization: auth.getBearer()
        },
        body: JSON.stringify({ idSender: auth.user.id, loginReceiver: login })
      };
      try {
        const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/newPrivateConv`, requestOptions);
        if (!response.ok) {
          throw new Error("Request failed");
        }
        const data = await response.json();
        updateChat("Chat New DM " + data.id.toString());
      }
      catch (error) {
        console.error("Error while starting private conversation", error);
      }
    } else {
      updateChat("none");
    }
  }

  async function setEditAndHideChat() {
	setEdit(true);
	updateChat("none");
  }

  async function setTwoFaAndHideChat() {
    setTwoFa(true);
    updateChat("none");
  }

  return (
    <div key={"profile"} style={{
      position: 'fixed',
      color: 'black',
      backgroundColor: 'red',
      top: toolbar ? '89px' : '166px'
    }}>
      <img src={image }
        alt="" className="profilePic"
        key={"image"}
        style={{
          width: `${(80 + (zoom - 100) / 2) * 1}px`,
          height: `${(20 + (zoom - 100) / 8) * 3}px`,
          objectFit: 'cover',
          position: 'absolute',
          top: `${(20 + (zoom - 100) / 8) * (3 - scroll.scrollX)}px`,
          left: `${0 + (80 + (zoom - 100) / 2) * (4 - scroll.scrollY)}px`,
          border: '2px solid black'
        }} />
      <CreateStyledCell coordX={3} coordY={1} width={1} height={1} text={"Username"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={3} coordY={2} width={isAuth() ? 2 : 1} height={1} text={user.username} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={4} coordY={1} width={1} height={1} text={"Login"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={4} coordY={2} width={isAuth() ? 2 : 1} height={1} text={user.login} className={"data_profile"} fontSize={12} />
      {(isAuth() || !login_url) && <CreateStyledCell coordX={5} coordY={1} width={1} height={1} text={"email"} className={"title_profile"} fontSize={12} />}
      {(isAuth() || !login_url) && <CreateStyledCell coordX={5} coordY={2} width={2} height={1} text={user.email} className={"data_profile"} fontSize={12} />}
      <CreateStyledCell coordX={3} coordY={1} width={isAuth() ? 3 : 2} height={isAuth() ? 3 : 2} text={""} className={"border_profile"} fontSize={12} />

      <CreateStyledCell coordX={7} coordY={2} width={1} height={1} text={"Basic"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={7} coordY={3} width={1} height={1} text={"Advanced"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={7} coordY={4} width={1} height={1} text={"Total"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={8} coordY={1} width={1} height={1} text={"Games"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={8} coordY={2} width={1} height={1} text={`${gameUser.numberGamesBasic}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={8} coordY={3} width={1} height={1} text={`${gameUser.numberGamesAdvanced}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={8} coordY={4} width={1} height={1} text={`${gameUser.numberGames}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={9} coordY={1} width={1} height={1} text={"Wins"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={9} coordY={2} width={1} height={1} text={`${gameUser.numberWonBasic}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={9} coordY={3} width={1} height={1} text={`${gameUser.numberWonAdvanced}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={9} coordY={4} width={1} height={1} text={`${gameUser.numberWon}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={10} coordY={1} width={1} height={1} text={"Losses"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={10} coordY={2} width={1} height={1} text={`${gameUser.numberLostBasic}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={10} coordY={3} width={1} height={1} text={`${gameUser.numberLostAdvanced}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={10} coordY={4} width={1} height={1} text={`${gameUser.numberLost}`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={11} coordY={1} width={1} height={1} text={"Sec. in game"} className={"title_profile"} fontSize={12} />
      <CreateStyledCell coordX={11} coordY={2} width={1} height={1} text={`${Math.floor(gameUser.totalGameDurationBasicInSec)}s`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={11} coordY={3} width={1} height={1} text={`${Math.floor(gameUser.totalGameDurationAdvancedInSec)}s`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={11} coordY={4} width={1} height={1} text={`${Math.floor(gameUser.totalGameDurationInSec)}s`} className={"data_profile"} fontSize={12} />
      <CreateStyledCell coordX={7} coordY={2} width={3} height={5} text={""} className={"border_profile"} fontSize={12} />
      <CreateStyledCell coordX={8} coordY={1} width={4} height={4} text={""} className={"border_profile"} fontSize={12} />


      <CreateStyledCell coordX={14} coordY={7} width={1} height={1} text={"Type"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={2} width={1} height={1} text={"Status"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={3} width={1} height={1} text={"Result"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={4} width={1} height={1} text={"Opponent"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={5} width={1} height={1} text={"Score"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={6} width={1} height={1} text={"Opponent score"} className={"title_contacts"} fontSize={9} />
      <CreateStyledCell coordX={14} coordY={1} width={1} height={1} text={"Date"} className={"title_contacts"} fontSize={12} />
      <CreateStyledCell coordX={14} coordY={8} width={1} height={1} text={"Duration"} className={"title_contacts"} fontSize={12} />
      {alternateLine(sizeOfList === 0 ? 1 : sizeOfList)}
      {gameUser.games?.map((game, index) => {
        const variableToPass = 15 + index;
        return (<AddLine game={game} index={variableToPass} key={index} />);
      })}
      {sizeOfList === 0 && <CreateStyledCell coordX={15} coordY={1} width={8} height={1} text={"No game"} fontSize={12} className={"dataItem"} />}
      <CreateStyledCell coordX={14} coordY={1} width={8} height={sizeOfList === 0 ? 2 : sizeOfList + 1} text={""} className={"border"} fontSize={12} />
      {isAuth() && <CreateStyledCell coordX={1} coordY={calculate_edit_Y()} width={1} height={1} text={"Edit Profile"} className={"edit_profile"} fontSize={12} onClick={setEditAndHideChat} />}
      {isAuth() && <CreateStyledCell coordX={2} coordY={calculate_edit_Y()} width={1} height={1} text={"TwoFa Settings"} className={"edit_profile"} fontSize={12} onClick={setTwoFaAndHideChat} />}
      {twoFa && <Navigate to="/twofa"/>}
      {(edit || auth.user.newbie) && <Navigate to="/edit"/>}
      {redirect && <Navigate to ={"/profile/" + auth.user.login}/>}
      {!isAuth() &&
      <div>
        <CreateStyledCell coordX={1} coordY={calculate_edit_Y()} width={1} height={1} text={"Send DM"} className={"edit_profile"} fontSize={12} onClick={() => sendDM(user.login)} />
        {friend === false && <CreateStyledCell coordX={2} coordY={calculate_edit_Y()} width={1} height={1} text={"Add friend"} className={"edit_profile"} fontSize={12} onClick={() => addToFriends(user.login)} />}
      </div>}
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
export default Profile;