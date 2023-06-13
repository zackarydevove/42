SRCS 		=		main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex03

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -Werror

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
					@echo "===== ex03 has been created ====="

%.o					:			%.cpp
								$(CC) $(CFLAGS) -c $< -o $@

clean		:		
					rm -rf $(OBJS)
					@echo "===== Temporary files have been deleted ====="

fclean		:		 clean
					rm -rf $(NAME)
					@echo "===== ex03 has been deleted ====="

re			:		 fclean all

.PHONY		:		 all clean fclean re