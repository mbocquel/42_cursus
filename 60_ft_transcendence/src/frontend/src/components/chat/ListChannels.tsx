import MenuIcon from '@mui/icons-material/Menu';
import { Tooltip } from '@mui/material';
import "./ListChannels.scss"
import { useContext, useState, useEffect } from 'react';
import { WebsocketContext } from '../../context/chatContext';
import chatContext from '../../context/chatContext';
import { useLogin } from "../../components/user/auth";

type ChannelToJoin = {
	id : number;
	name: string;
	owner: string;
	type: string;
	password: null | string;
}

export const ListChannels = (props: {showSubMenu: string, setShowSubMenu: Function}) => {
	const auth = useLogin();
    const socket = useContext(WebsocketContext);
	const {allChannels, setNeedToUpdate} = useContext(chatContext);
	const [password, setPassword] = useState('');
	const [chanToJoin, setChanToJoin] = useState<ChannelToJoin>({id: -1, name: "", owner: "", type: "", password: null});
	const [availableChannels, setAvailableChannels] = useState<ChannelToJoin[]>([{id: -1, name: "", owner: "", type: "", password: null}]);
	const [errorMessage, setErrorMessage] = useState("");

	const DealWithIdChat = async () => {
		const returnValue = await SendIdChat();
		if (returnValue === -3) {
			setErrorMessage("Oops, something wrong happened")
			setChanToJoin({id: -1, name: "", owner: "", type: "", password: null})
		} else if (returnValue === -2) {
			setErrorMessage("You cannot join this chat because you were banned");
			setChanToJoin({id: -1, name: "", owner: "", type: "", password: null})
		} else if (returnValue === -1) {
			setErrorMessage("Wrong password");
			setChanToJoin({id: -1, name: "", owner: "", type: "", password: null})
		} else {
			setErrorMessage("");
			setNeedToUpdate("joinedChat " + chanToJoin.id.toString());
			toggleForm();

		}
	  }

	  const SendIdChat = async () => {
		let messageData;
		if (chanToJoin.type === "protected by password") {
			if (password === "")
				return (-1);
			messageData = {
				login: auth.user.login,
				chat_id: chanToJoin.id,
				password: password,
		  };
		}
		else {
			messageData = {
				login: auth.user.login,
				chat_id: chanToJoin.id,
				password: null,
			  };
		}
		const requestOptions = {
		  method: 'post',
		  headers: { 'Content-Type': 'application/json' ,
		  Authorization: auth.getBearer()},
		  body: JSON.stringify(messageData),
		};
		try {
		  const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/joinChat/`, requestOptions);
		  if (!response.ok) {
			throw new Error('Request failed');
		  }
		  const data = await response.json();
		  setPassword('');
		  return data;
		} catch (error) {
		  console.error('Error:', error);
		  return -3;
		}
	  }

	useEffect(() => {

		setErrorMessage("");
		setChanToJoin({id: -1, name: "", owner: "", type: "", password: null});
		if (props.showSubMenu !== "list")
			return;
		socket.emit('chatList');
		socket.on("chatList", (available: ChannelToJoin[]) => {
			setAvailableChannels(available);
		});

		return () => {
			socket.off("chatList");
		}
	}, [props.showSubMenu, socket]);

    const toggleForm = () => {
        if (props.showSubMenu !== "list") {
            props.setShowSubMenu("list");
      } else {
          props.setShowSubMenu("none");
      }
    }

	function isNotAlreadyIn(chan: ChannelToJoin) {
		if (allChannels.find((element) => element.id === chan.id)) {
			return (false);
		}
		return (true);
	}

    return (
    <div className='listchannels'>
        <Tooltip title="List available channels" arrow>
            <MenuIcon onClick={toggleForm}/>
        </Tooltip>
		{props.showSubMenu === "list" &&
        <div className="submenu">
			<div className="top">
				<div className="joinInfo">
				{chanToJoin.id === -1 ? <span>Choose a channel to join</span> : <span>Do you want to join "{chanToJoin.name}" ?</span>}
				{chanToJoin.type === "protected by password" && <input
					name="enterPasswordInput"
					type="password"
					placeholder='Password'
					value={password}
					maxLength={16}
					onChange={(e) => setPassword(e.target.value)}
					/>}
				</div>
				{ chanToJoin.id !== -1 && <button onClick={() => {DealWithIdChat()}}>Join</button>}
			</div>
			<hr/>
			{errorMessage !== "" &&
			<div>
				<p>{errorMessage}</p>
				<hr/>
			</div>}
            {availableChannels.filter(isNotAlreadyIn).map((chan) => {return (
			<div className="channelItem" key={chan.id}>
				{chan.type === "protected by password" ?
				<p onClick={() => {setChanToJoin(chan)}}>{chan.name + " (password)"}</p> :
				<p onClick={() => {setChanToJoin(chan)}}>{chan.name}</p>}
			</div>
			)
			})}
        </div>}
    </div>
    );
}
