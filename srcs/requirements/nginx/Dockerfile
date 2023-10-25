FROM debian:buster

RUN \
  apt-get update && \
  apt-get install -y openssl nginx

RUN openssl req -newkey rsa:2048 -x509 \
  -sha256 -nodes -days 342 -out \
  /etc/ssl/certs/ngonzale.crt -keyout \
  /etc/ssl/private/ngonzale.key -subj "/C=ES/L=Malaga/CN=ngonzale.42.fr"

COPY config/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
# cd /usr/share/wordpress/
# php -S 127.0.0.1:80
# mariadb --host mariadb-ngonzale