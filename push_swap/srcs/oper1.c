/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:47 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 19:19:46 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_s(t_node **stack)
{
	int	tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
}

void	oper_r(t_node **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	return ;
}

void	oper_rr(t_node **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->pre;
}

void	oper_rrr(t_node **a, t_node **b)
{
	oper_rr(a);
	oper_rr(b);
	ft_printf("rrr\n");
}

void	oper_p(t_node **a, t_node **b, char target)
{
	if (target == 'a' && push_node(a, pop_node(b)))
	{
		ft_printf("pa\n");
	}
	else if (target == 'b' && push_node(b, pop_node(a)))
	{
		ft_printf("pb\n");
	}
}
