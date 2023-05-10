
NAME = PhoneBook

CC = c++

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@${CC} ${FLAGS} $^ -o $@

clean :
	@rm ${OBJ}

fclean : clean
	@rm ${NAME}

re :
	make fclean
	make all

.PHONY : re clean fclean all 