# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 11:34:44 by zdevove           #+#    #+#              #
#    Updated: 2023/05/16 11:34:45 by zdevove          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=			main.c init.c philo.c utils.c death_routine.c routine.c

NAME				=			philo

CC					=			cc

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.c=.o)

all					:			$(NAME)

$(NAME)				:			$(OBJS)
								$(CC) -o $(NAME) $(OBJS)
								@echo "===== philosopher has been created ====="

clean				:
								rm -rf $(OBJS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) libft.a
								@echo "===== philosopher has been deleted ====="

re					:			fclean all

.PHONY				:			all clean fclean re
								@echo "===== philosopher created, delete and re-created done ====="
