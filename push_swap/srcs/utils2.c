/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:23 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/29 17:44:32 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err_msg()
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_atoi_int(const char *str)
{
	long long	ret;
	int			sign;

	sign = 1;
	ret = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_err_msg();
		ret = ret * 10 + (*str - '0');
		str++;
	}
	ret *= sign;
	if (ret > 2147483647 || ret < -2147483648)
		print_err_msg();
	return (ret);
}
