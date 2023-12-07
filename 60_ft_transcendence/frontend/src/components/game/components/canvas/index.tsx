import {useEffect, useContext, useRef} from "react";
import gameContext from '../../../../context/gameContext';
import { PageContext } from "../../../../context/PageContext";


export function Canvas(props:any) {
	const {draw, ...rest} = props;
	const canvasRef = useRef<HTMLInputElement>(null);
	const {setGameHeight, setGameWidth } = useContext(gameContext);
	const context = useContext(PageContext);
	if (!context) { throw new Error('useContext must be used within a MyProvider'); }

	useEffect(()=> {
		const canvas = canvasRef.current;
		// @ts-ignore: Object is possibly 'null'.
		const context:CanvasRenderingContext2D = canvas.getContext('2d');
    	let animationFrameId:number;
		const render = () => {
			draw(context);
			animationFrameId = window.requestAnimationFrame(render);	
		}
		render();
		return () => {
			window.cancelAnimationFrame(animationFrameId);
		}
	}, [draw]);

	useEffect(()=> {
		const canvas = canvasRef.current;
		// @ts-ignore: Object is possibly 'null'.
		const context:CanvasRenderingContext2D = canvas.getContext('2d');
		const handleResize = () => {
			const width = canvasRef.current?.parentElement?.clientWidth;
			const height = canvasRef.current?.parentElement?.clientHeight;
			if (typeof(width) !== 'undefined' && typeof(height) !== 'undefined') {
				context.canvas.width = width;
				context.canvas.height = height;
				setGameWidth(width)
				setGameHeight(height)
			}
			else {
				context.canvas.width = 300;
				context.canvas.height = 300 /2;
				setGameWidth(300)
				setGameHeight(300 / 2)
			}
		};
	  
		handleResize();
		window.addEventListener("resize", handleResize);
		return () => {
			window.removeEventListener("resize", handleResize);
		}
	},[setGameWidth, setGameHeight]);

	return (
		<canvas ref={canvasRef} {...rest} style={{position: 'relative', width: '100%', heigth: '100%', cursor:'cell', pointerEvents:'none'}}  />
	);
};