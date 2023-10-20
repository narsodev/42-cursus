FROM debian:buster

ENV ROOT_PASSWORD=root

RUN \
  apt-get update && \
  apt-get install -y mariadb-server

COPY ./config/my.cnf /etc/mysql/my.cnf

COPY ./tools/init.sh /init.sh
RUN chmod +x /init.sh && /init.sh

EXPOSE 3306

CMD ["mysqld"]