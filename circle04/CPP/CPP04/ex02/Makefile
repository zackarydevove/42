SRCS 		=		main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex02

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -Werror

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o					:			%.cpp
								$(CC) $(CFLAGS) -c $< -o $@

clean		:		
					rm -rf $(OBJS)

fclean		:		 clean
					rm -rf $(NAME)

re			:		 fclean all

.PHONY		:		 all clean fclean re