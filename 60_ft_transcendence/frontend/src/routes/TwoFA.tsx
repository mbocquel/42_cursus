import "./TwoFa.scss";
import { useState, MouseEvent } from "react";
import { useLogin } from "../components/user/auth";
import TwoFAToken from "../components/user/TwoFAToken";
import { useNavigate } from "react-router-dom";

function Twofa() {
  const auth = useLogin();
  const navigate = useNavigate();

  let tmp = auth.user.username;
  if (tmp === null) tmp = "";

  const [qrcode, setQrcode] = useState();

  const handleTfa = async (event: MouseEvent<HTMLButtonElement>) => {
    event.preventDefault();
    try {
      const data = await fetch(
        `http://${process.env.REACT_APP_URL_MACHINE}:4000/twofa/setup`,
        {
          mode: "cors",
          method: "GET",
          headers: {
            Authorization: auth.getBearer(),
          },
        }
      );
      if (data.status === 200) {
        const qr_url = await data.json();
        setQrcode(qr_url.qrcode_url);
      }
    } catch (e) {
      console.error(e);
    }
  };

  const handleCancel = async (event: MouseEvent<HTMLButtonElement>) => {
    event.preventDefault();
    const data = await fetch(
      `http://${process.env.REACT_APP_URL_MACHINE}:4000/twofa/cancel`,
      {
        mode: "cors",
        method: "GET",
        headers: {
          Authorization: auth.getBearer(),
        },
      }
    );
    if (data.status === 200) {
      const newUser = await data.json();
      auth.edit(newUser);
      navigate("/", { replace: true });
    }
  };

  const handleSkip = async () => {
    navigate("/", { replace: true });
  };

  return (
    <div className="register">
      <div className="card">
        <div className="right">
          <h1>Two Factors Authentication</h1>
          <h2>{auth.user.login}</h2>
          {!qrcode && (
            <div>
              <form name="2FAForm">
                {!auth.user.tfa_activated && (
                  <button onClick={handleTfa}>setup </button>
                )}
                {auth.user.tfa_activated && (
                  <button onClick={handleCancel}>remove</button>
                )}
              </form>
              <button onClick={handleSkip}>skip</button>
            </div>
          )}

          {qrcode && <img src={qrcode} alt="QR" />}
          {qrcode && <TwoFAToken />}
        </div>
      </div>
    </div>
  );
}

export default Twofa;
