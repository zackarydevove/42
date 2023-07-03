SRCS		=		main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJS 		=		$(SRCS:.cpp=.o)
DEPS 		=		$(SRCS:.cpp=.d)

OBJS_DIR	=		obj/
DEPS_DIR	=		obj/

OBJS		:=		$(addprefix $(OBJS_DIR), $(OBJS))
DEPS		:=		$(addprefix $(DEPS_DIR), $(DEPS))

NAME 		=		ex02

CC 			=		c++

CFLAGS 		=		-Wall -Wextra -Werror -std=c++98 -MMD

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o	:	%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

clean		:		
					rm -rf $(OBJS) $(DEPS) $(OBJS_DIR)

fclean		:		clean
					rm -rf $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re

-include $(DEPS)
