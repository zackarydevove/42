#!/bin/sh

WP_PATH="/var/www/html/wordpress"

# Check if wordpress is already downloaded
if [ -f ./wp-config.php ]
then
	echo "wordpress already installed"
else
	# Create the wp-config.php file
	wp config create --allow-root \
					--dbname="$MYSQL_HOSTNAME" \
					--dbuser="$MYSQL_USER" \
					--dbpass="$MYSQL_PASSWORD" \
        			--dbhost="$MYSQL_HOST" \
					--path="$WP_PATH"

	# Fill wordpress first page
	wp core install --allow-root \
					--url="$DOMAIN_NAME" \
					--title="$WP_TITLE" \
					--admin_user="$WP_ADMIN_LOGIN" \
					--admin_password="$WP_ADMIN_PASSWORD" \
					--admin_email="$WP_ADMIN_EMAIL" \
					--path="$WP_PATH"
	
	# Add user1
	wp user create --allow-root \
					"$WP_USER1_LOGIN" "$WP_USER1_EMAIL" \
					--user_pass="$WP_USER1_PASSWORD" \
					--path="$WP_PATH"

	touch /wordpress_installed
fi

echo "wordpress ready"
/usr/sbin/php-fpm7.3 -F
