#!/bin/bash

# Check if the database already exist
if [ -f /mariadb_installed ]
then 
	echo "Database already exists"
else
	echo "Configuring $MYSQL_DATABASE ..."

	#mysql_install_db
	killall mysqld
	mysql_install_db &> /dev/null;
	service mysql start 2> /dev/null;

	#SQL langage, create everything (rootpassword, user, privileges, etc.)
	mysql -e "CREATE DATABASE $MYSQL_DATABASE;";
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';";
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';";
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';FLUSH PRIVILEGES;";
	
    touch /mariadb_installed
fi

killall mysqld
echo "database $MYSQL_DATABASE ready"
mysqld --bind-address=0.0.0.0