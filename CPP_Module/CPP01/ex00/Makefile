
NAME = CPP01_00

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

.cpp.o :
	${CC} ${FLAGS} -c $< -o $@

${NAME} : ${OBJ}
	${CC} ${FLAGS} $^ -o $@


clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean  re
	 