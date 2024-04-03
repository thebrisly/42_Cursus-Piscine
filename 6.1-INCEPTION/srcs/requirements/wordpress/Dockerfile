# this will create a container on debian
FROM debian:buster

# these 4 lines will update (= search MAJ) & upgrade (= install MAJ) debian and then install wget & VIM on this "virtual machine"
# -y is to accept all the questions automatically
RUN apt update -y
RUN apt upgrade -y
RUN apt install wget -y 
RUN apt install vim -y

# then we install php
RUN apt-get install php7.3 -y \
            php-fpm \
			php-mysql \
			mariadb-client

# copy new files that i created/modified and replacing the original files
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

# Download Wordpress
RUN wget https://fr.wordpress.org/wordpress-6.3-fr_FR.tar.gz -P /var/www

# Unzip Wordpress
RUN cd /var/www && tar -xzf wordpress-6.3-fr_FR.tar.gz && rm wordpress-6.3-fr_FR.tar.gz

# Give rights
RUN chmod 755 /var/www/wordpress && chown -R www-data:www-data /var/www/wordpress

# Copy script to configure wordpress
COPY ./tools/conf_wordpress.sh /tmp/conf_wordpress.sh

EXPOSE 9000

# Create run directory for php-fpm
RUN mkdir -p /run/php

# Fill wp-config.php with env variables
ENTRYPOINT ["sh", "/tmp/conf_wordpress.sh"]

# Run PHP (-F : stay in foreground)
CMD ["php-fpm7.3", "-F"]

# docker build -t wordpress .
# docker run -it wordpress