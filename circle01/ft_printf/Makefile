# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdevove <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:44:48 by zdevove           #+#    #+#              #
#    Updated: 2022/11/18 14:44:52 by zdevove          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				=			ft_itoa_printf.c\
								ft_itoaunsigned_printf.c\
								ft_putchar_printf.c\
								ft_putptr_printf.c\
								ft_putstr_printf.c\
								ft_putx_printf.c\
								ft_printf.c

NAME				=			libftprintf.a

FLAGS				=			-Wall -Wextra -Werror

OBJ					=			$(SRCS:.c=.o)

all					:			$(NAME)

$(NAME)				:
								cc $(FLAGS) -c ft_printf.h $(SRCS) 
								ar -rc $(NAME) $(OBJ)
								@echo "===== libftprintf has been created ====="

clean				:
								rm -rf $(OBJ)
								@echo "===== temporary files had been deleted ====="

fclean				: 			clean
								rm -rf $(NAME)
								@echo "===== libftprintf has been deleted ====="

re					:			fclean all

.PHONY				:			all clean fclean re
								@echo "===== libftprintf created, delete and re-created done ====="
