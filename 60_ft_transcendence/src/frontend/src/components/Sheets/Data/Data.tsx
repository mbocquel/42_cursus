import {useState, useEffect } from 'react';
import { useLogin } from '../../user/auth';
import { CreateStyledCell } from '../CreateStyledCell';
import { Link } from 'react-router-dom';

type User = {
  userId: number,        
  userLogin: string,
  userUsername: string,       
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
}

function alternateLine(sx: number, sy: number, zoom: number, size: number) {
	const lines = [];
	for (let i = 0; i < size; i++) {
		if (i % 2 === 0)
			lines.push(
				<CreateStyledCell key={i}
					coordX={4 + i} coordY={1} width={7} height={1}
					text={''} fontSize={0} className={"linePair"} />);
		else
			lines.push(<CreateStyledCell key={i}
				coordX={4 + i} coordY={1} width={7} height={1} 
				text={''} fontSize={0} className={"lineUnpair"} />)
	}
	return (<div key={"alternateLines"}>{lines}</div>);
}

export function Data(props: {sx: number, sy: number, zoom: number}) {

  const [userList, setUserList] = useState<User[]>([]);
  const [listBy, setListBy] = useState("Won");
  const [reverse, setReverse] = useState(1);
  const auth = useLogin();

  useEffect(() => {
		const getUsers = async () => {
			try {
				const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/gameStats`, {
					method: 'GET',
					headers: { Authorization: auth.getBearer()},
				});
				if (!response.ok) {
					console.error(`Error fetching users: ${response.status}`);
					return;
				}

				const data = await response.json();
				if (data) {
					setUserList(data);
				}
			} catch (error) {
				console.error('Error fetching user list:', error);
			}
		}
		getUsers();
	}, [auth])

  function convertSeconds(seconds: number) {
    const hours = Math.floor(seconds / 3600);
    const minutes = Math.floor((seconds % 3600) / 60);
    const remainingSeconds = Math.floor(seconds % 60);
    const hoursStr = (hours > 9 ? hours.toString() : "0" + hours.toString());
    const minutesStr = (minutes > 9 ? minutes.toString() : "0" + minutes.toString());
    const remainingSecStr = (remainingSeconds > 9 ? remainingSeconds.toString() : "0" + remainingSeconds.toString());
  
      return `${hoursStr}:${minutesStr}:${remainingSecStr}`
  }
  
  function AddLine(key: number, coordX:number, user: User, myLogin: string, reverseRank: number, reverseBool: number) {
  
    let classname: string;
    if (myLogin === user.userLogin)
      classname = "dataItemSelf";
    else
      classname = "dataItem";
    let ratio: string;
    if (user.numberGames === 0)
      ratio = "Not yet";
    else
      ratio = (user.numberWon / user.numberGames).toFixed(3).toString();
    const playTime = convertSeconds(user.totalGameDurationInSec);
  
    return (<div key={key}>
            <CreateStyledCell
              coordX={coordX} coordY={1} width={1} height={1}
              text={reverseBool === 1 ? key.toString() : reverseRank.toString()} fontSize={12} className={classname} />
            <Link to={"/profile/" + user.userLogin} style={{textDecoration:"none", color: "#ddddf7"}}>
            <CreateStyledCell
                coordX={coordX} coordY={2} width={1} height={1}
                text={user.userUsername} fontSize={12} className={classname} />
						</Link>
            <CreateStyledCell
              coordX={coordX} coordY={3} width={1} height={1}
              text={user.numberGames.toString()} fontSize={12} className={classname} />
            <CreateStyledCell
              coordX={coordX} coordY={4} width={1} height={1}
              text={user.numberWon.toString()} fontSize={12} className={classname} />
            <CreateStyledCell
              coordX={coordX} coordY={5} width={1} height={1}
              text={user.numberLost.toString()} fontSize={12} className={classname} />
            <CreateStyledCell
              coordX={coordX} coordY={6} width={1} height={1}
              text={ratio} fontSize={12} className={classname} />
            <CreateStyledCell
              coordX={coordX} coordY={7} width={1} height={1}
              text={playTime} fontSize={12} className={classname} />
          </div>)
  }

function sortUsers(users: User[], by: string) {
    if (by === "Won")
      users.sort((a: User, b: User) => {
        if (a.numberWon < b.numberWon)
          return reverse;
        if (a.numberWon > b.numberWon)
          return -reverse;
        return 0;
      });
    else if (by === "Played")
      users.sort((a: User, b: User) => {
        if (a.numberGames < b.numberGames)
          return reverse;
        if (a.numberGames > b.numberGames)
          return -reverse;
        return 0;
      });
    else if (by === "Username")
      users.sort((a: User, b: User)=>{
        if (a.userUsername < b.userUsername)
          return -reverse;
        if (a.userUsername > b.userUsername)
          return reverse;
        return 0;
      });
    else if (by === "Lost")
      users.sort((a: User, b: User)=>{
        if (a.numberLost < b.numberLost)
          return reverse;
        if (a.numberLost > b.numberLost)
          return -reverse;
        return 0;
      });
    else if (by === "Play Time")
      users.sort((a: User, b: User)=>{
        if (a.totalGameDurationInSec < b.totalGameDurationInSec)
          return reverse;
        if (a.totalGameDurationInSec > b.totalGameDurationInSec)
          return -reverse;
        return 0;
      });
    else if (by === "Ratio") 
      users.sort((a: User, b: User)=>{
        let ratioA = 0;
        let ratioB = 0;
        if (a.numberGames !== 0)
          ratioA = (a.numberWon / a.numberGames);
        if (b.numberGames !== 0)
          ratioB = (b.numberWon / b.numberGames);
        if (ratioA < ratioB)
          return reverse;
        if (ratioA > ratioB)
          return -reverse;
        return 0;
      });
  return (users);
}

// async function sendDM(login: string) {
//   if (chat === "none") {
//     const requestOptions = {
//       method: 'post',
//       headers: { 'Content-Type': 'application/json',
//       Authorization: auth.getBearer()},
//       body: JSON.stringify({ idSender: auth.user.id, loginReceiver: login})
//     };
//     try {
//       const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/newPrivateConv`, requestOptions);
//       if (!response.ok) {
//         throw new Error("Request failed");
//       }
//       const data = await response.json();
//       updateChat("Chat New DM " + data.id.toString());
//     }
//     catch (error) {
//       console.error("Error while starting private conversation", error);
//     }
//   } else {
//     updateChat("none");
//   }
// }

  return (
    <div key={"contact"}>
      {alternateLine(props.sx, props.sy, props.zoom, userList.length)}
      <div><CreateStyledCell
      coordX={3} coordY={1} width={1} height={1}
      text={"Rank"} fontSize={12} className={"title_data"} /></div>
      <div  onClick={()=>{listBy === "Username" ? setReverse(-reverse) : setReverse(1);setListBy("Username")}}><CreateStyledCell
        coordX={3} coordY={2} width={1} height={1}
        text={"Username"} fontSize={12} className={"title_data"} /></div>
      <div onClick={()=>{listBy === "Played" ? setReverse(-reverse) : setReverse(1);setListBy("Played")}}><CreateStyledCell
        coordX={3} coordY={3} width={1} height={1}
        text={"Played"} fontSize={12} className={"title_data"} /></div>
      <div onClick={()=>{listBy === "Won" ? setReverse(-reverse) : setReverse(1);setListBy("Won")}}><CreateStyledCell
        coordX={3} coordY={4} width={1} height={1}
        text={"Won"} fontSize={12} className={"title_data"} /></div>
      <div onClick={()=>{listBy === "Lost" ? setReverse(-reverse) : setReverse(1);setListBy("Lost")}}><CreateStyledCell
        coordX={3} coordY={5} width={1} height={1}
        text={"Lost"} fontSize={12} className={"title_data"} /></div>
      <div onClick={()=>{listBy === "Ratio" ? setReverse(-reverse) : setReverse(1);setListBy("Ratio")}}><CreateStyledCell
        coordX={3} coordY={6} width={1} height={1}
        text={"Ratio"} fontSize={12} className={"title_data"} /></div>
      <div onClick={()=>{listBy === "Play Time" ? setReverse(-reverse) : setReverse(1);setListBy("Play Time")}}><CreateStyledCell
        coordX={3} coordY={7} width={1} height={1}
        text={"Play Time"} fontSize={12} className={"title_data"} /></div>
      {sortUsers(userList, listBy).map((user, index) => {
        const variableToPass = 4 + index;
        return AddLine(index + 1, variableToPass, user , auth.user.login, userList.length - index, reverse)
      })}
      <CreateStyledCell coordX={3} coordY={1} width={7} height={userList.length + 1} text={''} fontSize={0} className={'border'}/>
     </div>);
}
