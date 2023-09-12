NAME = megaphone

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC = megaphone.cpp

DEP = $(SRC:.cpp=.d)

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

-include $(DEP)

clean :
	$(RM) $(OBJ) $(DEP)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all