# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:13:14 by jaekkang          #+#    #+#              #
#    Updated: 2022/09/21 11:36:49 by jaekkang         ###   ########.fr        #
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
	@$(MAKE) -C ./lib all
	cp ./lib/libft.a $@
	ar rc $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INC_LINK) -c $< -o $@ 


all : $(NAME)

clean :
	@$(MAKE) -C ./lib clean
	@rm -rf ./obj

fclean : clean
	@$(MAKE) -C ./lib fclean
	@rm -rf ./obj $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
