NAME = a.out

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScaveTrap.cpp

OBJ = $(SRC:.cpp=.o)

.cpp.o :
	$(CC) $(FLAGS) -c $<

RM = rm -rf

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all