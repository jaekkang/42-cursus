/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:25:17 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/28 21:44:08 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_error(char *base)
{
	int	idx;
	int	i;

	i = 0;
	idx = 0;
	while (base[i])
	{
		idx = i;
		while (base[idx])
		{
			idx++;
			if (base[i] == base[idx])
				return (0);
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
			|| base[i] == '\f' || base[i] == ' ' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v')
			return (0);
		i++;
	}
	return (1);
}

int	ft_change_print(char *str, char *base, int size)
{
	int	check;
	int	result;
	int	idx;

	result = 0;
	check = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			check *= -1;
		str++;
	}
	while (*str)
	{	
		idx = -1;
		while (++idx <= size)
			if (base[idx] == *str)
				result = result * size + (idx);
		str++;
	}
	return (result * check);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;

	size = 0;
	while (base[size])
		size++;
	if (size < 2)
		return (0);
	if (ft_check_error(base))
		return (ft_change_print(str, base, size));
	return (0);
}
