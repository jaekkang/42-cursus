
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SRC = find_square.c main.c tool.c srcs.c ft_split.c
SRCS = $(addprefix ${SRCD}, ${SRC})
SRCD = ./srcs/
OBJS = ${SRCS:.c=.o}
INC = ./includes/
HEAD = ${INC}bsq_struct.h
TARGET = bsq_exe

all : ${TARGET}

%.o : %.c
	${CC} ${CFLAGS} -c $< -I ${INC} -o ${<:.c=.o}

${TARGET} : ${OBJS}
	@${CC} ${CFLAGS} -o ${TARGET} ${OBJS}

clean : 
	@rm -f ${OBJS}

fclean : clean
	@rm -f  ${TARGET}

re : fclean all

.PHONY : all clean fclean re
