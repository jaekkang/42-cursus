/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:43:22 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/06 16:45:24 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tab[++i] != '\0')
	{
		if ((*f)(tab[i]) != 0)
			count += 1;
	}
	return (count);
}
