#!/bin/sh

WP_DB_HOST=$1
WP_DB_NAME=$2
WP_DB_USER=$3
WP_DB_PASSWORD=$4

echo "
<?php
define('DB_NAME', '$WP_DB_NAME');
define('DB_USER', '$WP_DB_USER');
define('DB_PASSWORD', '$WP_DB_PASSWORD');
define('DB_HOST', '$WP_DB_HOST');
define('WP_CONTENT_DIR', '/var/lib/wordpress/wp-content');
?>
" > /etc/wordpress/config-default.php

groupadd wp && useradd -g wp wp

mkdir /run/php