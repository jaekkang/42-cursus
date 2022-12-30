/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:34:33 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 19:05:04 by jaekkang         ###   ########.fr       */
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
}

void	grouping_stack_a(t_node **a, t_node **b, t_info *info)
{
	int	len;

	len = info->len;
	while (len--)
	{
		if ((*a)->value > info->pi2)
		{
			oper_r(a);
			ft_printf("ra\n");
			(info->cnt_ra)++;
		}
		else if ((*a)->value <= info->pi1)
		{
			oper_p(a, b, 'b');
			ft_printf("pb\n");
			(info->cnt_pb)++;
		}
		else
		{
			oper_p(a, b, 'b');
			oper_r(b);
			ft_printf("pb\n");
			ft_printf("rb\n");
			(info->cnt_pb)++;
			(info->cnt_rb)++;
		}
	}
}

void	a_to_b(t_node **a, t_node **b, int len)
{
	t_info	info;
	int		i;

	i = 0;
	if (len <= 3)
	{
		if (len == 2)
		{
			if ((*a)->value > (*a)->next->value)
			{
				oper_s(a);
				ft_printf("sa\n");
			}
		}
		if (len == 3)
		{
			oper_r(a);
			oper_s(a);
			oper_rr(a);
			if ((*a)->value > (*a)->next->value)
			{
				oper_s(a);
				ft_printf("sa\n");
			}
		}
		return ;
	}
	info = (t_info){0, };
	info.len = len;
	set_pivot(*a, len, &info, 'a');
	grouping_stack_a(a, b, &info);
	run_rrr(a, b, info.cnt_rb);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
	b_to_a(a, b, info.cnt_pb - info.cnt_rb);
}
