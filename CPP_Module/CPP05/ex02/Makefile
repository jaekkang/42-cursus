NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp ShrubberyCreationForm.cpp \

DEP = $(SRC:.cpp=.d)

OBJ = $(SRC:.cpp=.o)

TMP = *_shrubbery

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

-include $(DEP)

clean :
	$(RM) $(OBJ) $(DEP) $(TMP)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all