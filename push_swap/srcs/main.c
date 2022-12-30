/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 18:23:50 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nodes(t_node **a, t_node **b, int len)
{
	if (len <= 3)
	{
		sort_3_arg(a, len, 'a');
		exit(0);
	}
	if (len <= 5)
	{
		sort_5_arg(a, b, len);
		exit(0);
	}
	a_to_b(a, b, len);
}

void	print_node(t_node **a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", (*a)->value);
		*a = (*a)->next;
		i++;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	int			len;
	char		*str;
	int			i;

	i = 0;
	if (ac < 2)
		return (0);
	len = get_nodes_size(ac, av);
	str = sum_arg(ac, av);
	init_nodes_stack(str, &a, &b);
	sort_nodes(&a, &b, len);
	print_node(&a, len);
	return (0);
}
