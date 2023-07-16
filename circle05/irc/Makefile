SRCS        =       srcs/main.cpp \
                    srcs/Channel.cpp \
                    srcs/Client.cpp \
                    srcs/Server.cpp \
                    srcs/commands/cap.cpp \
                    srcs/commands/die.cpp \
                    srcs/commands/info.cpp \
                    srcs/commands/invite.cpp \
                    srcs/commands/join.cpp \
                    srcs/commands/kick.cpp \
                    srcs/commands/mode.cpp \
                    srcs/commands/names.cpp \
                    srcs/commands/nick.cpp \
                    srcs/commands/notice.cpp \
                    srcs/commands/oper.cpp \
                    srcs/commands/part.cpp \
                    srcs/commands/pass.cpp \
                    srcs/commands/ping.cpp \
                    srcs/commands/privmsg.cpp \
                    srcs/commands/quit.cpp \
                    srcs/commands/topic.cpp \
                    srcs/commands/user.cpp \
                    srcs/commands/wallops.cpp \
                    srcs/commands/whois.cpp

DIRS        =       $(sort $(dir $(SRCS)))

OBJS_DIR    =       obj/

OBJS        =       $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

NAME        =       ircserv

CC          =       c++

CFLAGS      =       -Wall -Wextra -Werror -std=c++98 -MMD

all         :       $(NAME)

$(NAME)     :       $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o :    %.cpp | dirs
	$(CC) $(CFLAGS) -c $< -o $@

dirs:
	mkdir -p $(addprefix $(OBJS_DIR), $(DIRS))

clean       :
	rm -rf $(OBJS_DIR)

fclean      :       clean
	rm -rf $(NAME)

re          :       fclean all

.PHONY      :       all clean fclean re dirs

-include $(OBJS:.o=.d)