import "./EditProfile.scss";
import { Navigate } from "react-router-dom";
import { useLogin } from "../components/user/auth";
import { useEffect, useState, MouseEvent } from "react";

import StringField from "../components/user/StringField";
import EmailField from "../components/user/EmailField";

interface IToSend {
  login: string;
  username?: string;
  email?: string;
  avatar?: string;
}

function EditProfile() {
  const auth = useLogin();

  const [userOk, setUserOk] = useState(false);
  const [newUsername, setNewUsername] = useState(auth.user.username);
  const [newEmail, setNewEmail] = useState(auth.user.email);
  const [newAvatar, setNewAvatar] = useState<File>();
  const [returnPath, setReturnPath] = useState("/");
  const [avatarError, setAvatarError] = useState("");
  const [userError, setUserError] = useState("");

  const handleAvatar = (event: React.ChangeEvent<HTMLInputElement>) => {
    const { files } = event.target;
    const selectedFiles = files as FileList;
    const avatar = selectedFiles?.[0];
    if (avatar) {
      setNewAvatar(avatar);
    } else {
      setNewAvatar(undefined);
    }
  };

  const handleUser = async (event: MouseEvent<HTMLButtonElement>) => {
    event.preventDefault();
    setAvatarError("");
    setUserOk(false);
    let avatarOk = true;
    if (newAvatar) {
      try {
        let formData = new FormData();
        formData.append("file", newAvatar, newAvatar.name);
        const fileData = await fetch(
          `http://${process.env.REACT_APP_URL_MACHINE}:4000/user/editAvatar`,
          {
            method: "POST",
            headers: { Authorization: auth.getBearer() },
            body: formData,
          }
        );
        if (fileData.status === 201) {
          setUserOk(true);
        } else {
          setAvatarError(fileData.statusText);
          avatarOk = false;
        }
      } catch (e) {
        console.error(e);
      }
    }
    if (avatarOk) {
      let tosend: IToSend = { login: auth.user.login };
      if (newUsername) tosend.username = newUsername;
      if (newEmail) tosend.email = newEmail;

      if (tosend.username || tosend.email) {
        try {
          const data = await fetch(
            `http://${process.env.REACT_APP_URL_MACHINE}:4000/user/edit`,
            {
              method: "POST",
              headers: {
                Authorization: auth.getBearer(),
                "Content-Type": "application/json; charset=utf-8",
              },
              body: JSON.stringify(tosend),
            }
          );
          const newUser = await data.json();

          if (newUser) {
            if (newUser.message) {
              setUserOk(false);
              setUserError(newUser.message);
            } else {
              if (newUsername) {
                try {
                  const toSend2 = {
                    OldUsername: auth.user.username,
                    newUsername: newUsername,
                  };
                  await fetch(
                    `http://${process.env.REACT_APP_URL_MACHINE}:4000/chatOption/updateDmName`,
                    {
                      method: "POST",
                      headers: {
                        Authorization: auth.getBearer(),
                        "Content-Type": "application/json; charset=utf-8",
                      },
                      body: JSON.stringify(toSend2),
                    }
                  );
                } catch (error) {
                  console.error(error);
                }
              }
              auth.edit(newUser);
              setUserOk(true);
            }
          }
        } catch (e) {
          console.error(e);
        }
      }
    }
  };

  useEffect(() => {
    if (auth.user.newbie) setReturnPath("/twofa");
  }, [auth]);

  return (
    <div className="register">
      <div className="card">
        <div className="right">
          <h1>Edit profile</h1>
          <h2>{auth.user.login}</h2>
          {auth.user.newbie && (
            <div>
              <h3> Welcome to PongOffice</h3>
              <h3>please setup your profile</h3>
            </div>
          )}
          <form name="formNewUsername">
            <StringField
              placeholder="username"
              value={newUsername}
              onChange={setNewUsername}
              maxLength={10}
            />
            <EmailField value={newEmail} handleValid={setNewEmail} />
            <input
              name="inputNewFile"
              type="file"
              onChange={(e) => {
                handleAvatar(e);
              }}
            />
            {avatarError && <p className="errorMessage">{avatarError}</p>}
            {userError && <p className="errorMessage">{userError}</p>}
            {userOk && <Navigate to={returnPath}></Navigate>}
            <button onClick={handleUser}>Edit</button>
          </form>
        </div>
      </div>
    </div>
  );
}

export default EditProfile;