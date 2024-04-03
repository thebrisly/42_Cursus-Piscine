include ./srcs/.env

DOCKER_COMPOSE = ./srcs/docker-compose.yml

all: build

build:
		docker-compose -f ${DOCKER_COMPOSE} -p inception up --build

up:
		docker-compose -f ${DOCKER_COMPOSE} -p inception up

down:
		docker-compose -f ${DOCKER_COMPOSE} -p inception down

create_data:
	mkdir -p $(VOLUMES_PATH)/wordpress
	mkdir -p $(VOLUMES_PATH)/mysql

delete_data:
	rm -rf $(VOLUMES_PATH)

clean_data: delete_data create_data

purge:
	docker image prune -f -a

purge_volumes:
	docker volume rm wp_volume
	docker volume rm db_volume

fclean: purge purge_volumes clean_data

nginx:
	docker exec -it nginx bash

wordpress:
	docker exec -it wordpress bash

mariadb:
	docker exec -it mariadb bash

#Usage: make [target]
# up: Runs the containers
# build: Builds and run the containers
# down: Stops and removes the containers
# clean_data: Deletes and create data folders
# create_data: Creates data folders
# delete_data: Deletes data folders
# purge: Deletes all images
# purge_volumes: Deletes all volumes
# fclean: Deletes all images and data folders
# nginx: Access to nginx container
# wordpress: Access to wordpress container
# mariadb: Access to mariadb container
