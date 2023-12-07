import ChatContext from "../../context/chatContext";
import BlockIcon from "@mui/icons-material/BlockOutlined";
import { Tooltip } from '@mui/material';
import { useContext, useState } from "react";
import "./UnblockUsers.scss"
import { useLogin } from "../user/auth";

export const UnblockUsers = (props: {showSubMenu: string, setShowSubMenu: Function}) => {

    const {blockedUsers, setBlockedUsers} = useContext(ChatContext);
    const [toUnblock, setToUnblock] = useState({idUser: -1, username: "", login: ""});
    const auth = useLogin()

    const toggleForm = () => {
        if (props.showSubMenu !== "blocked") {
            props.setShowSubMenu("blocked");
      } else {
          props.setShowSubMenu("none");
      }
    }

    async function unblock() {
        const data = {
            blockedLogin: toUnblock.login,
            login: auth.user.login,
        };
        const requestOptions = {
            method: 'post',
            headers: { 'Content-Type': 'application/json' ,
            Authorization: auth.getBearer()},
            body: JSON.stringify(data),
        };
        try {
            const response = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/unblockUser/`, requestOptions);
            if (!response.ok)
                throw new Error("Request failed");
            const response2 = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/listOfBlockedUser/${auth.user.login}`, {
                method: "GET",
                headers: { Authorization: auth.getBearer()},
                });
            if (!response2.ok) {
                throw new Error("Request failed");
            }
            const data = await response2.json();
            let result: {idUser: number, username: string, login: string}[] = [];
            if (data) {
                data.map((element: any) => {
                    return result.push(element)
                })
                setBlockedUsers(result);
                toggleForm();
                setToUnblock({idUser: -1, username: "", login: ""});
            }
        }
        catch (error) {
            console.error("Error while unblocking user", error);
        }
    }

    return (
    <div className="blockedUsers">
        <Tooltip title="Blocked users" arrow>
            <BlockIcon onClick={toggleForm}/>
        </Tooltip>
        {props.showSubMenu === "blocked" &&
            <div className="submenu">
                <div className="top">
                {toUnblock.username === "" ? <span>Blocked users</span> : <span>Do you want to unblock {toUnblock.username} ?</span>}
                {toUnblock.username !== "" && <button onClick={() => {unblock()}}>Unblock</button>}
            </div>
            <hr/>
                <div className="blockedList">
                    {blockedUsers.map((element) => {
                        return (<div className="blockedItem" key={element.idUser} onClick={() => {setToUnblock(element)}}><p>{element.username}</p></div>)
                    })}
                </div>
            </div>}
    </div>);
}