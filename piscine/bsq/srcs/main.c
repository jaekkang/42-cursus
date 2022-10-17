/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:13:35 by myko              #+#    #+#             */
/*   Updated: 2022/06/08 17:51:49 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_struct.h"
#include <stdlib.h>

t_pos	initialize_position(void);
t_pos	find_max_square(char **board, t_words word, t_pos max_pos);
void	print_answer(char **board, t_words word, t_pos max_pos);
int		ft_atoi(char *str);
int		ft_read();
//들어온 입력값 중 첫 줄만 받음
// t_words	find_words(char *words)
// {
// 	int		i;
// 	char	num[];
// 	t_words	words;

// 	i = -1;
// 	while (words[++i])
// 	{
// 		while ('0' <= words[i] && words[i] <= '9')
// 		{
// 		}
// 	}
// }

int	main(void)
{
	int		i;
	t_words	word;
	t_pos	max_pos;
	char	**board;

	i = -1;
	board = (char **)malloc(sizeof(char *) * 10);
	while (++i < 10)
		*(board + i) = (char *)malloc(sizeof(char) * 28);
	ft_read();

	*(board) = "...........................\0";
	*(board + 1) = "....o......................\0";
	*(board + 2) = "............o..........o...\0";
	*(board + 3) = "...........................\0";
	*(board + 4) = "....o............o.........\0";
	*(board + 5) = ".............o.............\0";
	*(board + 6) = "...........................\0";
	*(board + 7) = "......o..............o.....\0";
	*(board + 8) = "..o.......o................\0";
	*(board + 9) = 0;
	word.col = 27;
	word.row = 9;
	word.empty = '.';
	word.filled = 'x';
	word.obstacle = 'o';
	max_pos = find_max_square(board, word, initialize_position());
	print_answer(board, word, max_pos);
	return (0);
}
