#!/bin/sh
DB_ROOT_PASSWORD=$1
DB_NAME=$2
DB_USER=$3
DB_USER_HOST=$4
DB_PASSWORD=$5

service mysql start

sleep 3

mysql -u root << EOF
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$DB_ROOT_PASSWORD')
FLUSH PRIVILEGES;
EOF

mysql_secure_installation << EOF
$DB_ROOT_PASSWORD
n
y
y
y
y
EOF

mysql -u root --password="$DB_ROOT_PASSWORD" << EOF
CREATE DATABASE $DB_NAME;
GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP,ALTER
ON $DB_NAME.*
TO $DB_USER@'$DB_USER_HOST'
IDENTIFIED BY '$DB_PASSWORD';
FLUSH PRIVILEGES;
EOF

sleep 3

service mysql stop