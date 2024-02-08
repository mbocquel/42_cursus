import React, { useEffect, useState, useContext } from 'react';
import { CreateStyledCell } from '../CreateStyledCell';
import { useLogin } from '../../user/auth';
import { PageContext } from '../../../context/PageContext';
import { useNavigate } from 'react-router-dom';

function alternateLine(size: number) {
	const lines = [];
	for (let i = 0; i < size; i++) {
		if (i % 2 !== 0)
			lines.push(
				<CreateStyledCell key={i}
					coordX={4 + i} coordY={1} width={2} height={1}
					text={''} fontSize={0} className={"linePair"} />);
		else
			lines.push(<CreateStyledCell key={i}
				coordX={4 + i} coordY={1} width={2} height={1}
				text={''} fontSize={0} className={"lineUnpair"} />)
	}
	return (<div key={'alternateLines' + size}>{lines}</div>);
}

export function AddLine(props: {scrollX: number, scrollY: number, toolbar: boolean, zoom: number, name: string, login:string, id: number, coordX:number, connected: string, avatar: string, key:string}) {

	const navigate = useNavigate();
		let add;
		let classname;
	if (props.connected === "online" || props.connected === "in Game")
	{
		classname = "status_connected";
		if (props.connected === "in Game")
			add = "in Game";
		else
			add = "online"
	}
	else
	{
		add = "offline"
		classname= "status_unconnected"
	}

	return (
		<div key={props.name}>
			<div key={"1"}><CreateStyledCell
				coordX={props.coordX} coordY={1} width={1} height={1}
				text={props.name} fontSize={12} className={"contacts_button"} onClick={() => navigate(`/profile/${props.login}`)}/>
			</div>
			<div key={"2"}><CreateStyledCell
				coordX={props.coordX} coordY={2} width={1} height={1}
				text={add} fontSize={12} className={classname} />
			</div>

		</div>)
}

type listOfFriend = {
	avatar: string,
	username: string,
	connected: string,
	id: number,
	login: string,
}

export function Contacts(props: { sx: number, sy: number, zoom: number, toolbar: boolean }) {
	const [listOfFriend, setListOfFriend] = useState<listOfFriend[]>([]);
	const [sizeOfList, setSizeOfList] = useState(0);
	const auth = useLogin();
	const context = useContext(PageContext);
	if (!context) {
		throw new Error('useContext must be used within a MyProvider');
	}
	const { updateChat, chat } = context;

	async function sendDM(login: string) {
		if (chat === "none") {
		  const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json',
			Authorization: auth.getBearer()},
			body: JSON.stringify({ idSender: auth.user.id, loginReceiver: login})
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

	  const getUser = async () => {
		  try {
			  const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/friend/listFriends/${auth.user.login}`, {
				  method: 'GET',
				  headers: { Authorization: auth.getBearer()},
			  });
			  if (!response.ok) {
				  console.error(`Error fetching friends: ${response.status}`);
				  return;
			  }

			  const data = await response.json();
			  if (data) {
				  setListOfFriend(data);
			  }
		  } catch (error) {
			  console.error('Error fetching friends:', error);
		  }
	  }
	  async function removeFriend(idOfUser:number) {
		try {
			const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/friend/deleteFriend/${idOfUser}/${auth.user.id}`, {
				method: 'DELETE',
				headers: { Authorization: auth.getBearer()},
			});
			if (!response.ok) {
				console.error(`Error fetching friends: ${response.status}`);
				return ;
			}
		} catch (error) {
			console.error('Error removing friends:', error);
		}
		getUser();
	}

	useEffect(() => {
		const getUser2 = async () => {
			if (auth.user.login)
			{
				try {
					const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/friend/listFriends/${auth.user.login}`, {
						method: 'GET',
						headers: { Authorization: auth.getBearer()},
					});
					if (!response.ok) {
						console.error(`Error fetching friends: ${response.status}`);
						return;
					}
	
					const data = await response.json();
					if (data) {
						setListOfFriend(data);
					}
				} catch (error) {
					console.error('Error fetching friends:', error);
				}
			}
		}
		getUser2();
		const intervalId = setInterval(getUser2, 5000);

		return () => clearInterval(intervalId);
	}, [auth])

	useEffect(() => {
		setSizeOfList(listOfFriend.length);
	}, [listOfFriend])

	return (
		<div key={"contact"}>
			{alternateLine(sizeOfList !== 0 ? sizeOfList : 1)}

			<CreateStyledCell
			coordX={3} coordY={1} width={1} height={1}
			text={"Username"} fontSize={12} className={"title_contacts"} />
			<CreateStyledCell
			coordX={3} coordY={2} width={1} height={1}
			text={"Status"} fontSize={12} className={"title_contacts"} />
			{sizeOfList === 0 && <CreateStyledCell coordX={4} coordY={1} width={2} height={1} text={"You have no friends :("} fontSize={12} className={"no_friends"} />}
			{listOfFriend.map((friend, index) => {
      const variableToPass = 4 + index; // Commence à 4 et s'incrémente à chaque itération
      return (<div key={friend.id}><AddLine scrollX={props.sx} scrollY={props.sy} toolbar={props.toolbar} zoom={props.zoom} name={friend.username} login={friend.login} id={friend.id} coordX={variableToPass} connected={friend.connected} avatar={friend.avatar} key={`${friend.id}`}/>
		<div onClick={()=>{sendDM(friend.login)}}><CreateStyledCell
		  coordX={variableToPass} coordY={3} width={1} height={1} key={"3"}
		  text={'Send DM'} fontSize={12} className={"DM_contacts"} /></div>
		<div key={"removeFriend"} onClick={() =>removeFriend(friend.id)}>
		<CreateStyledCell
			coordX={variableToPass} coordY={4} width={1} height={1} key={"3"}
			text={'Unfriend'} fontSize={12} className={"delete_contacts"} />
		
		</div>
		</div>)})};
		<CreateStyledCell
			coordX={3} coordY={1} width={2} height={sizeOfList === 0 ? 2 : sizeOfList + 1 } key={"4"}
			text={''} fontSize={12} className={"border"} />
	</div>)
}
