/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 18:44:36 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nodes(t_node **a, t_node **b, int len)
{
	if (len <= 3)
		sort_3_arg(a, b, len);
	else if (len <= 4)
		sort_4_arg(a, b, len);
	else if (len <= 5)
		sort_5_arg(a, b, len);
	else
		a_to_b(a, b, len);
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
	if (is_double_val(&a))
		print_err_msg();
	if (len == 2 && !is_sorted(&a, 2))
		enum_work("sa", &a, &b);
	else if (len >= 3 && !is_sorted(&a, len))
		sort_nodes(&a, &b, len);
	return (0);
}
