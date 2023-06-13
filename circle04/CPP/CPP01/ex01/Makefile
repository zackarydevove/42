SRCS 		=		main.cpp Zombie.cpp zombieHorde.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		zombie_horde

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -Werror

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