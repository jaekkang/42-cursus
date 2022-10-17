/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:31:59 by myko              #+#    #+#             */
/*   Updated: 2022/06/08 06:01:43 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq_struct.h"

int		ft_sqrt(int nb);
int		min(t_pos coor, char **dp);
int		ft_str_len(char *str);
t_pos	initialize_position(void);

void	initialize(char **board, t_words word, t_pos coor, char **dp)
{
	while (++coor.y < word.row)
	{
		dp[coor.y] = (char *)malloc(sizeof(char) * (word.col + 1));
		if (dp[coor.y] == 0)
			return ;
	}
	coor.y = -1;
	while (++coor.y < word.row)
	{
		coor.x = -1;
		while (++coor.x < word.col)
		{
			if (board[coor.y][coor.x] == word.obstacle)
				dp[coor.y][coor.x] = 0;
			else if (coor.x == 0 || coor.y == 0)
				dp[coor.y][coor.x] = 1;
			else
				dp[coor.y][coor.x] = min(coor, dp) + 1;
		}
	}
}

t_pos	check_max(t_pos max_pos, t_pos coor, char **dp)
{
	if (max_pos.length < dp[coor.y][coor.x])
	{
		max_pos.x = coor.x;
		max_pos.y = coor.y;
		max_pos.length = dp[coor.y][coor.x];
	}
	return (max_pos);
}

t_pos	find_max_square(char **board, t_words word, t_pos max_pos)
{
	char	**dp;
	t_pos	coor;

	coor.y = -1;
	dp = (char **)malloc(sizeof(char *) * (word.row + 1));
	if (dp == 0)
	{
		coor.x = 0;
		coor.y = 0;
		coor.length = 0;
		return (coor);
	}
	initialize(board, word, coor, dp);
	coor.y = -1;
	while (++coor.y < word.row)
	{
		coor.x = -1;
		while (++coor.x < word.col)
			max_pos = check_max(max_pos, coor, dp);
	}
	return (max_pos);
}

int	check_filled(t_pos max_pos, int y, int x)
{
	if ((max_pos.x - max_pos.length < x && x <= max_pos.x)
		&& (max_pos.y - max_pos.length < y && y <= max_pos.y))
		return (1);
	return (0);
}

void	print_answer(char **board, t_words word, t_pos max_pos)
{
	int	y;
	int	x;

	y = -1;
	while (++y < word.row)
	{
		x = -1;
		while (++x < word.col)
		{
			if (check_filled(max_pos, y, x))
				write(1, &word.filled, 1);
			else
				write(1, &board[y][x], 1);
		}
		write(1, "\n", 1);
	}
}
