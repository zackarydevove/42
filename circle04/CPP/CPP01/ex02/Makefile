SRCS 		=		main.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex02

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
					@echo "===== Zombie Horde has been created ====="

%.o					:			%.cpp
								$(CC) $(CFLAGS) -c $< -o $@

clean		:		
					rm -rf $(OBJS)
					@echo "===== Temporary files have been deleted ====="

fclean		:		 clean
					rm -rf $(NAME)
					@echo "===== Zombie Horde has been deleted ====="

re			:		 fclean all

.PHONY		:		 all clean fclean re