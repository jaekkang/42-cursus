/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:18:32 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/07 20:38:10 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = -1;
	up = 0;
	down = 0;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			down += 1;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			up += 1;
	}
	if (down == i || up == i)
		return (1);
	return (0);
}
