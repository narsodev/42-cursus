FROM debian:buster

ARG FTP_USER=ftp_user
ARG FTP_PASSWORD=ftp_pwd

RUN \
  apt-get update && \
  apt-get install -y vsftpd

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh && /init.sh /var/ftp $FTP_USER $FTP_PASSWORD

COPY config/vsftpd.conf /etc/vsftpd.conf

EXPOSE 21
EXPOSE 21000-21010

CMD ["vsftpd"]