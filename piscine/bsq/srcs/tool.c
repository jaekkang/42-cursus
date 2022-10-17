/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:12:15 by myko              #+#    #+#             */
/*   Updated: 2022/06/08 05:57:23 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_struct.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		result = result * 10 + (str[i++] - '0') * sign;
	return (result);
}

int	min(t_pos coor, char **dp)
{
	int	tmp;

	if (dp[coor.y][coor.x - 1] < dp[coor.y - 1][coor.x])
		tmp = dp[coor.y][coor.x - 1];
	else
		tmp = dp[coor.y - 1][coor.x];
	if (tmp > dp[coor.y - 1][coor.x - 1])
		tmp = dp[coor.y - 1][coor.x - 1];
	return (tmp);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_pos	initialize_position(void)
{
	t_pos	pos;

	pos.x = -1;
	pos.y = -1;
	pos.length = -1;
	return (pos);
}
