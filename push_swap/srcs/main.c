/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:30:36 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nodes(t_node **a, t_node **b, t_cmd **cmd, int len)
{
	if (len <= 3)
		sort_3_arg(a, b, len, cmd);
	else if (len <= 4)
		sort_4_arg(a, b, len, cmd);
	else if (len <= 5)
		sort_5_arg(a, b, len, cmd);
	else
		a_to_b(a, b, cmd, len);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_cmd		*cmd;
	int			len;
	char		*str;

	if (ac < 2)
		return (0);
	len = get_nodes_size(ac, av);
	str = sum_arg(ac, av);
	init_nodes_stack(str, &a, &b, &cmd);
	free(str);
	if (is_double_val(&a))
		print_err_msg();
	if (len == 2 && !is_sorted(&a, 2))
		enum_work("sa", &a, &b, &cmd);
	else if (len >= 3 && !is_sorted(&a, len))
		sort_nodes(&a, &b, &cmd, len);
	cut_cmd(&cmd);
	print_cmd(&cmd);
	ft_nodeclear(a);
	return (0);
}
