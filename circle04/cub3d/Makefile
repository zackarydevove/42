# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:09:46 by zdevove           #+#    #+#              #
#    Updated: 2023/04/21 16:24:47 by zdevove          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=			srcs/main.c \
								srcs/parsing/parsing.c \
								srcs/parsing/parsing_utils.c \
								srcs/parsing/check_walls.c \
								srcs/game/hooks.c \
								srcs/game/background.c \
								srcs/game/textures.c \
								srcs/game/move_player.c \
								srcs/game/raycasting.c \
								srcs/game/rotate_player.c

NAME				=			cub3d

CC					=			cc

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.c=.o)

OBJS_BONUS			=			$(SRCS_BONUS:.c=.o)

LFLAGS				=			libmlx.a libmlx_Linux.a -lX11 -lXext -lm

all					:			$(NAME)

$(NAME)				:			$(OBJS)
								make -C libft/ && mv libft/libft.a .
								make -C minilibx-linux/ && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
								$(CC) -o $(NAME) $(OBJS) $(LFLAGS) libft.a
								@echo "===== cub3d has been created ====="

$(NAME_BONUS)		:			$(OBJS_BONUS)
								make -C libft/ && mv libft/libft.a .
								make -C minilibx-linux/ && mv minilibx-linux/libmlx.a . && mv minilibx-linux/libmlx_Linux.a .
								$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LFLAGS) libft.a
								@echo "===== cub3d bonus has been created ====="

bonus				:			$(NAME_BONUS)

clean				:
								make clean -C libft/
								make clean -C minilibx-linux/
								rm -rf $(OBJS) $(OBJS_BONUS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) $(NAME_BONUS) libft.a libmlx.a libmlx_Linux.a
								@echo "===== cub3d has been deleted ====="

re					:			fclean all

.PHONY				:			all bonus clean fclean re
								@echo "===== cub3d created, deleted and re-created done ====="
