# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:13:14 by jaekkang          #+#    #+#              #
#    Updated: 2023/01/10 20:49:27 by jaekkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
FLAGS = -Wall -Wextra -Werror

HEADER = get_next_line.h

SRCS = \
get_next_line.c \
get_next_line_utils.c
	
OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	ar rc $@ $^

.c.o :
	gcc $(FLAGS) -c $< -I ${HEADER} -o $@

all : $(NAME)

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
