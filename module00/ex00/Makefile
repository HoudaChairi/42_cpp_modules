NAME = megaphone
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(SRC) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re
