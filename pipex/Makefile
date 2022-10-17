# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:49:32 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/18 07:57:10 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGE = -Wall -Wextra -Werror

CC = cc

SRCS = main.c

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	@${CC} ${FLAGE} ${OBJ} -o ${NAME}

all : ${NAME}
	@./${NAME}

clean :
	@rm -rf ${OBJ}
fclean : clean
	@rm -f ${NAME}

re :
	@make fclean
	@make all

.PHONY : all clean fclean re