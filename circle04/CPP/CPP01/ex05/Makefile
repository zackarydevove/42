SRCS		=		main.cpp Harl.cpp

OBJS		=		$(SRCS:.cpp=.o)

NAME		=		harl

CC			=		g++

CFLAGS		=		-Wall -Wextra -Werror

all			:		$(NAME)

$(NAME)		:		$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
						@echo "===== Harl has been created ====="

clean		:
						rm -rf $(OBJS)
						@echo "===== Temporary files have been deleted ====="

fclean		: 		clean
						rm -rf $(NAME)
						@echo "===== Harl has been deleted ====="

re			:		fclean all

.PHONY		:		all clean fclean re