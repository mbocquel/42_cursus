import React, { createContext, useState, ReactNode } from 'react';
import { useEffect } from 'react';

type SharedData = {
  page: string;
  updatePage: (page: string) => void;
};

const PageUrlContext = createContext<SharedData | undefined>(undefined);

type MyProviderProps = {
  children: ReactNode;
  page_url: string;
};

function PageUrlProvider({ children, page_url }: MyProviderProps) {
  const [sharedData, setSharedData] = useState({
    page: page_url,
  });
  useEffect(() => {
    setSharedData((prevSharedData) => ({
      ...prevSharedData,
      page: page_url,
    }));
  }, [page_url]);
  const updatePage = (newData: string) => {
    setSharedData({ ...sharedData, page: newData });
  };
  
  return (
    <PageUrlContext.Provider value={{ ...sharedData, updatePage}}>
      {children}
    </PageUrlContext.Provider>
  );
}

export { PageUrlProvider, PageUrlContext };