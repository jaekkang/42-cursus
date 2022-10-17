/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:55 by jaekkang          #+#    #+#             */
/*   Updated: 2022/08/30 11:46:35 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(va_list ap)
{
	return (ft_putchar(va_arg(ap, int)));
}

int	type_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (ft_putstr(str));
}

int	type_d(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	ft_putnbr_fd(num, 1);
	return (ft_num_length(num, 10));
}

int	type_per(void)
{
	return (ft_putchar('%'));
}

int	type_x(char c, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	if (num == 0)
		return (ft_putchar('0'));
	if (c == 'X')
		return (ft_convert_base((unsigned int)num, "0123456789ABCDEF"));
	return (ft_convert_base((unsigned int)num, "0123456789abcdef"));
}
