import "./Chats.scss";
import { WebsocketContext } from "../../context/chatContext";
import { useContext, useEffect, useRef, useState } from 'react';
import ChatContext from "../../context/chatContext";
import { Channel } from './ChatComponent';
import { useLogin } from "../../components/user/auth";

const Chats = () => {

    const socket = useContext(WebsocketContext);
    const auth = useLogin();
	const {allChannels, setAllChannels, blockedUsers} = useContext(ChatContext);

    useEffect(() => {
        socket.emit('chatListOfUser', auth.user.login);
        socket.on("ListOfChatOfUser", (channelsListReceive : Channel[]) => {
            setAllChannels(channelsListReceive);
        });

        return () => {
			socket.off("ListOfChatOfUser");
        }
    }, [setAllChannels, socket, auth.user.login])

    const startRef = useRef<HTMLDivElement>(null);

    useEffect(() => {
        if (allChannels.length > 0) {
            startRef.current?.scrollIntoView({
                behavior: "smooth",
                block: "end",
            });
        }
    }, [allChannels.length]);

    function moveMostRecentUp(chatsOfUser: Channel[]) {

        chatsOfUser.sort((a: Channel, b: Channel) => {
            const aDate = a.dateSend;
            const bDate = b.dateSend;
            if (aDate === null && bDate !== null)
                return 1;
            else if (aDate !== null && bDate === null)
                return -1;
            else if (aDate === null || bDate === null)
                return 0;
            else if (aDate < bDate)
                return 1;
            else if (aDate > bDate)
                return -1;
            return 0;
    })
    return (chatsOfUser);
    }

    return (
        <div className='chats'>
            {allChannels.length === 0 ? (
				<div className='noConversations'>No conversations</div>
				) : (
					<div>
                        <div ref={startRef} />
						{moveMostRecentUp(allChannels).map((channel) => {
                            if (channel.type === "DM" && blockedUsers.find((element) => channel.channelName.indexOf(element.username) !== -1) !== undefined)
                                return (<div key={channel.id}></div>);
                            else {
                                return (<div key={channel.id}><ChannelItem channel={channel}/></div>)
                            }
                        })}
			  		</div>
				)}
        </div>
    )
}

export default Chats;

const ChannelItem = (props: {channel: Channel}) => {

    const socket = useContext(WebsocketContext);
    const auth = useLogin();
    const [image, setImage] = useState("");
    const {activeChannel, setActiveChannel, allChannels, blockedUsers} = useContext(ChatContext);

    function findReceiverName(names: string) {

        let name = names.replace(auth.user.username, "");
        return (name.trim())
    }

    useEffect(() => {
        function findReceiverName2(names: string) {

            let name = names.replace(auth.user.username, "");
            return (name.trim())
        }
        async function fetchAvatar(avatar: string) {
            const res = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/avatar/` + avatar, {
            method: "GET",
            headers: { Authorization: auth.getBearer() },
            });
            const imageBlob = await res.blob();
            const imageObjectURL = URL.createObjectURL(imageBlob);
            setImage(imageObjectURL);
        }
    
        async function fetchUserAvatarByUsername(username: string) {
            const data = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/username/` + username, {
                method: "GET",
                headers: { Authorization: auth.getBearer() },
                });
                const newUser = await data.json();
                if (newUser.avatar) {
                    try {
                        fetchAvatar(newUser.avatar).catch((e) => console.error("Failed to fetch avatar"));
                    } catch (e) {
                        console.error(e);
                    }
                }
        }
		if (props.channel.type === "DM") {
			try {
				fetchUserAvatarByUsername(findReceiverName2(props.channel.channelName));
			} catch (e) {
				console.error(e);
			}
		}
	}, [activeChannel, allChannels, auth, props.channel.type, props.channel.channelName]);

    return (
        <div onClick={() => {
            if (props.channel.id !== activeChannel.id) {
            setActiveChannel(props.channel);
            socket.emit('retrieveMessage', {chatId: props.channel.id, messageToDisplay: 15 })
            }}}>
        <div className={activeChannel.id === props.channel.id ? "userChat active" : "userChat"}>
            {/* {image === "" && props.channel.type === "DM" && <img src={require("../../assets/norminet.jpeg")}  alt="user avatar"/>} */}
            {image === "" && props.channel.type !== "DM" && <img src={require("../../assets/img1.png")}  alt="user avatar"/>}
            {image !== "" && <img src={image}  alt="user avatar"/>}
            <div className='userChatInfo'>
                <h1>{props.channel.type !== "DM" ? props.channel.channelName : findReceiverName(props.channel.channelName)}</h1>
                {blockedUsers.find(element => element.idUser === props.channel.userId) && <p>blocked message</p>}
                {blockedUsers.find(element => element.idUser === props.channel.userId) === undefined && <p>{props.channel.msg ? props.channel.msg : ""}</p>}
            </div>
        </div>
    </div>)
}