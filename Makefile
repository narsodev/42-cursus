build: 
	docker-compose -f srcs/docker-compose.yml build

up:
	docker-compose -f srcs/docker-compose.yml up

down:
	docker-compose -f srcs/docker-compose.yml down

re: down up

all: build up

clean:
	docker system prune -a

fclean: clean
	docker volume prune