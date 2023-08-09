FROM debian:buster

RUN apt-get update -y && \
    apt-get install -y mariadb-server mariadb-client && \
    rm -rf /var/lib/apt/lists/*

RUN service mysql start && mysqladmin -u root password pw123

RUN service mysql start && \
	mysql -uroot -ppw123 -e \
	"CREATE DATABASE mariadb; \
	CREATE USER 'zdevove'@'%' IDENTIFIED BY 'pw123'; \
	GRANT ALL ON mariadb.* TO 'zdevove'@'%'; \
	FLUSH PRIVILEGES;"

EXPOSE 3306

CMD ["mysqld", "--bind-address=0.0.0.0"]