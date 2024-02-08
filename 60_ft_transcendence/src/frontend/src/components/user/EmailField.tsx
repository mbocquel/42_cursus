import { useState } from "react";
import "./checkField.scss";

function EmailField(props: { value: string; handleValid: Function }) {
  const [checkClass, setCheckClass] = useState("NA");
  const [email, setEmail] = useState(props.value);

  const handleChange = (m: string) => {
    setEmail(m);
    const re = /^[ ]*([^@\s]+)@((?:[-a-z0-9]+\.)+[a-z]{2,})[ ]*$/i;
    if (re.test(m)) {
      setCheckClass("OK");
      props.handleValid(m);
    } else {
      setCheckClass("KO");
    }
  };

  return (
    <input
      name="emailFieldInput"
      className={checkClass}
      type="email"
      placeholder="email"
      value={email}
      onChange={(e) => handleChange(e.target.value)}
    />
  );
}

export default EmailField;
