/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:11:20 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/19 22:16:05 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	a;
	int	swap;

	a = size -1;
	i = 0;
	while (i < a)
	{
		swap = tab[i];
		tab[i] = tab[a];
		tab[a] = swap;
		i++;
		a--;
	}
}
