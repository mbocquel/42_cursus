import styles from "./GameBar.module.css";
import { useContext } from "react";
import { PageContext } from "../../context/PageContext";

export function GameBar () {
	const context = useContext(PageContext);
	if (!context) { throw new Error('useContext must be used within a MyProvider'); }
	const { game, dark } = context;
    return (
    <div className={dark ? styles.bar : styles.barLight}>
        <div className={styles.leftText}>{game.player1} : {game.points1} points</div>
        <div className={styles.rightText}>{game.player2} : {game.points2} points</div>
    </div>)
}
