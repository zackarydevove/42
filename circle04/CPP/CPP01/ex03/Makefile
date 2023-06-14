SRCS 		=		main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex03

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98

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