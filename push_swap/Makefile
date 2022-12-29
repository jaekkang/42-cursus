# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:49:24 by jaekkang          #+#    #+#              #
#    Updated: 2022/12/29 17:30:49 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU	= \033[0;34m
GRN	= \033[0;32m
RED	= \033[0;31m
RST	= \033[0m
END	= \e[0m

NAME = push_swap

CC = gcc
FLAG = -Wall -Wextra -Werror -g
LIBFLAG = -Llib -lft -L ft_printf -lftprintf

INC = -I./includes/

SRC_DIR = ./srcs/

OBJ_DIR = ./objs/

SRC = \
	main.c \
	utils.c \
	quick_sort.c \
	stack_utils.c \
	oper1.c \
	oper2.c \
	a_to_b.c \
	b_to_a.c \
	utils2.c\
	
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all : ${NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR) srcs
	@$(CC) $(FLAG) ${INC} -c $< -o $@
	@printf	"${BLU}[BUILD - $(NAME)] '$<' $(END)"

$(NAME): $(OBJS)
	@make -C lib
	@make -C ft_printf
	@$(CC) ${LIBFLAG} ${OBJS} -o ${NAME}

clean :
	@rm -rf ./objs
	@make clean -C lib
	@echo "${RED}[CLEAN]${RST} done"
	
fclean : clean
	@make fclean -C lib/
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "${RED}[FCLEAN]${RST} done"

re : 
	make fclean 
	make all

.PHONY: all clean fclean re bonus
