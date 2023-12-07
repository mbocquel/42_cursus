import SettingsIcon from '@mui/icons-material/Settings';
import { Tooltip } from '@mui/material';
import "./ChannelSettings.scss"
import { useContext, useState } from 'react';
import ChatContext, {WebsocketContext} from '../../context/chatContext';
import { useLogin } from "../../components/user/auth";


export const ChannelSettings = (props: {showSubMenu: string, setShowSubMenu: Function}) => {

    const socket = useContext(WebsocketContext);
    const {activeChannel} = useContext(ChatContext);
    const [userToInvite, setUserToInvite] = useState('');
	const [password, setPassword] = useState('');
    const [errorMessage, setErrorMessage] = useState("");
    const auth = useLogin();


    const toggleForm = () => {
        if (props.showSubMenu !== "settings") {
            props.setShowSubMenu("settings");
      } else {
          props.setShowSubMenu("none");
      }
    }

    async function updatePassword() {
        if (password === "") {
            setErrorMessage("Password cannot be left empty");
            return;
        }
        const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json',
			Authorization: auth.getBearer()},
			body: JSON.stringify({ password: password, type: "protected by password", chatId: activeChannel.id, login: auth.user.login})
		};
        try {
            const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/changeType/`, requestOptions);
            const data = await response.json();
            if (data) {
                toggleForm();
                setErrorMessage("");
                setPassword("");
                setUserToInvite("");
                const messageData = {
                    username: auth.user.username,
                    login:auth.user.login,
                    content: "This channel is now protected by a new password",
                    serviceMessage: true,
                    idOfChat: activeChannel.id,
                }
                socket.emit('newMessage', messageData);
                activeChannel.type = "protected by password";
            }
            else
                setErrorMessage("Oops, an error occured while updating password")
        }
        catch (error) {
            console.error("Error while updatin channel type", error);
        }
    }

    async function changeChannelType(newType: string) {
        const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json' ,
			Authorization: auth.getBearer()},
			body: JSON.stringify({ password: "", type: newType, chatId: activeChannel.id, login: auth.user.login})
		};
        try {
            const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/changeType/`, requestOptions);
            const data = await response.json();
            if (data){
                toggleForm();
                setErrorMessage("");
                setPassword("");
                setUserToInvite("");
                const messageData = {
                    username: auth.user.username,
                    login:auth.user.login,
                    content: "This channel is now " + newType,
                    serviceMessage: true,
                    idOfChat: activeChannel.id,
                }
                socket.emit('newMessage', messageData);
                activeChannel.type = newType;
            }
            else
                setErrorMessage("Oops, an error occured while changing channel type")
        }
        catch (error) {
            console.error("Error while changing channel type", error);
        }
    }

    async function inviteUserToChannel() { 
        const data = {
				ownerLogin: auth.user.login,
                username: userToInvite,
				chat_id: activeChannel.id,
			};
            const requestOptions = {
            method: 'post',
            headers: { 'Content-Type': 'application/json',
            Authorization: auth.getBearer()},
            body: JSON.stringify(data),
            };
            try {
                const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/inviteUser`, requestOptions);
                const data = await response.json();
                if (data.message !== "ok") {
                    setErrorMessage(data.message);
                } else {
                    setErrorMessage("");
                    setPassword("");
                    toggleForm();
                    const messageData = {
                        username: auth.user.username,
                        login:auth.user.login,
                        content: userToInvite + " has been invited to join the channel",
                        serviceMessage: true,
                        idOfChat: activeChannel.id,
                    }
                    socket.emit('newMessage', messageData);
                    setUserToInvite("");
                }
            }
            catch (error) {
                console.error("Error while inviting user to channel", error);
            }
    }

    return (
        <div className='channelManagement'>
            <Tooltip title="Channel Settings" arrow>
                <SettingsIcon onClick={toggleForm}/>
            </Tooltip>
            {props.showSubMenu === "settings" &&
                <div className='channelSettingsMenu'>
                    <div className="passwordManagement">
                        {activeChannel.type === "protected by password" &&
                            <div>
                                <span>Change channel password</span>
				                <input
                                    name="passwordChangeInput"
					                type="password"
                                    maxLength={16}
					                placeholder='New password'
                                    value={password}
							        onChange={(e) => setPassword(e.target.value)}
					            />
				                <button onClick={updatePassword}>Change Password</button>
                                <div></div>
                                <span>Change channel type</span>
                                <div></div>
                                <button onClick={() => {changeChannelType("private")}}>Private</button>
                                <button onClick={() => {changeChannelType("public")}}>Public</button>
                            </div>
                        }
                        {activeChannel.type === "public" &&
                            <div>
                                <span>Add channel password</span>
                                <input
                                    name="addPasswordInput"
					                type="password"
                                    maxLength={16}
					                placeholder='Password'
                                    value={password}
							        onChange={(e) => setPassword(e.target.value)}
					            />
				                <button onClick={updatePassword}>Add Password</button>
                                <div></div>
                                <span>Change channel type</span>
                                <div></div>
                                <button onClick={() => {changeChannelType("private")}}>Private</button>
                            </div>
                        }
                        {activeChannel.type === "private" &&
                            <div>
                                <span>Add channel password</span>
                                <input
                                    name="addPasswordInput"
					                type="password"
                                    maxLength={16}
					                placeholder='Password'
                                    value={password}
							        onChange={(e) => setPassword(e.target.value)}
					            />
				                <button onClick={updatePassword}>Add Password</button>
                                <div></div>
                                <span>Change channel type</span>
                                <div></div>
                                <button onClick={() => {changeChannelType("public")}}>Public</button>
                            </div>
                        }
			        </div>
                    <hr/>
                    <div className='inviteUsers'>
                        <span>Invite a user to join the channel</span>
                        <input
                            name="inviteUserInput"
					        type="text"
                            maxLength={32}
					       placeholder='Username'
                           value={userToInvite}
							onChange={(e) => setUserToInvite(e.target.value)}
					    />
                        <button onClick={inviteUserToChannel}>Invite</button>
                    </div>
                    {errorMessage !== "" &&
                        <div>
                            <hr/>
                            <p>{errorMessage}</p>
                        </div>
                    }
                </div>
            }
        </div>
    )
}
