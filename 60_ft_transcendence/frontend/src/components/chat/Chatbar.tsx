import "./Chatbar.scss"
import { AddChat } from './AddChat';
import { ListChannels } from './ListChannels';
import { useState, useRef, useEffect } from 'react';

const Chatbar = () => {

    const [showSubMenu, setShowSubMenu] = useState("none");
    let menuRef = useRef<HTMLInputElement>(null);

    useEffect(() => {
		const clickHandler = (e: any) => {
			if (!menuRef.current?.contains(e.target)) {
				setShowSubMenu("none");
			}
		};
		document.addEventListener("mousedown", clickHandler);
		return () => {
			document.removeEventListener("mousedown", clickHandler);
		}
	});

    return (
        <div className='chatbar'>
            <span className='chatlogo'></span>
            <div className='icons' ref={menuRef}>
                <ListChannels showSubMenu={showSubMenu} setShowSubMenu={setShowSubMenu}/>
                <AddChat showSubMenu={showSubMenu} setShowSubMenu={setShowSubMenu}/>
            </div>
        </div>
    )
}

export default Chatbar;
