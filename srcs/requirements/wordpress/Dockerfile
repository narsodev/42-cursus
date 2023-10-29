FROM debian:buster

ARG WP_DB_HOST=db_host
ARG WP_DB_NAME=wordpress
ARG WP_DB_USER=wp
ARG WP_DB_PASSWORD=wp_pwd

ENV WP_URL=localhost
ENV WP_TITLE=wordpress

ENV WP_ADMIN_USER=admin
ENV WP_ADMIN_EMAIL=admin@ngonzale.42.fr
ENV WP_ADMIN_PASSWORD=admin

ENV WP_USER=user
ENV WP_USER_PASSWORD=user
ENV WP_USER_EMAIL=user@ngonzale.42.fr


RUN \
  apt-get update && \
  apt-get install -y wordpress php-fpm curl

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
  php wp-cli.phar --info && \
  chmod +x wp-cli.phar && \
  mv wp-cli.phar /usr/local/bin/wp

COPY config/php-fpm.conf /etc/php/7.3/fpm/pool.d/wordpress.conf

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh && /init.sh $WP_DB_HOST $WP_DB_NAME $WP_DB_USER $WP_DB_PASSWORD

COPY tools/main.sh /main.sh
RUN chmod +x /main.sh

CMD ["/main.sh"]