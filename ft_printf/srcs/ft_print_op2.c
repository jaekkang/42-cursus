/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_op2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:00:50 by jaekkang          #+#    #+#             */
/*   Updated: 2022/08/29 19:58:51 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_u(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	ft_putunnbr(num);
	return (ft_num_length(num, 10));
}

int	type_p(va_list ap)
{
	int		size;
	void	*ptr;

	size = 2;
	ptr = va_arg(ap, void *);
	ft_putstr("0x");
	size += ft_putptr((uintptr_t)ptr);
	return (size);
}
