import React, { useState, useEffect } from 'react';
import { useContext } from 'react';
import { PageContext } from '../../../context/PageContext';

export function SmartCell(props:{i:number, j:number}) {
    const context = useContext(PageContext);
  
  
    if (!context) { throw new Error('useContext must be used within a MyProvider'); }
    
    const { div, zoom, scroll, updateCoords } = context;
    const { align } = div;
  
    const { scrollX, scrollY } = scroll;
    const [sx, setNewScrollX] = useState(scrollX);
    const [sy, setNewScrollY] = useState(scrollY);
  
    const dynamicLeft = `${(props.i - sy) * (80 + ((zoom - 100)) / 2)}px`;
    const dynamicTop = `${(props.j - sx) * (20 + ((zoom - 100)) / 8)}px`;
  
    const handleUpdateCoords = (a: number, b: number) => {
      updateCoords({ coordX: a, coordY: b });
    };
  
    const [input, setInput] = useState('');
    const handleInputChange = (event: React.ChangeEvent<HTMLInputElement>) => {
      setInput(event.target.value);
    };
    const handleKeyDown = (event: React.KeyboardEvent<HTMLInputElement>) => {
      if (event.key === 'Enter') {
        event.preventDefault();
        if (input.charAt(0) === '=')
            calculate();
      }
    };
    const calculate = () => {
      try {
        const calculatedResult = evaluateExpression(input);
        setInput(calculatedResult.toString());
      } catch (error) {
        setInput(error + '');
        //console.error('Invalid expression:', error);
      }
    };
    const evaluateExpression = (expression: string): number => {
      const sanitizedExpression = expression.replace(/[^0-9()+\-*/.]/g, ''); // Sanitize input
  
      return evalInBrackets(sanitizedExpression);
    };
  
    const evalInBrackets = (expression: string): number => {
      while (expression.includes('(')) {
        const startIndex = expression.lastIndexOf('(');
        const endIndex = expression.indexOf(')', startIndex);
  
        if (endIndex === -1) {
          throw new Error('Mismatched brackets');
        }
  
        const subExpression = expression.slice(startIndex + 1, endIndex);
        const result = evaluate(subExpression);
  
        expression = expression.replace(`(${subExpression})`, result.toString());
      }
  
      return evaluate(expression);
    };
  
    const evaluate = (expression: string): number => {
      const operators = ['*', '/', '+', '-'];
      const tokens = expression.split(/([+\-*/])/).map((token) => token.trim());
  
      let result = parseFloat(tokens[0]);
  
      for (let i = 1; i < tokens.length; i += 2) {
        const operator = tokens[i];
        const nextOperand = parseFloat(tokens[i + 1]);
  
        if (!operators.includes(operator) || isNaN(nextOperand)) {
          throw new Error('Invalid expression');
        }
  
        if (operator === '+') {
          result += nextOperand;
        } else if (operator === '-') {
          result -= nextOperand;
        } else if (operator === '*') {
          result *= nextOperand;
        } else if (operator === '/') {
          if (nextOperand === 0) {
            throw new Error('Division by zero');
          }
          result /= nextOperand;
        }
      }
  
      return result;
    };

    useEffect(() => {
        setNewScrollX(scrollX);
        setNewScrollY(scrollY);
      }, [scrollX, scrollY]);

    return (
      <input id={`x:${props.i} y:${props.j}`} key={`x:${props.i} y:${props.j}`} 
                 size={1}
                 onMouseDown={() => handleUpdateCoords(props.i, props.j)}
                 value={input}
                 onChange={handleInputChange}
                 onKeyDown={handleKeyDown}
                 style={{
                    position: 'absolute',
                    top: dynamicTop,
                    left: dynamicLeft,
                    width: `${80 + ((zoom - 100)) / 2}px`,
                    height: `${20 + ((zoom - 100)) / 8}px`,
                    boxSizing: 'border-box',
                    border: '0.5px solid #C0C0C0',
                    fontSize: `${11 + ((zoom - 100) / 16)}px`,
                    textIndent: '3px',
                    textAlign: align as 'left' | 'right' | 'center' | 'justify',
                    fontWeight: context?.div.bold ? 'bold': 'normal',
                    fontStyle: context?.div.italic ? 'italic': '',
                    textDecoration: context?.div.underLined ? 'underline': '',
                    fontFamily: context?.div.font,
          }}
            onFocus={(e) => {
              e.target.style.outline = 'none';
            }}>
      </input>);
  }