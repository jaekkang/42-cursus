# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:49:32 by jaekkang          #+#    #+#              #
#    Updated: 2022/11/02 16:32:00 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
FLAGE = -Wall -Wextra -Werror
LIB_FLAGE = -Llibft -lft

SRC_DIR = ./srcs/

OBJ_DIR = ./objs/

INC = -I./includes/

SRC = \
	main.c\

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all : ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR) srcs
	@$(CC) $(FLAG) ${INC} -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	$(CC)  $(LIB_FLAGE) ${OBJS} -o ${NAME}

clean :
	@make clean -C libft 
	@rm -rf ${OBJ_DIR}
	
fclean : clean
	@make fclean -C libft
	@rm -f ${NAME}

re :
	@make fclean
	@make all

.PHONY : all clean fclean re bonus