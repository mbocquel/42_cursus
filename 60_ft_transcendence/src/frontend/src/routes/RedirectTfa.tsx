import "./Login.scss";
import { useNavigate, useLocation } from "react-router-dom";
import { MouseEvent, useEffect, useState } from "react";
import { useLogin } from "../components/user/auth";

function RedirectTfa() {
  const auth = useLogin();
  const navigate = useNavigate();
  const [tokenOk, setTokenOk] = useState<boolean | undefined>();
  const [key, setKey] = useState<string | undefined>();
  const [tfaToken, setTfaToken] = useState("");
  const [errorMessage, setErrorMessage] = useState("");

  const location = useLocation();
  const queryParams = new URLSearchParams(location.search);
  const param_key = queryParams.get("key");
  if (param_key && param_key !== key) setKey(param_key);

  const getToken = async () => {
    const data = await fetch(
      `http://${process.env.REACT_APP_URL_MACHINE}:4000/ft_auth/tfatoken`,
      {
        mode: "cors",
        method: "POST",
        headers: { "Content-Type": "application/json; charset=utf-8" },
        body: JSON.stringify({ key, tfa_token: tfaToken }),
      }
    );
    const token = await data.json();
    let isOk = false;
    if (!token.message) {
      auth.login(token);
      isOk = true;
    }
    setTokenOk(isOk);
  };

  const handleTfaToken = async (event: MouseEvent<HTMLButtonElement>) => {
    event.preventDefault();
    if (tfaToken) {
      getToken();
    }
  };

  const handleBack = async (event: MouseEvent<HTMLButtonElement>) => {
    event.preventDefault();
    navigate("/login", { replace: true });
  };

  useEffect(() => {}, [key]);

  useEffect(() => {
    if (tokenOk) {
      navigate("/", { replace: true });
    } else if (tokenOk === false) {
      setErrorMessage("sorry bad token");
    }
  }, [tokenOk, navigate]);

  return (
    <div className="login">
      <div className="card">
        <div className="right">
          <h1>Two Factor Authentication</h1>
          <form name="2FA auth">
            <input
              name="2FA auth input"
              type="text"
              placeholder="enter the TFA token"
              value={tfaToken}
              onChange={(e) => setTfaToken(e.target.value)}
            />
            {tokenOk === false ? (
              <div>
                <p className="errorMessage">{errorMessage}</p>
                <button onClick={(e) => handleBack(e)}>back</button></div>
              
            ) : (
              <button
                onClick={(e) => {
                  handleTfaToken(e);
                }}
              >
                submit
              </button>
            )}
          </form>
        </div>
      </div>
    </div>
  );
}

export default RedirectTfa;
