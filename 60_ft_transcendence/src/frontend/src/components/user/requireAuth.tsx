import { Navigate, useLocation } from "react-router-dom";
import { useLogin } from "./auth";

export const RequireAuth = ({ children }: any) => {
  const location = useLocation();
  const auth = useLogin();

  if (!auth.getLogin()) {
    return <Navigate to="/login" replace={true} state={{path: location.pathname}}/>;
  }
  return children;
};
