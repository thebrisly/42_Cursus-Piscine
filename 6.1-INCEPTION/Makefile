# Get variables from .env file
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
