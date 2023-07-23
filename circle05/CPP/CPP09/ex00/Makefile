SRCS 		=		main.cpp BitcoinExchange.cpp

OBJS 		=		$(SRCS:.cpp=.o)

NAME 		=		btc

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