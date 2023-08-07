#!/bin/bash

# Start mysql in the background for initial setup
service mysql start

# Check if the database already exists
if [ -f /mariadb_installed ]
then 
	echo "Database already exists"
else
	echo "Configuring $MYSQL_DATABASE ..."

	# Create everything in db
	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';"
	mysql -e "FLUSH PRIVILEGES;"
	
    touch /mariadb_installed
fi

# Stop the initial MySQL service
service mysql stop

echo "database $MYSQL_DATABASE ready"
mysqld --bind-address=0.0.0.0
