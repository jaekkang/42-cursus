
NAME = CPP01_01

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp ZombieHorde.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
	 