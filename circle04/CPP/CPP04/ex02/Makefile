SRCS 		=		main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS 		=		$(SRCS:.cpp=.o)

DEPS 		=		$(SRCS:.cpp=.d)

NAME 		=		ex02

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98 -MMD

all			:		 $(NAME)

$(NAME)		:		 $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o					:			%.cpp
								$(CC) $(CFLAGS) -c $< -o $@

clean		:		
					rm -rf $(OBJS) $(DEPS)

fclean		:		 clean
					rm -rf $(NAME)

re			:		 fclean all

.PHONY		:		 all clean fclean re

-include $(DEPS)