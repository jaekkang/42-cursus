/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:57:16 by jaekkang          #+#    #+#             */
/*   Updated: 2022/08/29 19:57:40 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_length(long long num, int base)
{
	int			length;

	if (num == 0)
		return (1);
	length = 0;
	if (num < 0)
	{
		num *= -1;
		length++;
	}
	while (num)
	{
		num /= base;
		length++;
	}
	return (length);
}

int	ft_convert_base(unsigned int nb, const char *base)
{
	int		size;
	char	*ret;

	size = 0;
	if (nb == 0)
		size = 1;
	size = ft_num_length((long long)nb, 16);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = '\0';
	while (nb)
	{
		ret[--size] = base[nb % 16];
		nb /= 16;
	}
	size = ft_putstr(ret);
	free(ret);
	return (size);
}
