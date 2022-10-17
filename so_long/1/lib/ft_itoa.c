/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:10:02 by jaekkang          #+#    #+#             */
/*   Updated: 2022/07/08 10:10:44 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_number(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_count_number(n);
	i = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		i = 1;
	}
	while (len-- > i)
	{
		if (n < 0)
			ret[len] = n % 10 * -1 + '0';
		else
			ret[len] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}
