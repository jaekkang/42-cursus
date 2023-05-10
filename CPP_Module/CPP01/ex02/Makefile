
NAME = CPP01_02

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@${CC} ${FLAGS} $^ -o $@


clean :
	@rm ${OBJ}

fclean : clean
	@rm ${NAME}

re : fclean all

.PHONY : all clean fclean re
	 