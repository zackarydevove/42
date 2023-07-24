# Start from a debian image base
FROM debian:buster

# Update and Install packages, -y for automatic yes to any prompts
RUN apt-get update -y
RUN apt-get install -y wget \
    php \
    php-cgi \
    php-mysql \
    php-fpm \
    php-pdo \
    php-gd \
    php-cli \
    php-mbstring \
    rm -rf /var/lib/apt/lists/*

# Copy the .conf in the html directory (necessary tools to download wordpress)
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

# Create php directory to enable php-fpm to run and store the temporary files from php
RUN mkdir -p /run/php

# Copy the script, give the right to launch it in local on our computer, and launch it
COPY ./conf/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

# Expose the 9000 port
EXPOSE 9000

ENTRYPOINT ["bash", "/usr/local/bin/script.sh"]