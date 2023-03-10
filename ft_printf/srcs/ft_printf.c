/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:40:00 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/13 13:47:34 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_type(const char **str, va_list ap)
{
	int		size;
	char	type;

	(*str)++;
	type = *(*str);
	size = -1;
	if (type == 'c')
		size = type_c(ap);
	else if (type == 's')
		size = type_s(ap);
	else if (type == 'd' || type == 'i')
		size = type_d(ap);
	else if (type == '%')
		size = type_per();
	else if (type == 'x' || type == 'X')
		size = type_x(type, ap);
	else if (type == 'u')
		size = type_u(ap);
	else if (type == 'p')
		size = type_p(ap);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		size;
	int		length;
	va_list	ap;

	size = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			length = ft_print_type(&str, ap);
			if (length == -1)
				return (-1);
			size += length;
		}
		else
			size += ft_putchar(*str);
		str++;
	}	
	va_end(ap);
	return (size);
}

int check_op(const char **str, va_list ap)
{
	int size;
	char type;
	
	(*str)++;
	type = *(*str);
	size = -1;
	if (type == 'i')
		size = check_i(ap);
	return (size);
}

int check_i(va_list ap)
{
	va_arg(ap, int);
}