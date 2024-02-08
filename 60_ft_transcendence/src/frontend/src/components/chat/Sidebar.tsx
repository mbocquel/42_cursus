import "./Sidebar.scss"
import Chatbar from './Chatbar';
import Chats from "./Chats";
import { useEffect, useContext } from "react";
import ChatContext from "../../context/chatContext";
import { WebsocketContext } from "../../context/chatContext";
import { useLogin } from "../../components/user/auth";

const Sidebar = () => {

	const socket = useContext(WebsocketContext);
    const auth = useLogin();
    const {activeChannel, allChannels, setActiveChannel, needToUpdate, setNeedToUpdate} = useContext(ChatContext);

	useEffect(() => {
        const id = activeChannel.id;
        if (needToUpdate === "" && id !== -1 && allChannels.find(element => element.id === id) === undefined)
            setActiveChannel({id: -1, channelName: "PongOffice Chat", type: "", status: "", username: null, dateSend: null, msg: null, userId: null, userLogin: ""});
        else if (needToUpdate.indexOf("addChat ") === 0 && allChannels.length > 0) {
            const newChatId = parseInt(needToUpdate.substring(8));
            const newChannel = allChannels.find(element => element.id === newChatId)
            if (newChannel !== undefined) {
                setActiveChannel(newChannel);
                setNeedToUpdate("");
            }
        }
        else if (needToUpdate.indexOf("newDM ") === 0 && allChannels.length > 0) {
            const DMid = parseInt(needToUpdate.substring(6));
            const DMChannel = allChannels.find(element => element.id === DMid)
            if (DMChannel !== undefined) {
                setActiveChannel(DMChannel);
                socket.emit('retrieveMessage', {chatId: DMid, messageToDisplay: 15 })
                setNeedToUpdate("");
            }  
        }
        else if (needToUpdate.indexOf("joinedChat ") === 0  && allChannels.length > 0) {
            const joinedId = parseInt(needToUpdate.substring(11));
            const channelJoined = allChannels.find(element => element.id === joinedId)
            if (channelJoined !== undefined) {
                socket.emit('retrieveMessage', {chatId: joinedId, messageToDisplay: 15 })
                setActiveChannel(channelJoined);
                setNeedToUpdate("");
                const messageData = {
                    username: auth.user.username,
                    login:auth.user.login,
                    content: auth.user.username + " has just joined",
                    serviceMessage: true,
                    idOfChat: channelJoined.id,
                }
                socket.emit('newMessage', messageData);
            }
        }
    }, [allChannels.length, activeChannel, allChannels, auth.user.login, auth.user.username, needToUpdate, setActiveChannel, setNeedToUpdate, socket])

    return (
        <div className='sidebar'>
            <Chatbar/>
            <Chats />
        </div>
    )
}

export default Sidebar;
