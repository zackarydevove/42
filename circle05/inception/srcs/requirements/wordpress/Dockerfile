# Start from a debian image base
FROM debian:buster

# Update and Install packages, -y for automatic yes to any prompts
RUN apt-get update -y
RUN apt-get install -y php php-fpm

# Install WP-CLI on my Wordpress Website
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy the .conf in the html directory
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

# Create php directory to enable php-fpm to run
RUN mkdir /run/php

# Copy the script and launch it
COPY /tools/script.sh

RUN cd /run/php

# Run php-fpm
CMD [""]

