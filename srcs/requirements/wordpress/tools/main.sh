#!/bin/sh

wp core install \
  --url="$WP_URL" \
  --title="$WP_TITLE" \
  --admin_user="$WP_ADMIN_USER" \
  --admin_password="$WP_ADMIN_PASSWORD" \
  --admin_email="$WP_ADMIN_EMAIL" \
  --allow-root \
  --path="/usr/share/wordpress/"

wp user create \
  "$WP_USER" \
  "$WP_USER_EMAIL" \
  --user_pass="$WP_USER_PASSWORD" \
  --role="author" \
  --allow-root \
  --path="/usr/share/wordpress/"

php-fpm7.3 -F