/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:45:52 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 18:03:35 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_arg(t_node **a, t_node **b, int len)
{
	if (len == 3)
	{
		if ((*a)->value == get_min_node_value(a) && !is_sorted(a, 3))
		{
			enum_work("rra", a, b);
			enum_work("sa", a, b);
		}
		else if ((*a)->pre->value == get_min_node_value(a))
		{
			if ((*a)->value > (*a)->next->value)
				enum_work("sa", a, b);
			enum_work("rra", a, b);
		}
		else if ((*a)->next->value == get_min_node_value(a))
		{
			if ((*a)->value < (*a)->pre->value)
				enum_work("sa", a, b);
			else
				enum_work("ra", a, b);
		}
	}
}

void	sort_4_arg(t_node **a, t_node **b, int len)
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
			enum_work("pb", a, b);
			info.cnt_pb++;
		}
		else
			enum_work("ra", a, b);
	}
	if (is_sorted(b, 2))
		enum_work("sb", a, b);
	if (!is_sorted(a, 2))
		enum_work("sa", a, b);
	while (info.cnt_pb-- > 0)
		enum_work("pa", a, b);
}

void	sort_5_arg(t_node **a, t_node **b, int len)
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
			enum_work("pb", a, b);
			info.cnt_pb++;
		}
		else
			enum_work("ra", a, b);
	}
	sort_3_arg(a, b, len - info.cnt_pb);
	if (!is_sorted_row(b, 2))
		enum_work("sb", a, b);
	while (info.cnt_pb-- > 0)
		enum_work("pa", a, b);
}
