# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 09:19:23 by zdevove           #+#    #+#              #
#    Updated: 2023/01/02 13:21:57 by zdevove          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT			=			client

NAME_CLIENT_BONUS	=			client_bonus

NAME_SERVER			=			server

NAME_SERVER_BONUS	=			server_bonus

CC					=			cc

CFLAGS				=			-Wall -Wextra -Werror

all					:			$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT)		:
								make -C libft/ && mv libft/libft.a .
								$(CC) -o $(NAME_CLIENT) client.c libft.a

$(NAME_SERVER)		:
								$(CC) -o $(NAME_SERVER) server.c libft.a
								@echo "===== client.exe and server.exe has been created ====="

$(NAME_CLIENT_BONUS) :
								make -C libft/ && mv libft/libft.a .
								$(CC) -o $(NAME_CLIENT_BONUS) client_bonus.c libft.a

$(NAME_SERVER_BONUS):;
								$(CC) -o $(NAME_SERVER_BONUS) server_bonus.c libft.a
								@echo "===== client.exe and server.exe has been created ====="

clean				:
								make clean -C libft/
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS) libft.a
								@echo "===== push_swap && checker has been deleted ====="
								
re					:			fclean all

bonus				:			$(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

.PHONY				:			all clean fclean re bonus
								@echo "===== client.exe and server.exe created, delete and re-created done ====="
