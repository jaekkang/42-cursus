# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:13:14 by jaekkang          #+#    #+#              #
#    Updated: 2022/12/29 14:07:32 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC_NAME = ft_printf.c \
			ft_print_op.c \
			ft_print_op2.c \
			ft_utils.c \
			ft_utils2.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC_LINK = -I./includes

$(NAME): $(OBJ)
	ar rc $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INC_LINK) -c $< -o $@ 


all : $(NAME)

clean :
	@rm -rf ./obj

fclean : clean
	@rm -rf ./obj $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
