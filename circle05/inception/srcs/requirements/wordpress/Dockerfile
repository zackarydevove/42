# Start from a debian image base
FROM debian:buster

# Update and Install packages
RUN apt-get update -y && \
    apt-get install -y wget php php-cgi php-mysql php-fpm php-pdo php-gd php-cli php-mbstring && \
	rm -rf /var/lib/apt/lists/*

# Download wordpress
RUN wget http://wordpress.org/wordpress-6.1.1.tar.gz -P /var/www/html && \
	tar -xvf /var/www/html/wordpress-6.1.1.tar.gz -C /var/www/html && \
	rm -rf /var/www/html/wordpress-6.1.1.tar.gz && \
	chown -R www-data:www-data /var/www/* && \
	chmod -R 755 /var/www/*

# Install wp_cli command
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

# Copy configurations
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
COPY ./conf/script.sh ./

RUN chmod +x ./script.sh && mkdir -p /run/php

EXPOSE 9000

ENTRYPOINT ["sh", "./script.sh"]
