SRCS 		=		ScalarConverter.cpp main.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME		=		ex00

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98

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