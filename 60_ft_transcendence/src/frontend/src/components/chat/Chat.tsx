import "./Chat.scss";
import Messages from "./Messages";
import MessageInput from "./MessageInput";
import ChatContext from "../../context/chatContext";
import ConversationBar from "./ConversationBar";
import { useContext, useEffect, useState } from "react";
import { useLogin } from "../user/auth";


const Chat = () => {
    const auth = useLogin();
    const {activeChannel, allAvatarsURL, setAllAvatarsURL, setAllAvatarsImg} = useContext(ChatContext);
    let isDM = false;
    const [isAdmin, setIsAdmin] = useState(false);
    const [isOwner, setIsOwner] = useState(false); 
    if (activeChannel.type === "DM") {
        isDM = true;
    }

    useEffect(()=> {
        async function getAllAvatars() {
            try {
                const res = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/retrieveCommonsChatUser/${activeChannel.id}`, {
                    method: 'GET',
                    headers: { Authorization: auth.getBearer()},
                });
                const data = await res.json();
                setAllAvatarsURL(data);
            } catch (error) {
                console.error('getAllAvatars', error);
            }
        }
        getAllAvatars()
    }, [activeChannel, auth, setAllAvatarsURL]);

    useEffect(()=>{

        async function fetchAvatar(avatar: string) {
			try {
				const res = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/user/avatar/` + avatar, {
				method: "GET",
				headers: { Authorization: auth.getBearer() },
				});
				const imageBlob = await res.blob();
				const imageObjectURL = URL.createObjectURL(imageBlob);
				return (imageObjectURL);
			}
			catch (e) {
				console.error(e)
			}
		}

        async function getImg(){
            let allImg = [];
            for (let i = 0; i < allAvatarsURL.length; i++) {
                let img : string | undefined = '';
                if (allAvatarsURL[i].avatar) { 
                    img = await fetchAvatar(allAvatarsURL[i].avatar);
                }
                const obj = {
                    login: allAvatarsURL[i].login,
                    imageObjectURL:img
                }
                allImg.push(obj);
            }
            setAllAvatarsImg(allImg);
        }


        getImg();
    }, [allAvatarsURL, setAllAvatarsImg, auth])

    useEffect(() => {
        if (activeChannel.status === "admin")
            setIsAdmin(true);
        else
            setIsAdmin(false);
        if (activeChannel.status === "owner")
            setIsOwner(true);
        else
            setIsOwner(false);
    }, [activeChannel]);

    return (
        <div className='chat'>
            <ConversationBar isOwner={isOwner} isAdmin={isAdmin}/>
            <Messages key={activeChannel.id + " " + auth.user.login} chatId={activeChannel.id} isOwner={isOwner} setIsOwner={setIsOwner} isAdmin={isAdmin} setIsAdmin={setIsAdmin} isDM={isDM}/>
            <MessageInput chatId={activeChannel.id}/>
        </div>
    )
}

export default Chat;
