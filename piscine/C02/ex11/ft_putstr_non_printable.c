/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:56:52 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/25 03:05:27 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*base;
	char	first_unit;
	char	second_unit;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else if (str[i] < 32 || str[i] == 127)
		{
			first_unit = base[(unsigned char)str[i] / 16];
			second_unit = base[(unsigned char)str[i] % 16];
			ft_putchar('\\');
			ft_putchar(first_unit);
			ft_putchar(second_unit);
		}
		i++;
	}
}
