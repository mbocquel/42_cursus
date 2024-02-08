import FormatAlignLeftIcon from '@mui/icons-material/FormatAlignLeft';
import FormatAlignCenterIcon from '@mui/icons-material/FormatAlignCenter';
import FormatAlignRightIcon from '@mui/icons-material/FormatAlignRight';
import FormatAlignJustifyIcon from '@mui/icons-material/FormatAlignJustify';
import FormatBoldIcon from '@mui/icons-material/FormatBold';
import FormatItalicIcon from '@mui/icons-material/FormatItalic';
import FormatUnderlinedIcon from '@mui/icons-material/FormatUnderlined';
import { PageContext } from '../../context/PageContext';
import { useContext } from 'react';
import styles from './DivSelector.module.css'

export function DivSelector() {
  
  const context = useContext(PageContext);
  if (!context) { throw new Error('useContext must be used within a MyProvider'); }
  const { updateDiv } = context;
  return (
    <div style={{
            width:'350px',
            height:'35px',
            position:'fixed',
            top: context?.toolbar ? '0px': '74px',
            left: '170px',
            display: 'flex',
            color: context?.dark ? 'white': '#484848'}}>
        <div className={styles.button}>
            <FormatAlignLeftIcon onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: context?.div.italic, underLined: context?.div.underLined, align: "left",})} 
                                 style={{color: context?.div.align === 'left' ? (context?.dark ? 'white': '#484848') : 'grey'}}
                                 className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatAlignCenterIcon  onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: context?.div.italic, underLined: context?.div.underLined, align: "center",})}
                                    style={{color: context?.div.align === 'center' ? (context?.dark ? 'white': '#484848') : 'grey'}}
                                    className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatAlignRightIcon  onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: context?.div.italic, underLined: context?.div.underLined, align: "right",})}
                                   style={{color: context?.div.align === 'right' ? (context?.dark ? 'white': '#484848') : 'grey'}}
                                   className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatAlignJustifyIcon  onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: context?.div.italic, underLined: context?.div.underLined, align: "justify",})}
                                     style={{color: context?.div.align === 'justify' ? (context?.dark ? 'white': '#484848') : 'grey'}}
                                     className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatBoldIcon  onClick={() => updateDiv({ font: context?.div.font, bold: !context?.div.bold, italic: context?.div.italic, underLined: context?.div.underLined, align: context?.div.align,})}
                             style={{color: context?.div.bold ? (context?.dark ? 'white': '#484848') : 'grey'}}
                             className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatItalicIcon  onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: !context?.div.italic, underLined: context?.div.underLined, align: context?.div.align,})}
                               style={{color: context?.div.italic ? (context?.dark ? 'white': '#484848') : 'grey'}}
                               className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
        <div className={styles.button}>
            <FormatUnderlinedIcon  onClick={() => updateDiv({ font: context?.div.font, bold: context?.div.bold, italic: context?.div.italic, underLined: !context?.div.underLined, align: context?.div.align,})}
                                   style={{color: context?.div.underLined ? (context?.dark ? 'white': '#484848') : 'grey'}}
                                   className={context?.dark ? styles.icon : styles.iconLight}/>
        </div>
    </div>
  );
}