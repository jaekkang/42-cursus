NAME = a.out

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScaveTrap.cpp 

OBJ = ${SRC:.cpp=.o}

.cpp.o :
	${CC} ${FLAGS} -c $<

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : re fclean clean all