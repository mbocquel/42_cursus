import "./Home.scss";
import { useContext } from "react";
import GameWindow from "../components/GameWindow";
import { WebsocketContext } from "../context/chatContext";


function Home() {
    return (
        <div className="home">
            <div className="container">
                <GameWindow />
            </div>
        </div>
    );
}

export default Home;
