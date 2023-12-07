
FROM node:20 AS base

RUN mkdir /var/avatar

WORKDIR /app
COPY ["package.json", "./"]
RUN yarn install --frozen-lockfile
COPY . .
RUN mv norminet.jpeg /var/avatar/1111111111111.jpeg

CMD ["sh", "script.sh"]