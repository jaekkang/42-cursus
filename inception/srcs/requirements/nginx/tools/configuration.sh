#!/bin/sh

if [ ! -d "/etc/nginx/ssl" ]; then
       mkdir /etc/nginx/ssl
       openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
              -out /etc/nginx/ssl/jaekkang.crt \
              -keyout /etc/nginx/ssl/jaekkang.key \
              -subj "/C=KR/ST=Seoul/L=Seoul/O=42 School/OU=student/CN=jaekkang/"
       mkdir -p /run/nginx
fi

nginx -g "daemon off;"