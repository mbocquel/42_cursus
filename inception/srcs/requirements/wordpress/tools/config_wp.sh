#!/bin/bash

if [ -f "/var/www/html/wp-config.php" ]
then
	echo "wordpress is already set !"
else
	echo "I will set wp"
	sleep 10
	./wp-cli.phar config create --allow-root --dbname=$MARIADB_DATABASE --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASSWORD --dbhost=mariadb:3306 --path='/var/www/html'
	chmod 777 /var/www/html/wp-config.php
	chown -R root:root /var/www/html
	./wp-cli.phar core install --allow-root --url=$DOMAIN_NAME --title="$TITLE" --admin_user=$WP_ADMIN_USER --admin_password=$WP_PASSWORD --admin_email=$SITE_ADMIN_MAIL --path='/var/www/html'
	./wp-cli.phar user create $WP_SECOND_USER $WP_SECOND_USER_EMAIL --allow-root --role=author --user_pass=$WP_SECOND_USER_PW --path='/var/www/html'
	echo "Wordpress script run!"
fi

exec /usr/sbin/php-fpm7.4 -F;
