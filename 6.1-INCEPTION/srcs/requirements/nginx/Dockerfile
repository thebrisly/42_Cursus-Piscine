# this will create a container on debian
FROM debian:buster

# these 3 lines will update (= search MAJ) & upgrade (= install MAJ) debian and then install nginx & VIM on this "virtual machine"
# -y is to accept all the questions automatically
RUN apt update -y 
RUN apt upgrade -y
RUN apt install nginx -y
RUN apt install vim -y


##########################
# SECURE CONNEXION : TLS #
##########################

# we now will create a file containing all the connexion/security files on the virtual machine (AKA docker)
# and then install OpenSSL on it
# -p will create any missing directories in the path and 
RUN mkdir -p /etc/nginx/ssl && apt install openssl -y
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/lfabbian.42lausanne.ch.crt \
    -keyout /etc/nginx/ssl/lfabbian.42lausanne.ch.key \
    -subj "/C=CH/ST=VD/L=Lausanne/O=42/OU=42Lausanne/CN=login.42lausanne.ch/UID=laura"

RUN rm -rf /etc/nginx/http.d/default.conf

# Copy nginx config
COPY conf/nginx.conf /etc/nginx/nginx.conf

# give rights
RUN chmod 755 /var/www/html && chown -R www-data:www-data /var/www/html

# port to communicate with internet
EXPOSE 443

# Start nginx with daemon off
CMD ["nginx", "-g", "daemon off;"]

# docker build -t nginx .
# docker run -it -p 443:443 nginx