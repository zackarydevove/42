SRCS 		=		main.cpp Fixed.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		ex02

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