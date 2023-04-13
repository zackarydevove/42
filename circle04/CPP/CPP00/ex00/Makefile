SRCS				=			megaphone.cpp

NAME				=			megaphone

CC					=			g++

CFLAGS				=			-Wall -Wextra -Werror

OBJS				=			$(SRCS:.cpp=.o)

all					:			$(NAME) 

$(NAME)				:			$(OBJS)
								$(CC) -o $(NAME) $(OBJS)
								@echo "===== megaphone has been created ====="

clean				:
								rm -rf $(OBJS)
								@echo "===== temporary files has been deleted ====="

fclean				: 			clean
								rm -rf $(NAME) libft.a
								@echo "===== megaphone has been deleted ====="

re					:			fclean all

.PHONY				:			all clean fclean re
								@echo "===== megaphone created, delete and re-created done ====="
