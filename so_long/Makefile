# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:49:24 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/17 19:45:26 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU	= \033[0;34m
GRN	= \033[0;32m
RED	= \033[0;31m
RST	= \033[0m
END	= \e[0m

NAME = so_long
CC = gcc
FLAG = -Wall -Wextra -Werror
MLB_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit -Llib -lft -Lgnl -lgnl

INC = -I./includes/
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC = \
	main.c \
	utils.c \
	map.c \
	init.c \
	move.c \
	map_check.c \
	chac.c
	
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
	@make -C mlx
	@printf "${BLU}[MLX library]${END} Load Good!\n"
	@make -C lib
	@printf "${BLU}[LIB library]${END} Load Good!\n"
	@make -C gnl
	@printf "${BLU}[GNL library]${END} Load Good!\n"
	@$(CC)  $(MLB_FLAG) ${OBJS} -o ${NAME}
	@printf "${GRN}[READY!] $(NAME) $(END) You can start!\n"

clean :
	@rm -rf ./objs
	@make clean -C lib
	@make clean -C gnl
	@echo "${RED}[CLEAN]${RST} done"
fclean : clean
	@make clean -C mlx
	@make fclean -C lib
	@make fclean -C gnl
	@rm -f $(NAME)
	@echo "${RED}[FCLEAN]${RST} done"

re : 
	make fclean 
	make all

.PHONY: all clean fclean re
