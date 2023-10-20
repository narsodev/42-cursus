mariadb:
	docker build srcs/requirements/mariadb -t mariadb-ngonzale
	docker run --env-file srcs/requirements/mariadb/.env \
		-it -p 3306:3306 --name mariadb-ngonzale mariadb-ngonzale

rm-mariadb-container:
	-docker stop mariadb-ngonzale
	-docker rm mariadb-ngonzale

open-mariadb:
	docker exec -it mariadb-ngonzale bash

re-mariadb: rm-mariadb-container mariadb