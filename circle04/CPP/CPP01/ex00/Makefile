SRCS 		=		main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		zombie

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98

%.o			:			%.cpp
						$(CC) $(CFLAGS) -c $< -o $@

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		:		
					rm -rf $(OBJS)

fclean		:		 clean
					rm -rf $(NAME)

re			:		 fclean all

.PHONY		:		 all clean fclean re