# this will create a container on debian
FROM debian:buster

ARG SQL_DATABASE
ARG SQL_USER
ARG SQL_PASSWORD
ARG SQL_ROOT_PASSWORD

# these 3 lines will update (= search MAJ) & upgrade (= install MAJ) debian and then install mariadb on this "virtual machine"
# -y is to accept all the questions automatically
RUN apt update -y
RUN apt upgrade -y
RUN apt install mariadb-server -y

# copy new files that i created/modified and replacing the original files
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/conf_mariadb.sh /tmp/conf_mariadb.sh

# run script to configure mariadb
RUN service mysql start && sh /tmp/conf_mariadb.sh

# port 3306 to communicate between WP and mariadb
EXPOSE 3306

# run mariadb
CMD ["mysqld"]
