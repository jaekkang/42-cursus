/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:23:32 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/05 13:45:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	max_count;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	max_count = max - min;
	ret = (int *)malloc(sizeof(int) * (max_count + 1));
	if (!ret)
		return (NULL);
	while (i < max_count)
		ret[i++] = min++;
	return (ret);
}
