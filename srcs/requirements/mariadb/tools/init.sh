#!/bin/sh
service mysql start

mysql_secure_installation << EOF

y
$ROOT_PASSWORD
$ROOT_PASSWORD
y
y
y
y
EOF

mysql -u root << EOF
CREATE DATABASE wordpress;
GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP,ALTER
ON wordpress.*
TO wordpress@'%wordpress.%network'
IDENTIFIED BY 'password';
FLUSH PRIVILEGES;
EOF

service mysql stop

