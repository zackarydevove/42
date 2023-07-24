all: build run

build:
	@echo "Building docker images..."
	docker-compose -f srcs/docker-compose.yml build

run:
	@echo "Running docker-compose..."
	docker-compose -f srcs/docker-compose.yml up -d

down:
	@echo "Stopping docker-compose..."
	docker-compose -f srcs/docker-compose.yml down

re: down all

clean: down
	@echo "Removing all docker images..."
	docker system prune -a --volumes