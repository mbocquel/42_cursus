import "./Error.scss";
import { useNavigate } from "react-router-dom";


function Error404() {
  const navigate = useNavigate();
    

  return (

    <div className="error">
      <div className="card">
        <div className="right">
          <h1>Error 404</h1>
          <h2>Page not found</h2>
          <button onClick={() => navigate("/")}>Back home</button>
          
        </div>
      </div>
    </div>
  );
}

export default Error404;