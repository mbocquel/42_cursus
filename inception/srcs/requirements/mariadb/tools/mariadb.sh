#!/bin/bash
if [ -e "/var/lib/mysql/first_config_db_done" ]
then
	echo "Database already configured"
else
	echo "Creating the files change_root.sql and config_db.sql"
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';" >> /var/lib/mysql/change_root.sql
	echo "FLUSH PRIVILEGES;" >> /var/lib/mysql/change_root.sql
	echo "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';" > /var/lib/mysql/config_db.sql
	echo "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;" >> /var/lib/mysql/config_db.sql
	echo "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';"  >> /var/lib/mysql/config_db.sql
	echo "FLUSH PRIVILEGES;" >> /var/lib/mysql/config_db.sql

	echo "---> Starting MYSQL"
	service mariadb start

	sleep 5

	echo "---> Configuring MYSQL"
	mariadb -u root < /var/lib/mysql/config_db.sql

	echo "---> Changing root password"
	mariadb -u root < /var/lib/mysql/change_root.sql

	echo "---> Shuting down the database"
	mariadb-admin --user=root --password=$MARIADB_ROOT_PASSWORD shutdown

	echo "---> Removing temporary files"
	rm /var/lib/mysql/change_root.sql /var/lib/mysql/config_db.sql

	echo "Creating first_config_db_done"
	touch /var/lib/mysql/first_config_db_done
fi

echo "---> Launching mysql_safe service"
exec mysqld_safe;