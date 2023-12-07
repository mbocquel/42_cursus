export interface IgameMaps {
    id: number;
    nbBalls: number;
    obstacles: {
        posx: number;
        posy: number;
        width: number;
        height: number;
        img: string;
        lives: number;
    }[];
};