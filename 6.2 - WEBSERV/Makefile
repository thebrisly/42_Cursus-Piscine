SRCS = $(addprefix sources/,  CgiHandler.cpp Client.cpp ConfigParser.cpp main.cpp Request.cpp RequestUtils.cpp Response_2.cpp Response.cpp \
		RunServer.cpp ServerConfig.cpp ServerInitializer.cpp ServersManager.cpp Utils.cpp)

NAME = ./webserv

OBJS := $(SRCS:%.cpp=%.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
