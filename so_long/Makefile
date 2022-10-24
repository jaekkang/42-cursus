# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 11:49:24 by jaekkang          #+#    #+#              #
#    Updated: 2022/10/24 15:52:01 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU	= \033[0;34m
GRN	= \033[0;32m
RED	= \033[0;31m
RST	= \033[0m
END	= \e[0m

NAME = so_long
NAME_BONUS	= so_long_bonus

CC = gcc
FLAG = -Wall -Wextra -Werror
MLB_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit -Llib -lft -Lgnl -lgnl

INC = -I./includes/
INC_BONUS = -I./includes_bonus/

SRC_DIR = ./srcs/
SRC_BONUS_DIR = ./srcs_bonus/

OBJ_DIR = ./objs/
OBJ_BONUS_DIR = ./objs_bonus/

SRC = \
	main.c \
	utils.c \
	map.c \
	init.c \
	move.c \
	map_check.c \
	chac.c \

SRC_BONUS = \
	main_bonus.c \
	utils_bonus.c \
	map_bonus.c \
	init_bonus.c \
	move_bonus.c \
	map_check_bonus.c \
	chac_bonus.c \
	
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJ = ${SRCS:.c=.o}
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

SRCS_BONUS	=	$(addprefix $(SRCS_BONUS_DIR), $(SRC_BONUS))
OBJ_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(OBJ_BONUS))

		
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

bonus : ${NAME_BONUS}

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@mkdir -p $(OBJ_BONUS_DIR) srcs_bonus
	@$(CC) $(FLAG) ${INC_BONUS} -c $< -o $@
	@printf	"${BLU}[BUILD - $(NAME_BONUS)] '$<' $(END)"

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C mlx
	@printf "${BLU}[MLX library]${END} Load Good!\n"
	@make -C lib
	@printf "${BLU}[LIB library]${END} Load Good!\n"
	@make -C gnl
	@printf "${BLU}[GNL library]${END} Load Good!\n"
	@$(CC)  $(MLB_FLAG) ${OBJS_BONUS} -o ${NAME_BONUS}
	@printf "${GRN}[READY!] $(NAME_BONUS) $(END) You can start!\n"

clean :
	@rm -rf ./objs
	@rm -rf ./objs_bonus
	@make clean -C lib
	@make clean -C gnl
	@echo "${RED}[CLEAN]${RST} done"
	
fclean : clean
	@make clean -C mlx
	@make fclean -C lib
	@make fclean -C gnl
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "${RED}[FCLEAN]${RST} done"

re : 
	make fclean 
	make all

.PHONY: all clean fclean re bonus
