# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:49:32 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/25 15:12:27 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGE = -Wall -Wextra -Werror

LIB_FLAGE = -Llibft -lft

CC = cc

SRCS = \
	main.c\

INC = -I./includes/

.o.c: ${NAME}
	${CC} ${FLAGE} ${INC} -c $< -o $@

${NAME} : ${OBJ}
	@make -C libft
	@${CC} ${LIB_FLAGE} $@ -o $^

all : ${NAME}

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