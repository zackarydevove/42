all:
	mkdir -p /home/zack/data/mariadb
	mkdir -p /home/zack/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up --build -d

down:
	docker compose -f ./srcs/docker-compose.yml down

logs:
	docker logs wordpress
	docker logs mariadb
	docker logs nginx

check:
	docker ps
	docker volume ls
	docker images

clean:
	docker stop wordpress mariadb nginx
	docker rm wordpress mariadb nginx

fclean: clean
	docker rmi wordpress mariadb nginx
	@sudo rm -rf /home/zack/data/mariadb /home/zack/data/wordpress
	@docker system prune -af

re:	fclean all
