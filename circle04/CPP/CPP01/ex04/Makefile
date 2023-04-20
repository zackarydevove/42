SRCS 		=		main.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		replace

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -Werror

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
					@echo "===== Program Horde has been created ====="

clean		:		
					rm -rf $(OBJS)
					@echo "===== Temporary files have been deleted ====="

fclean		:		 clean
					rm -rf $(NAME)
					@echo "===== Program Horde has been deleted ====="

re			:		 fclean all

.PHONY		:		 all clean fclean re