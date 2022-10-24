# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:49:32 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/24 16:20:35 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGE = -Wall -Wextra -Werror

CC = cc

SRCS = main.c

INC = -I./includes/

OBJ = ${SRCS:.c=.o}

${NAME} : ${OBJ}
	@make -C ./libft all
	@${CC} ${FLAGE} ${INC} ${OBJ} -o ${NAME}

all : ${NAME}
	@./${NAME}

clean :
	@make -C ./libft clean
	@rm -rf ${OBJ}
fclean : clean
	@make -C ./libft fclean
	@rm -f ${NAME}

re :
	@make fclean
	@make all

.PHONY : all clean fclean re