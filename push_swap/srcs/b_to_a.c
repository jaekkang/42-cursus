/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:10:32 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 18:47:59 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_3(t_node **a, t_node **b, int len)
{
	if (len != 1)
	{
		if ((*b)->value < (*b)->next->value)
			enum_work("sb", a, b);
		if (len == 3)
		{
			if (!is_sorted_row(b, len))
			{
				enum_work("rb", a, b);
				enum_work("sb", a, b);
				enum_work("rrb", a, b);
				if ((*b)->value < (*b)->next->value)
					enum_work("sb", a, b);
			}
			enum_work("pa", a, b);
		}
		enum_work("pa", a, b);
	}
	enum_work("pa", a, b);
}

void	grouping_stack_b(t_node **a, t_node **b, t_info *info)
{
	int	len;

	len = info->len;
	while (len--)
	{
		if ((*b)->value >= info->pi2)
		{
			enum_work("pa", a, b);
			info->cnt_pa++;
		}
		else if ((*b)->value < info->pi1)
		{
			enum_work("rb", a, b);
			info->cnt_rb++;
		}
		else
		{
			enum_work("pa", a, b);
			enum_work("ra", a, b);
			info->cnt_pa++;
			info->cnt_ra++;
		}
	}
}

void	b_to_a(t_node **a, t_node **b, int len)
{
	t_info	info;

	if (len <= 3)
	{
		sort_b_3(a, b, len);
		return ;
	}
	info = (t_info){0, };
	info.len = len;
	set_pivot(*b, len, &info, 'b');
	grouping_stack_b(a, b, &info);
	a_to_b(a, b, info.cnt_pa - info.cnt_ra);
	run_rrr(a, b, info.cnt_ra);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
}
