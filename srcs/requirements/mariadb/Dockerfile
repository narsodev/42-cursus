FROM debian:buster

ARG DB_ROOT_PASSWORD=root
ARG DB_NAME=db
ARG DB_USER=user
ARG DB_USER_HOST=domain
ARG DB_PASSWORD=password

RUN \
  apt-get update && \
  apt-get install -y mariadb-server

COPY config/my.cnf /etc/mysql/my.cnf

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh && /init.sh $DB_ROOT_PASSWORD $DB_NAME $DB_USER $DB_USER_HOST $DB_PASSWORD

CMD ["mysqld"]