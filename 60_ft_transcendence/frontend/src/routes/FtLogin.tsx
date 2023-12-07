import "./Login.scss";
import { MouseEvent } from "react";

function Login() {

  const handleSubmit = async (event: MouseEvent<HTMLButtonElement>) => {
    //event.preventDefault();
    window.open(`http://${process.env.REACT_APP_URL_MACHINE}:4000/ft_auth/login`, "_self");
    
  };

  return (
    <div className="login">
      <div className="card">
        <div className="right">
          <button style={{paddingBottom:'10px', paddingTop:'2px'}} onClick={(e) => {handleSubmit(e)}}> Login with <img style={{position:'relative', top:'8px', left:'3px'}} alt="logo42" src="42_Logo.png"></img></button>
        </div>
      </div>
    </div>
  );
}

export default Login;
