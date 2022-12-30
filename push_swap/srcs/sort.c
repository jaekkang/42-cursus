/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:45:52 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 16:58:34 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_node_value(t_node **a, int len)
{
	int	ret;
	int	i;

	i = -1;
	ret = (*a)->value;
	while (++i < len)
	{
		if (ret > (*a)->value)
			ret = (*a)->value;
		(*a) = (*a)->pre;
	}
	return (ret);
}

int	get_middle_node_value(t_node **a, int len)
{
	int	*tmp;
	int	ret;

	tmp = get_int_arr(*a, len);
	quick_sort(tmp, 0, len - 1);
	ret = tmp[len / 2];
	return (ret);
}

void	sort_3_arg(t_node **a, int len, char target)
{
	if (len == 2)
	{
		if ((*a)->value > (*a)->pre->value)
		{
			ft_swap_node(*a, (*a)->pre);
		}
		if (target == 'b')
		{
			ft_printf("sb\n");
			return ;
		}
		ft_printf("sa\n");
	}
	else if (len == 3)
	{
		if ((*a)->value == get_min_node_value(a, len))
		{
			if ((*a)->pre->value > (*a)->next->value)
			{
				oper_r(a);
				ft_printf("ra\n");
				ft_swap_node((*a)->pre, (*a)->pre->pre);
				ft_printf("sa\n");
				oper_rr(a);
				ft_printf("rra\n");
			}
		}
		else if ((*a)->next->value == get_min_node_value(a, len))
		{
			if ((*a)->value > (*a)->pre->value)
			{
				ft_swap_node((*a), (*a)->pre);
				ft_printf("sa\n");
				oper_rr(a);
				ft_printf("rra\n");
			}
			else
			{
				oper_rr(a);
				ft_printf("rra\n");
			}
		}
		else if ((*a)->pre->value == get_min_node_value(a, len))
		{
			if ((*a)->value > (*a)->next->value)
			{
				oper_r(a);
				ft_printf("ra\n");
			}
			else
			{
				{
					oper_s(a);
					ft_printf("sa\n");
				}
			}
		}
	}
}

void	sort_5_arg(t_node **a, t_node **b, int len)
{
	int	pi;
	int	i;

	pi = get_middle_node_value(a, len);
	i = -1;
	while (++i < pi)
	{
		if ((*a)->value < pi)
		{
			oper_p(a, b, 'b');
			ft_printf("pb\n");
		}
		(*a) = (*a)->pre;
	}
	(*a) = (*a)->pre;
	sort_3_arg(a, len / 2, 'a');
	sort_3_arg(b, len / 2, 'b');
	oper_p(a, b, 'a');
	ft_printf("pa\n");
	oper_p(a, b, 'a');
	ft_printf("pa\n");
	oper_s(a);
	ft_printf("sa\n");
	print_node(a, len);
}
