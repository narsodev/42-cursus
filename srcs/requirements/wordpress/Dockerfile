FROM debian:buster

ARG WP_DB_HOST=db_host
ARG WP_DB_NAME=wordpress
ARG WP_DB_USER=wp
ARG WP_DB_PASSWORD=wp_pwd

RUN \
  apt-get update && \
  apt-get install -y wordpress php-fpm

COPY config/php-fpm.conf /etc/php/7.3/fpm/pool.d/wordpress.conf

COPY tools/init.sh /init.sh

RUN chmod +x /init.sh && /init.sh $WP_DB_HOST $WP_DB_NAME $WP_DB_USER $WP_DB_PASSWORD

CMD ["php-fpm7.3", "-F"]