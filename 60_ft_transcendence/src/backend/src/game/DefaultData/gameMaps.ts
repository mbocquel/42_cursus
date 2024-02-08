import { IgameMaps } from "../Interface/gameMaps.interface"

export const gameMaps :IgameMaps[] = [
	{
		id:1, 
		nbBalls: 2,
		obstacles : [
			{
				posx: 0.15,
				posy:0.10,
				width: 0.20,
				height: 0.20,
				img:'img0.png',
				lives:5
			}, 
			{
				posx: 0.70,
				posy:0.10,
				width: 0.10,
				height: 0.20,
				img:'img1.png',
				lives:5
			}, 
			{
				posx: 0.20, 
				posy:0.70,
				width: 0.10, 
				height: 0.20,
				img:'img2.png', 
				lives:5,
			},
			{
				posx: 0.65,
				posy:0.70,
				width: 0.20,
				height: 0.20,
				img:'img3.png',
				lives:5
			}
		]
	}, 
	{
		id:2, 
		nbBalls: 2,
		obstacles : [
			{
				posx: 0.35,
				posy:0.10,
				width: 0.30,
				height: 0.20,
				img:'img4.png',
				lives:5
			}, 
			{
				posx: 0.35, 
				posy:0.70, 
				width: 0.30,
				height: 0.20,
				img:'img5.png',
				lives:5
			}
		]
	}, 
	{
		id:3, 
		nbBalls: 2,
		obstacles : [
			{
				posx: 0.20,
				posy:0.10, 
				width: 0.10, 
				height: 0.20, 
				img:'img6.png',
				lives:5
			}, 
			{
				posx: 0.65, 
				posy:0.10, 
				width: 0.20, 
				height: 0.20, 
				img:'img7.png',
				lives:5
			},
			{
				posx: 0.15, 
				posy:0.70, 
				width: 0.20, 
				height: 0.20, 
				img:'img8.png', 
				lives:5
			}, 
			{
				posx: 0.70, 
				posy:0.70, 
				width: 0.10,
				height: 0.20,
				img:'img9.png',
				lives:5
			}
		]
	}, 
	{
		id:4, 
		nbBalls: 2,
		obstacles : [
			{
				posx: 0.15, 
				posy:0.20, 
				width: 0.20, 
				height: 0.60, 
				img:'img10.png',
				lives:5
			}, 
			{
				posx: 0.65, 
				posy:0.20, 
				width: 0.20, 
				height: 0.60, 
				img:'img11.png',
				lives:5
			}
		]
	}
]
