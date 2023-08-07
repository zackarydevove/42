all:
	mkdir -p $(HOME)/data/mariadb
	mkdir -p $(HOME)/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up --build -d

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
	docker rmi my-wordpress my-mariadb my-nginx
	@sudo rm -rf $(HOME)/data/mariadb $(HOME)/data/wordpress
	@docker system prune -af

re:	fclean all
