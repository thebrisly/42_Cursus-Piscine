NAME = test

OBJ_DIR = objs/
SRC = main.cpp Harl.cpp
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ := $(SRC:%.cpp=%.o)
COMPILE = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	$(COMPILE) $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)