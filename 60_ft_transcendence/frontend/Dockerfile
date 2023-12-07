FROM node:20

WORKDIR /app

COPY ["package.json", "./"]

RUN yarn install
RUN yarn add socket.io-client
RUN yarn add react-router-dom
RUN yarn add sass
RUN yarn add clipboard
RUN yarn add @uidotdev/usehooks
RUN yarn add @types/react-router-dom --dev
RUN yarn add @mui/icons-material @mui/material @emotion/styled @emotion/react @types/react
COPY . .

CMD ["yarn", "start"]
