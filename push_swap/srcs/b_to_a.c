/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:10:32 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 19:21:02 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grouping_stack_b(t_node **a, t_node **b, t_info *info)
{
	int	len;

	len = info->len;
	while (len--)
	{
		if ((*b)->value >= info->pi2)
		{
			oper_p(a, b, 'b');
			ft_printf("pb\n");
			info->cnt_pb++;
		}
		else if ((*b)->value < info->pi1)
		{
			oper_r(b);
			ft_printf("rb\n");
			info->cnt_rb++;
		}
		else
		{
			oper_p(a, b, 'b');
			oper_r(a);
			ft_printf("pb\n");
			ft_printf("ra\n");
			info->cnt_pb++;
			info->cnt_ra++;
		}
	}
}

void	b_to_a(t_node **a, t_node **b, int len)
{
	t_info	info;

	info = (t_info){0, };
	if (len <= 3)
	{
		if (len == 2)
		{
			if ((*b)->value < (*b)->next->value)
			{
				oper_s(b);
				ft_printf("sb\n");
			}
		}
		if (len == 3)
		{
			oper_r(b);
			oper_s(b);
			oper_rr(b);
			if ((*b)->value < (*b)->next->value)
			{
				oper_s(b);
				ft_printf("sb\n");
			}
			oper_p(a, b, 'a');
		}
		oper_p(a, b, 'a');
		oper_p(a, b, 'a');
		return ;
	}
	info.len = len;
	set_pivot(*b, len, &info, 'b');
	grouping_stack_b(a, b, &info);
	a_to_b(a, b, info.cnt_pa - info.cnt_ra);
	run_rrr(a, b, info.cnt_ra);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
}
