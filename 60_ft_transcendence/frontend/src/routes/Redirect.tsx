import "./Login.scss";
import { useNavigate, useLocation } from "react-router-dom";
import { useEffect, useState } from "react";
import { useLogin } from "../components/user/auth";

function Redirect() {
  const auth = useLogin();
  const navigate = useNavigate();
  const [tokenOk, setTokenOk] = useState<boolean | undefined>();
  const [key, setKey] = useState<string | undefined>();

  const location = useLocation();
  const queryParams = new URLSearchParams(location.search);
  const param_key = queryParams.get("key");
  if (param_key && param_key !== key) setKey(param_key);



  useEffect(() => {
	const getToken = async () => {
		const flatkey = JSON.stringify({ key });
		const data = await fetch(`http://${process.env.REACT_APP_URL_MACHINE}:4000/ft_auth/token`, {
		  mode: "cors",
		  method: "POST",
		  headers: { "Content-Type": "application/json; charset=utf-8" },
		  body: flatkey,
		});
		const token = await data.json();
		let isOk = false;
		if (!token.message) {
		  auth.login(token);
		  isOk = true;
		}
		setTokenOk(isOk);
	  };

    if (key) {
      try {
        getToken();
      } catch (e) {
        console.error(e);
      }
    }
  }, [key, auth]);

  useEffect(() => {
    if (tokenOk) {
      navigate("/", { replace: true });
    } else if (tokenOk === false) {
      navigate("/login", { replace: true });
    }
  }, [tokenOk, navigate]);

  return (
    <div className="login">
      <div className="card">
        <div className="left">
          <h1>Log in</h1>
          <p>login in progress, please wait</p>
        </div>
      </div>
    </div>
  );
}

export default Redirect;
