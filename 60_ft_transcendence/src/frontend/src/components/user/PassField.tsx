import "./checkField.scss";
import { useEffect, useState } from "react";

function PassField(props: { value: string; handleValid: Function }) {
  const [newPassword, setNewPassword] = useState("");
  const [confPassword, setConfPassword] = useState("");
  const [confPasswordClass, setConfPasswordClass] = useState("NA");

  useEffect(() => {
    if ((confPassword && newPassword) || confPassword) {
      if (confPassword === newPassword) {
        setConfPasswordClass("OK");
        props.handleValid(newPassword);
      } else setConfPasswordClass("KO");
    } else setConfPasswordClass("NA");
  }, [confPassword, newPassword]);

  return (
    <>
      <input
        name="choosePasswordInput"
        type="password"
        placeholder="Password"
        value={newPassword}
        autoComplete="on"
        onChange={(e) => setNewPassword(e.target.value)}
      />
      <input
        name="confirmPasswordInput"
        className={confPasswordClass}
        type="password"
        placeholder="Confirm Password"
        value={confPassword}
        autoComplete="on"
        onChange={(e) => setConfPassword(e.target.value)}
      />
    </>
  );
}

export default PassField;
