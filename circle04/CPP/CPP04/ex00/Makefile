SRCS 		=		main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex00

CC 			=		g++

CFLAGS 		=		-Wall -Wextra -Werror

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		:		
					rm -rf $(OBJS)

fclean		:		 clean
					rm -rf $(NAME)

re			:		 fclean all

.PHONY		:		 all clean fclean re