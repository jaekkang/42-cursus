NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

INC = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp AAnimal.cpp ADog.cpp ACat.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)  $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all