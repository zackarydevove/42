# Start from a debian image base
FROM debian:buster

ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_ROOT_PASSWORD
ARG MYSQL_DATABASE

# Update and Install packages
RUN apt-get update -y && \
    apt-get install -y mariadb-server mariadb-client && \
    rm -rf /var/lib/apt/lists/*

# Start the MariaDB service, set root password, create database, user, and grant access
RUN service mysql start && \
    mysql -uroot -p$MYSQL_ROOT_PASSWORD -e \
    "CREATE DATABASE $MYSQL_DATABASE; \
    CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; \
    GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'; \
    FLUSH PRIVILEGES;"

# Expose port 3306 for mariadb
EXPOSE 3306

# Start the MariaDB server and bind its address to all available network interfaces (0.0.0.0)
CMD ["mysqld", "--bind-address=0.0.0.0"]