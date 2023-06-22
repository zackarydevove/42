FROM debian:buster

RUN apt-get update -y
RUN apt-get install -y mariadb-server mariadb-client

COPY ./conf/script.sh /script.sh
RUN chmod +x /script.sh

EXPOSE 3306

ENTRYPOINT ["bash", "/script.sh"]