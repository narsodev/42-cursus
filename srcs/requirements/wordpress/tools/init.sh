echo "
<?php
define('DB_NAME', '$DB_NAME');
define('DB_USER', '$DB_USER');
define('DB_PASSWORD', '$DB_PASSWORD');
define('DB_HOST', '$DB_HOST');
define('WP_CONTENT_DIR', '/var/lib/wordpress/wp-content');
?>
" > /etc/wordpress/config-default.php