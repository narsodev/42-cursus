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

service mysql stop

