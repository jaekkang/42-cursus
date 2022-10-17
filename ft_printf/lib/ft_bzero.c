/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:23:40 by jaekkang          #+#    #+#             */
/*   Updated: 2022/07/07 21:55:12 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ret;
	size_t			i;
	int				value;

	i = 0;
	value = 0;
	ret = (unsigned char *)s;
	while (i < n)
	{
			ret[i] = (unsigned char)value;
			i++;
	}
}
