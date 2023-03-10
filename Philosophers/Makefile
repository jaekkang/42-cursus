# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 18:40:21 by jaekkang          #+#    #+#              #
#    Updated: 2023/03/03 14:23:1\1 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFALG = -Wall -Wextra -Werror #-fsanitize=thread -g

INC = -I./includes/

SRCS_DIR = ./srcs/

OBJS_DIR = ./objs/

SRC = \
	main.c \
	mornitor.c \
	philo.c \
	eating.c \
	handler.c \
	init.c \
	check.c \
	time.c \
	print.c \
	utils.c \
	
SRCS = ${addprefix ${SRCS_DIR}, ${SRC}} 

OBJ = ${SRC:.c=.o}
OBJS = ${addprefix ${OBJS_DIR}, ${OBJ}}

all : ${NAME}

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p ${OBJS_DIR}
	@${CC} ${CFALG} ${INC} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${CFALG} ${OBJS} -o ${NAME}

clean :
	@rm -rf ${OBJS_DIR}

fclean : clean
	@rm -f ${NAME}

re :
	@make fclean
	@make all

.PHONY: all clean fclean re bonus
