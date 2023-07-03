SRCS 		=		srcs/main.cpp \
					srcs/Channel.cpp \
					srcs/Client.cpp \
					srcs/Server.cpp \
					srcs/commands/die.cpp \
					srcs/commands/invite.cpp \
					srcs/commands/join.cpp \
					srcs/commands/kick.cpp \
					srcs/commands/mode.cpp \
					srcs/commands/msg.cpp \
					srcs/commands/nick.cpp \
					srcs/commands/oper.cpp \
					srcs/commands/quit.cpp \
					srcs/commands/topic.cpp

OBJS 		=		$(SRCS:.cpp=.o)
DEPS 		=		$(SRCS:.cpp=.d)

OBJS_DIR	=		obj/
DEPS_DIR	=		obj/

OBJS		:=		$(addprefix $(OBJS_DIR), $(OBJS))
DEPS		:=		$(addprefix $(DEPS_DIR), $(DEPS))

NAME 		=		ex01

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
