#!/bin/bash

# Check if the database already exists
if [ -f /mariadb_installed ]
then 
	echo "Database already exists"
else
	# Start MariaDB in the background for initial setup
	mysqld_safe &

	# Wait for MariaDB to start up
	sleep 10

	echo "Configuring $MYSQL_DATABASE ..."

	# Create everything in db
	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"
	mysql -e "FLUSH PRIVILEGES;"
	
    touch /mariadb_installed

    # Kill all mysqld processes (since mysqld_safe might spawn multiple) 
    killall mysqld
    sleep 10
fi

echo "database $MYSQL_DATABASE ready"
mysqld --bind-address=0.0.0.0
