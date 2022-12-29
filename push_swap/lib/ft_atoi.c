/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:34:47 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/06 18:04:16 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (ret >= 922337203685477580 && *str > '6')
			return (-1);
		else if (ret <= -922337203685477580 && *str > '7')
			return (0);
		ret = ret * 10 + (*str - '0') * sign;
		str++;
	}
	return (ret);
}
