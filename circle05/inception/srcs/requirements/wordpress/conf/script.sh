#!/bin/sh

cd /var/www/html/

# Check if the file word_press_installed exist (if wordpress is already downloaded)
if [ -f ./wordpress_installed ]
then
	echo "wordpress already installed"
	sleep 10
else
	# Download wordpress and all config file
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz wordpress

	# Install wp_cli command and put it in the right directory /usr/local/bin
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	# Make sure the db is well created
	sleep 30

	# Import env variables in the config file
	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php

	touch /wordpress_installed
fi

echo "wordpress ready"
/usr/sbin/php-fpm7.3 -F

