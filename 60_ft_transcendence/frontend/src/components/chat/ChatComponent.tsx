import "./ChatComponent.scss"
import Sidebar from './Sidebar';
import Chat from './Chat'
import { WebsocketContext } from "../../context/chatContext";
import { useState, useEffect, useContext } from 'react';
import ChatContext, {IChatContext} from "../../context/chatContext";
import { useLogin } from "../../components/user/auth";
import ConversationBar from "./ConversationBar";
import { PageContext } from "../../context/PageContext";

export type Channel = {
    id: number;
    channelName: string;
    type : string;
    status: string;
    /*---------LastMessageReceive-------*/
    username: string | null;
    msg: string| null;
    dateSend: Date | null;
    userId: number | null;
    userLogin: string;
}

const ChatComponent = (props: {newDM: string}) => {
    const context = useContext(PageContext);
	if (!context) {
		throw new Error('useContext must be used within a MyProvider');
	}
	const { updateChat } = context;
    const auth = useLogin();
    let DM = false;
    if (props.newDM.search("New DM") !== -1 )
        DM = true;
    const [allChannels, setAllChannels] = useState<Channel[]>([])
    const [blockedUsers, setBlockedUsers] = useState<{idUser: number, username: string, login: string}[]>([]);
    const [needToUpdate, setNeedToUpdate] = useState("");
    const [activeChannel, setActiveChannel] = useState<Channel>({
        id: -1,
        channelName: "PongOffice Chat",
        type: "",
        status: "",
        username: null,
        dateSend: null,
        msg: null,
        userId: null,
        userLogin: "",
    })
    const [allAvatarsURL, setAllAvatarsURL] = useState<{login:string, avatar:string}[]>([]);
    const [allAvatarsImg, setAllAvatarsImg] = useState<{login:string, imageObjectURL:string | undefined}[]>([]);

  const ChatValue: IChatContext = {
    allChannels,
    setAllChannels,
    activeChannel,
    setActiveChannel,
    needToUpdate,
    setNeedToUpdate,
    blockedUsers,
    setBlockedUsers,
    allAvatarsURL,
    setAllAvatarsURL, 
	allAvatarsImg,
	setAllAvatarsImg,
  }

useEffect(() => {
    async function getBlockedUsers() {
        try {
            const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/listOfBlockedUser/${auth.user.login}`, {
                method: "GET",
                headers: { Authorization: auth.getBearer()},
              });
            if (!response.ok) {
                throw new Error("Request failed");
            }
            const data = await response.json();
            let result: {idUser: number, username: string, login: string}[] = [];
            if (data) {
                data.map((element: any) => {
                    result.push(element)
                    return 0;
                })
                return (result);
            }
        }
        catch(error) {
            console.error("Error while getting blocked users", error);
        }
    }
    const fetchBlocked = async () => {
        const result = await getBlockedUsers();
        if (result)
            setBlockedUsers(result)
    }
    fetchBlocked();
  }, [auth]);

  useEffect(() => {
    if (DM === true) {
        updateChat("Chat");
        setNeedToUpdate("newDM " + props.newDM.substring(12));
    }
  }, [allChannels, DM, props.newDM, updateChat])

    return (
        <div className="chatcomponent">
            <div className='container'>
                <ChatContext.Provider value={ChatValue}>
                    < Sidebar />
                    {activeChannel.id > 0 ? <Chat/> : <NoChat message={activeChannel.channelName}/>}
                </ChatContext.Provider>
            </div>
        </div>
    )
}

export default ChatComponent;


const NoChat = (props: {message: string}) => {

    const auth = useLogin();
    const socket = useContext(WebsocketContext);
    const {blockedUsers} = useContext(ChatContext);

    useEffect(() => {

    socket.on('newMessage', (chatHistoryReceive :{msg: string, username: string, login: string, date: Date, id: number, idOfChat:number, serviceMessage: boolean, userId: number}) => {
        if (blockedUsers.find(element => element.idUser === chatHistoryReceive.userId) === undefined)
            socket.emit("chatListOfUser",auth.user.login);
    });
    return () => {
        socket.off('newMessage');
    }
}, [auth.user.login, blockedUsers, socket])

    return (<div>
                <ConversationBar isOwner={false} isAdmin={false}/>
                <div className='noChat'></div>
            </div>);
}
