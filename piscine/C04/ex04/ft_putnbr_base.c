/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:39:26 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/28 14:40:02 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_change_print(int nbr, char *base, int size)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= size)
	{
		ft_change_print(n / size, base, size);
		ft_change_print(n % size, base, size);
	}
	else
		ft_putchar(base[n]);
}

int	ft_check_error(char *base)
{
	int	idx;
	int	i;

	i = 0;
	idx = 0;
	while (base[i] != '\0')
	{
		idx = i;
		while (base[idx] != '\0')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_strlen(base);
	if (size < 2)
		return ;
	if (ft_check_error(base))
		ft_change_print(nbr, base, size);
}
