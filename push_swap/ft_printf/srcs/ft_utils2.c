/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:39:20 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/18 13:46:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

void	ft_putunnbr(unsigned int nb)
{
	if (nb > 9)
		ft_putunnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static void	ft_putptr_2(uintptr_t ptr, int *ret, char *base)
{
	if (ptr > 15)
		ft_putptr_2(ptr / 16, ret, base);
	(*ret)++;
	ft_putchar(base[ptr % 16]);
}

int	ft_putptr(uintptr_t ptr)
{
	int	ret;

	ret = 0;
	ft_putptr_2(ptr, &ret, "0123456789abcdef");
	return (ret);
}
