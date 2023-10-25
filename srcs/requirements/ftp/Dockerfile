FROM debian:buster

RUN \
  apt-get update && \
  apt-get install -y vsftpd

RUN mkdir /usr/share/wordpress
RUN echo /usr/sbin/nologin >> /etc/shells && useradd -d /usr/share/wordpress wordpress -s /usr/sbin/nologin && chown -R wordpress:wordpress /usr/share/wordpress && echo "wordpress:wordpress" | chpasswd

COPY config/vsftpd.conf /etc/vsftpd.conf
RUN echo wordpress > /etc/vsftpd.chroot_list

RUN mkdir -p /var/ftp /var/run/vsftpd/empty

EXPOSE 21
EXPOSE 21000-21010

CMD ["vsftpd"]