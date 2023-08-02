FROM	debian:bullseye

LABEL	author="mbocquel"
LABEL	version="1.0"

RUN		mkdir -p /var/www/html \
		&& mkdir -p /run/php

RUN		apt update -y \
		&& apt upgrade -y \
		&& apt install wget -y \
		&& apt install -y php7.4 php-fpm php-mysql php-common php-cgi php-cli mariadb-client vim

EXPOSE	9000

RUN		wget https://fr.wordpress.org/wordpress-6.2.2-fr_FR.tar.gz -P /var/www
RUN		tar -xzf /var/www/wordpress-6.2.2-fr_FR.tar.gz -C /var/www/.
RUN 	cp -r /var/www/wordpress/. /var/www/html
RUN 	rm /var/www/wordpress-6.2.2-fr_FR.tar.gz

RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN 	chmod +x wp-cli.phar

COPY	conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY 	tools/config_wp.sh config_wp.sh

RUN		chmod +x config_wp.sh

CMD ["./config_wp.sh"]