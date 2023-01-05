/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:56 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 17:52:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enum_work(char *op, t_node **a, t_node **b)
{
	if (!ft_strcmp(op, "sa") && oper_s(a))
		ft_printf("sa\n");
	else if (!ft_strcmp(op, "sb") && oper_s(b))
		ft_printf("sb\n");
	else if (!ft_strcmp(op, "ra") && oper_r(a))
		ft_printf("ra\n");
	else if (!ft_strcmp(op, "rb") && oper_r(b))
		ft_printf("rb\n");
	else if (!ft_strcmp(op, "rra") && oper_rr(a))
		ft_printf("rra\n");
	else if (!ft_strcmp(op, "rrb") && oper_rr(b))
		ft_printf("rrb\n");
	else if (!ft_strcmp(op, "pa") && oper_p(a, b, 'a'))
		ft_printf("pa\n");
	else if (!ft_strcmp(op, "pb") && oper_p(a, b, 'b'))
		ft_printf("pb\n");
	else if (!ft_strcmp(op, "rrr") && oper_rrr(a, b))
		ft_printf("rrr\n");
}
