/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:46:45 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/01 11:42:00 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_cnt = 0;

void	print_queen(char *result)
{
	int	i;

	i = 0;
	while (i < 10)
		write(1, &result[i++], 1);
	write(1, "\n", 1);
	g_cnt++;
}

void	bt(int check[], char *result, int depth)
{
	int	i;

	i = -1;
	if (depth == 10)
		print_queen(result);
	else
	{
		while (++i < 10)
		{
			if (!(check[i] || check[i + depth + 10] || check[i - depth + 39]))
			{
				check[i] = 1;
				check[i + depth + 10] = 1;
				check[i - depth + 39] = 1;
				result[depth] = i + '0';
				bt(check, result, depth + 1);
				check[i] = 0;
				check[i + depth + 10] = 0;
				check[i - depth + 39] = 0;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	int		check[50];
	char	result[10];

	i = 0;
	while (i < 50)
		check[i++] = 0;
	bt(check, result, 0);
	return (g_cnt);
}
