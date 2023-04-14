# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 13:18:30 by zdevove           #+#    #+#              #
#    Updated: 2023/01/01 11:16:21 by zdevove          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				=			lst.c	main.c	main_utils.c main_utils2.c utils.c \
								op1.c 	op2.c	op3.c \
								sort.c

NAME				=			push_swap

CC					=			cc

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.c=.o)

all					:			$(NAME)

$(NAME)				:			$(OBJS)
								make -C libft/ && mv libft/libft.a .
								$(CC) -o $(NAME) $(OBJS) libft.a
								@echo "===== push_swap has been created ====="

clean				:
								make clean -C libft/
								rm -rf $(OBJS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) libft.a
								@echo "===== push_swap && checker has been deleted ====="

re					:			fclean all

.PHONY				:			all clean fclean re
								@echo "===== push_swap created, delete and re-created done ====="
