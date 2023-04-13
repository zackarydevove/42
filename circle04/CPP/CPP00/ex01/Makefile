SRCS				=			main.cpp PhoneBook.cpp Contact.cpp

NAME				=			phonebook

CC					=			g++

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.cpp=.o)

all					:			$(NAME) 

$(NAME)				:			$(OBJS)
								$(CC) -o $(NAME) $(OBJS)
								@echo "===== phonebook has been created ====="

clean				:
								rm -rf $(OBJS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) libft.a
								@echo "===== phonebook has been deleted ====="

re					:			fclean all

.PHONY				:			all clean fclean re
								@echo "===== phonebook created, delete and re-created done ====="
