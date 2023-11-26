NAME = Array
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HEADER = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADER)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
