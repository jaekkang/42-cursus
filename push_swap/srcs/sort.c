/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:45:52 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 17:15:33 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_arg(t_node **a, t_node **b, int len, t_cmd **cmd)
{
	if (len == 3)
	{
		if ((*a)->value == get_min_node_value(a) && !is_sorted(a, 3))
		{
			enum_work("rra", a, b, cmd);
			enum_work("sa", a, b, cmd);
		}
		else if ((*a)->pre->value == get_min_node_value(a))
		{
			if ((*a)->value > (*a)->next->value)
				enum_work("sa", a, b, cmd);
			enum_work("rra", a, b, cmd);
		}
		else if ((*a)->next->value == get_min_node_value(a))
		{
			if ((*a)->value < (*a)->pre->value)
				enum_work("sa", a, b, cmd);
			else
				enum_work("ra", a, b, cmd);
		}
	}
}

void	sort_4_arg(t_node **a, t_node **b, int len, t_cmd **cmd)
{
	t_info	info;
	int		pi;
	int		i;

	info = (t_info){0, };
	i = -1;
	if (is_sorted(a, len))
		return ;
	pi = get_middle_node_value(a, len);
	while (++i < len)
	{
		if ((*a)->value < pi)
		{
			enum_work("pb", a, b, cmd);
			info.cnt_pb++;
		}
		else
			enum_work("ra", a, b, cmd);
	}
	if (is_sorted(b, 2))
		enum_work("sb", a, b, cmd);
	if (!is_sorted(a, 2))
		enum_work("sa", a, b, cmd);
	while (info.cnt_pb-- > 0)
		enum_work("pa", a, b, cmd);
}

void	sort_5_arg(t_node **a, t_node **b, int len, t_cmd **cmd)
{
	t_info	info;
	int		pi;
	int		i;

	info = (t_info){0, };
	i = -1;
	pi = get_middle_node_value(a, len);
	if (is_sorted(a, len))
		return ;
	while (++i < len)
	{
		if ((*a)->value < pi)
		{
			enum_work("pb", a, b, cmd);
			info.cnt_pb++;
		}
		else
			enum_work("ra", a, b, cmd);
	}
	sort_3_arg(a, b, len - info.cnt_pb, cmd);
	if (!is_sorted_row(b, 2))
		enum_work("sb", a, b, cmd);
	while (info.cnt_pb-- > 0)
		enum_work("pa", a, b, cmd);
}
