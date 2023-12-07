FROM node:20-alpine

WORKDIR /var/www/prisma-studio

COPY ./prisma/schema.prisma .
COPY ./.env .env
RUN apk update
RUN apk --no-cache add curl
RUN npm install -g prisma

STOPSIGNAL SIGKILL

CMD ["prisma", "studio", "--browser", "none"]
