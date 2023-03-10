# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:49:24 by jaekkang          #+#    #+#              #
#    Updated: 2023/02/10 11:36:29 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU	= \033[0;34m
GRN	= \033[0;32m
RED	= \033[0;31m
RST	= \033[0m
END	= \e[0m

NAME = push_swap
BONUS_NAME = checker

CC = gcc
FLAG = -Wall -Wextra -Werror -g

LIBFLAG = -Llib -lft
PRINTFLAG =  -Lft_printf -lftprintf
GNLFLAG =  -Lgnl -lgnl

INC = -I./includes/

SRC_DIR = ./srcs/

OBJ_DIR = ./objs/
BONUS_OBJ_DIR = ./bonus_objs/

SRC = \
	main.c \
	node_init.c \
	cmd.c \
	cmd_utils.c \
	sort.c \
	free.c \
	quick_sort.c \
	stack_utils.c \
	oper1.c \
	oper2.c \
	a_to_b.c \
	b_to_a.c \
	enum_work.c \
	utils.c \
	utils2.c \
	utils3.c \

BONUS_SRC = \
	node_init.c \
	cmd.c \
	cmd_utils.c \
	sort.c \
	free.c \
	quick_sort.c \
	stack_utils.c \
	oper1.c \
	oper2.c \
	a_to_b.c \
	b_to_a.c \
	enum_work.c \
	utils.c \
	utils2.c \
	utils3.c \
	bonus_part.c \

	
SRCS = $(addprefix $(SRCS_DIR), $(SRC))

OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

BONUS_OBJ = ${BONUS_SRC:.c=.o}
BONUS_OBJS = ${addprefix ${BONUS_OBJ_DIR}, ${BONUS_OBJ}}

all : ${NAME}

bonus : ${BONUS_NAME}

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR) srcs
	@$(CC) $(FLAG) ${INC} -c $< -o $@
	@printf	"${BLU}[BUILD - $(NAME)] '$<' $(END)"

$(BONUS_OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@mkdir -p $(BONUS_OBJ_DIR) srcs
	@$(CC) $(FLAG) ${INC} -c $< -o $@
	@printf	"${BLU}[BUILD - $(NAME)] '$<' $(END)"

$(NAME): $(OBJS)
	@make -C lib
	@make -C ft_printf
	@$(CC) ${LIBFLAG} ${PRINTFLAG} ${OBJS} -o ${NAME}

${BONUS_NAME} : ${BONUS_OBJS}
	@make -C lib
	make -C ft_printf
	make -C gnl
	$(CC) ${GNLFLAG} ${PRINTFLAG} ${LIBFLAG} ${BONUS_OBJS} -o ${BONUS_NAME}
	
clean :
	@rm -rf ./objs
	@make clean -C lib
	@make clean -C ft_printf
	@make clean -C gnl
	@echo "${RED}[CLEAN]${RST} done"
	
fclean : clean
	@make fclean -C lib/
	@make fclean -C ft_printf
	@make fclean -C gnl
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@echo "${RED}[FCLEAN]${RST} done"

re : 
	@make fclean 
	@make all

.PHONY: all clean fclean re bonus
