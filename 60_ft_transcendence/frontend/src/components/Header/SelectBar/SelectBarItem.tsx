import styles from "./SelectBarItem.module.css"
import React, { useContext } from 'react';
import { PageContext } from '../../../context/PageContext';

interface SelectBarProps {
  labelText: string;
  left: string;
  width: string;
}

export function SelectBarItem( { labelText, left, width }  : SelectBarProps) {
  const context = useContext(PageContext);
  if (!context) {
    throw new Error('useContext must be used within a MyProvider');
  }
  const { menu, updateMenu } = context;
  const handleUpdate = () => {
    updateMenu(labelText);
  };

  const divStyle = {
    left: left,
    width: width,
  };
  return (<div className={styles.file} style={divStyle} onTouchMoveCapture={handleUpdate}>
            <div className={styles.file1} style={{width: width}}> {labelText}</div>
          </div>);
}
  

 // function AnotherComponent() {

//     const { data, updateData } = context;
//     const handleUpdate = () => {
//       updateData('Updated shared data');
//     };
//     return (
//       <div>
//         <p>{data}</p>
//         <button onClick={handleUpdate}>Update Data</button>
//       </div>
//     );
//   }
//   export default AnotherComponent;import React, { useContext } from 'react';
  //   export default AnotherComponent;