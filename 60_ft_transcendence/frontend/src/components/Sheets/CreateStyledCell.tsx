import "./Cells.css";
import "./Contacts/Contacts.css";
import "./Data/Data.css";
import "./Profile/Profile.css";
import "./GameGrid/GameGrid.css"
import { PageContext } from '../../context/PageContext';
import { useContext } from 'react';


type CreateCellProps = {
  coordX: number;
  coordY: number;
  width: number;
  height: number;
  text: string;
  fontSize: number;
  className?: string;
  onClick?: () => void;
};

export function CreateStyledCell({
  coordX, coordY, width, height, text, fontSize, className, onClick // Accept a className as a prop
}: CreateCellProps) {
  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }
  const { scroll, zoom } = context;
  return (
    <div
      key={`x:${coordX} y:${coordY}${height}${width}${text}${className}`}
      style={{
        position: 'absolute',
        top: `${(20 + (zoom - 100) / 8) * (coordX - scroll.scrollX)}px`,
        left: `${0 + (80 + (zoom - 100) / 2) * (coordY - scroll.scrollY)}px`,
        width: `${(80 + (zoom - 100) / 2) * width}px`,
        height: `${(20 + (zoom - 100) / 8) * height}px`,
        fontSize: `${fontSize + ((zoom - 100) / 16)}px`,
        textOverflow: 'ellipsis',
        overflow: 'hidden',
      }}
      className={`cell ${className}`}
      onClick={onClick}
    >
      {text}
    </div>
  );
}
