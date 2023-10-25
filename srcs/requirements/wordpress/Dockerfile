FROM debian:buster

ENV DB_ROOT_PASSWORD=root
ENV DB_NAME=wordpress
ENV DB_USER=wordpress
ENV DB_PASSWORD=password
ENV DB_HOST=mariadb

RUN \
  apt-get update && \
  apt-get install -y wordpress php-fpm

RUN groupadd wp && useradd -g wp wp
RUN chown -R wp:wp / || true

COPY config/php-fpm.conf /etc/php/7.3/fpm/pool.d/wordpress.conf
COPY tools/init.sh /init.sh
RUN chmod +x /init.sh && /init.sh
RUN mkdir /run/php

CMD ["php-fpm7.3", "-F"]

# php-fpm7.3 -F

# cd /usr/share/wordpress/
# php -S 127.0.0.1:80
# mariadb --host mariadb-ngonzale