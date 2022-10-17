CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a
DIR = ./srcs/
SRCS =  ${DIR}ft_putchar.c ${DIR}ft_swap.c ${DIR}ft_putstr.c ${DIR}ft_strlen.c ${DIR}ft_strcmp.c
OBJS = ${SRCS:.c=.o}
INC = ./includes/

all : ${TARGET}

%.o : %.c
	${CC} ${CFLAGS} -c $< -I ${INC} -o ${<:.c=.o}

${TARGET} : ${OBJS}
	ar cr ${TARGET} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${TARGET}

re : fclean all

.PHONY : all clean fclean re
