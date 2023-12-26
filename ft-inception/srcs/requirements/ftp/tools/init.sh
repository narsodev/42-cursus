#!/bin/sh

FTP_DIR=$1
FTP_USER=$2
FTP_PASSWORD=$3

mkdir -p /var/run/vsftpd/empty
echo "$FTP_USER" > /etc/vsftpd.chroot_list

mkdir -p "$FTP_DIR"

echo /usr/sbin/nologin >> /etc/shells

useradd -d "$FTP_DIR" "$FTP_USER" -s /usr/sbin/nologin

echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

chown -R "$FTP_USER":"$FTP_USER" "$FTP_DIR"