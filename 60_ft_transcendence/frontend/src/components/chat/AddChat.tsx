import { useState, useContext } from 'react';
import ChatContext from '../../context/chatContext';
import AddIcon from '@mui/icons-material/Add';
import { Tooltip } from  "@mui/material";
import "./AddChat.scss";
import { useLogin } from "../../components/user/auth";

export const AddChat = (props: {showSubMenu: string, setShowSubMenu: Function}) => {
	const auth = useLogin();
	const {setNeedToUpdate} = useContext(ChatContext);
	const [chatName, setChatName] = useState('');
	const [password, setPassword] = useState('');
	const [errorMessage, setErrorMessage] = useState('');
	const [chatType, setChatType] = useState('public');

	const toggleForm = () => {
		setErrorMessage('');
		if (props.showSubMenu !== "add") {
	  		props.setShowSubMenu("add");
		} else {
			props.setShowSubMenu("none");
		}
	};

	const onSubmit = async () => {

		let createChatData;
		if (chatName === "") {
			setErrorMessage("Channel Name cannot be left empty")
			return ;
		}
		else if (chatType === "protected by password" && password === "") {
			setErrorMessage("Password needs to be specified")
			return;
		}
		if (password === "") {
			createChatData = {
				login: auth.user.login,
				chatName: chatName,
				chatType: chatType,
				chatPassword: null,
			}
		} else {
			createChatData = {
				login: auth.user.login,
				chatName: chatName,
				chatType: chatType,
				chatPassword: password,
			}
		}
		const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json' ,
			Authorization: auth.getBearer()},
			body: JSON.stringify(createChatData),
		};
		try {
			const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/createChat/`, requestOptions);
			if (!response.ok) {
			  throw new Error('Request failed');
			}
			const data = await response.json();
			if (data) {
				setPassword('');
				setNeedToUpdate("addChat " + data.id.toString());
				setChatName('');
				setPassword('');
				toggleForm();
			}
		}
		catch (error) {
			console.error('Error while creating new channel', error);
		}
	}
	return (
		<div className='addchat'>
			<Tooltip title="Create new channel" arrow>
				<AddIcon onClick={toggleForm}/>
			</Tooltip>
			<div className={props.showSubMenu === "add" ? 'submenu' : 'submenu-hidden'}>
				<div className='form'>
					<div>
						<input
							name="channelNameInput"
							type="text"
							placeholder="Channel Name"
							maxLength={42}
							value={chatName}
							onChange={(e) => setChatName(e.target.value)}
						/>
						<p>Select the type of channel.</p>
						<select
							value={chatType}
							onChange={(e) => setChatType(e.target.value)}
						>
							<option value="public">Public</option>
							<option value="private">Private</option>
							<option value="protected by password">Protected by password</option>
						</select>
						{chatType === 'protected by password' && (
							<input
							name="passwordInput"
							type="password"
							placeholder="Password"
							maxLength={16}
							value={password}
							onChange={(e) => setPassword(e.target.value)}
							/>
						)}
					</div>
					{errorMessage !== "" &&
						<div>
							<p>{errorMessage}</p>
							<hr/>
						</div>}
					<button onClick={onSubmit}>Create</button>
				</div>
			</div>
		</div>
	  );
}
