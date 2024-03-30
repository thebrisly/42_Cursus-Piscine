# this will create container on debian
FROM debian:buster

# these 3 lines will update (= search MAJ) & upgrade (= install MAJ) debian and then install nginx & VIM on this "virtual machine"
# -y is to accept all the questions automatically
RUN apt-get update -y 
RUN apt upgrade -y
RUN apt-get install -y nginx
RUN apt install vim -y


##########################
# SECURE CONNEXION : TLS #
##########################

# we now will create a file containing all the connexion/security files on the virtual machine (AKA docker)
# and then install OpenSSL on it
# -p will create any missing directories in the path and 
RUN mkdir -p /etc/nginx/ssl
RUN apt install -y openssl

# this command below will create a certificate and a private key
# x509 : certificate type
# - nodes : private key without password
# -out : where i will store my certificate -> a .crt file
# -keyout : where i will store my key -> a .key file
# - subj : jsut some fields required by OpenSSL for the certificate that i pre-fill
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/lfabbian_inception.crt \
    -keyout /etc/nginx/ssl/lfabbian_inception.key \
    -subj "/C=CH/ST=BERNE/L=Lausanne/O=42/OU=42Lausanne/CN=login.42lausanne.ch/UID=lfabbian"



#######################
# NGINX CONFIGURATION #
#######################

RUN mkdir -p /var/run/nginx

RUN mkdir -p /var/www/html
RUN chmod -R 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/nginx.conf

# Expose port
EXPOSE 443

# Start nginx with daemon off
CMD ["nginx", "-g", "daemon off;"]
