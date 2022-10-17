/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:57:35 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/06 20:24:28 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int	i;
	int	count;

	count = max - min;
	i = 0;
	if (min >= max)
	{
		ret = NULL;
		return (0);
	}
	ret = malloc(sizeof(int) * (count + 1));
	if (!(ret))
		return (-1);
	while (i < count)
		ret[i++] = min++;
	*range = ret;
	return (i);
}
