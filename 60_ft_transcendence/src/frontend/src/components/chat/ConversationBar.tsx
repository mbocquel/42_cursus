import "./ConversationBar.scss";
import LogoutIcon from '@mui/icons-material/MeetingRoomOutlined';
import CloseIcon from '@mui/icons-material/Close';
import { Tooltip } from "@mui/material";
import ChatContext from '../../context/chatContext'
import { useContext, useState, useRef, useEffect } from "react";
import { ChannelSettings } from "./ChannelSettings";
import { useLogin } from "../../components/user/auth";
import { WebsocketContext } from '../../context/chatContext';
import { PageContext } from "../../context/PageContext";
import { UnblockUsers } from "./UnblockUsers";


const ConversationBar = (props: {isOwner: boolean, isAdmin: boolean}) => {

	const auth = useLogin();
    const {activeChannel, setActiveChannel} = useContext(ChatContext);
    const context = useContext(PageContext);
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
    const { updateChat } = context;
    const [showSubMenu, setShowSubMenu] = useState("none");
    let menuRef = useRef<HTMLInputElement>(null);
    const socket = useContext(WebsocketContext);

    useEffect(() => {
		const clickHandler = (e: any) => {
			if (!menuRef.current?.contains(e.target)) {
				setShowSubMenu("none");
			}
		};
		document.addEventListener("mousedown", clickHandler);
		return () => {
			document.removeEventListener("mousedown", clickHandler);
		}
	});

    async function leaveChannel() {
        const requestOptions = {
			method: 'post',
			headers: { 'Content-Type': 'application/json' ,
			Authorization: auth.getBearer()},
			body: JSON.stringify({ login: auth.user.login, chatId: activeChannel.id})
		};
        try {
            const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/leaveChat/`, requestOptions);
            const data = await response.json();
            let messageData;
            if (data.username) {
                messageData = {
                    username: auth.user.username,
                    login:auth.user.login,
                    content: auth.user.username + " has just left, " + data.username + " now owns this channel",
                    serviceMessage: true,
                    idOfChat: activeChannel.id,
                }
            }
            else {
                messageData = {
                    username: auth.user.username,
                    login:auth.user.login,
                    content: auth.user.username + " has just left",
                    serviceMessage: true,
                    idOfChat: activeChannel.id,
                }
            }
            socket.emit('newMessage', messageData);
            
        }
        catch (error) {
            console.error("Error while leaving channel", error);
        }
    }

    function findReceiverName(names: string) {

        let name = names.replace(auth.user.username, "");
        return (name.trim());
    }
        return (
            <div>
                <div className='chatInfo'>
                    <span>{activeChannel.type !== "DM" ? activeChannel.channelName : findReceiverName(activeChannel.channelName)}</span>
                    {props.isOwner && <span>(owner)</span>}
                    {props.isAdmin && <span>(admin)</span>}
                    <div className="chatIcons">
                        {props.isOwner === true &&
                            <div ref={menuRef}>
                                <ChannelSettings showSubMenu={showSubMenu} setShowSubMenu={setShowSubMenu}/>
                            </div>
                        }
                        {activeChannel.type !== "DM" && activeChannel.id !== -1 &&
                             <Tooltip title="Leave channel" arrow>
                                <LogoutIcon onClick={leaveChannel}/>
                            </Tooltip>
                        }
                        {activeChannel.id === -1 &&
                            <div ref={menuRef}>
                                <UnblockUsers showSubMenu={showSubMenu} setShowSubMenu={setShowSubMenu}/>
                            </div>}
                        {activeChannel.id === -1 && 
                            <Tooltip title="Close chat" arrow>
                                <CloseIcon onClick={() => {updateChat('none')}} />
                            </Tooltip>}
                        {activeChannel.id !== -1 &&
                            <Tooltip title="Close conversation" arrow>
                                <CloseIcon onClick={() => {setActiveChannel({id: -1, channelName: "PongOffice Chat", type: "", status: "", username: null, dateSend: null, msg: null, userId: null, userLogin: ""})}}/>
                            </Tooltip>}
                    </div>
                </div>
            </div>
)}

export default ConversationBar;
