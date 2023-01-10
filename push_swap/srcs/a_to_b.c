/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:34:33 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:13:53 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pivot(t_node *stack, int len, t_info *info, char target)
{
	int	*arr;
	int	div;

	arr = get_int_arr(stack, len);
	quick_sort(arr, 0, len - 1);
	div = len / 3;
	if (len % 3 == 2)
		div++;
	if (target == 'a')
	{
		info->pi1 = arr[(len - 1) - (2 * div)];
		info->pi2 = arr[(len - 1) - div];
	}
	else if (target == 'b')
	{
		info->pi1 = arr[div];
		info->pi2 = arr[2 * div];
	}
	free(arr);
}

void	sort_a_3(t_node **a, t_node **b, int len, t_cmd **cmd)
{
	if (len != 1)
	{
		if ((*a)->value > (*a)->next->value)
			enum_work("sa", a, b, cmd);
		if (len == 3 && !is_sorted(a, len))
		{
			enum_work("ra", a, b, cmd);
			enum_work("sa", a, b, cmd);
			enum_work("rra", a, b, cmd);
			if ((*a)->value > (*a)->next->value)
				enum_work("sa", a, b, cmd);
		}
	}
}

void	grouping_stack_a(t_node **a, t_node **b, t_info *info, t_cmd **cmd)
{
	int	len;

	len = info->len;
	while (len--)
	{
		if ((*a)->value > info->pi2)
		{
			enum_work("ra", a, b, cmd);
			(info->cnt_ra)++;
		}
		else if ((*a)->value <= info->pi1)
		{
			enum_work("pb", a, b, cmd);
			(info->cnt_pb)++;
		}
		else
		{
			enum_work("pb", a, b, cmd);
			enum_work("rb", a, b, cmd);
			(info->cnt_pb)++;
			(info->cnt_rb)++;
		}
	}
}

void	a_to_b(t_node **a, t_node **b, t_cmd **cmd, int len)
{
	t_info	info;

	if (len <= 3)
	{
		if (!is_sorted(a, len))
			sort_a_3(a, b, len, cmd);
		return ;
	}
	info = (t_info){0, };
	info.len = len;
	set_pivot(*a, len, &info, 'a');
	grouping_stack_a(a, b, &info, cmd);
	run_rrr(a, b, info.cnt_rb, cmd);
	a_to_b(a, b, cmd, info.cnt_ra);
	b_to_a(a, b, cmd, info.cnt_rb);
	b_to_a(a, b, cmd, info.cnt_pb - info.cnt_rb);
}
