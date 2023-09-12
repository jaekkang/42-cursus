
NAME = replace

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean :
	${RM} ${OBJ}
	${RM} *.replace

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : re fclean clean all