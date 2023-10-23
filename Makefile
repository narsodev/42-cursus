mariadb:
	docker build srcs/requirements/mariadb -t mariadb
	docker run --env-file srcs/requirements/mariadb/.env \
		-it -p 3306:3306 --network network --name mariadb mariadb

rm-mariadb-container:
	-docker stop mariadb
	-docker rm mariadb

open-mariadb:
	docker exec -it mariadb bash

re-mariadb: rm-mariadb-container mariadb

wordpress:
	docker build srcs/requirements/wordpress -t wordpress
	docker run -it -p 3001:3001 --network network --name wordpress wordpress

rm-wordpress-container:
	-docker stop wordpress
	-docker rm wordpress

open-wordpress:
	docker exec -it wordpress bash

re-wordpress: rm-wordpress-container wordpress

nginx:
	docker build srcs/requirements/nginx -t nginx
	docker run -it -p 3002:80 -p 443:443 --network network --name nginx nginx

rm-nginx-container:
	-docker stop nginx
	-docker rm nginx

open-nginx:
	docker exec -it nginx bash

db-network:
	docker network create network

db-network-check:
	docker network inspect network

rm-db-network:
	docker network rm network

rm: rm-mariadb-container rm-wordpress-container rm-nginx-container rm-db-network