/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:47 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/04 19:15:15 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	oper_s(t_node **stack)
{
	int	tmp;

	if (!(*stack))
		return (0);
	tmp = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = tmp;
	return (1);
}

int	oper_r(t_node **stack)
{
	if (!*stack)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

int	oper_rr(t_node **stack)
{
	if (!*stack)
		return (0);
	*stack = (*stack)->pre;
	return (1);
}

int	oper_rrr(t_node **a, t_node **b)
{
	if (!oper_rr(a) || !oper_rr(b))
		return (0);
	return (1);
}

int	oper_p(t_node **a, t_node **b, char target)
{
	if (target == 'a' && push_node(a, pop_node(b)))
	{
		return (1);
	}
	else if (target == 'b' && push_node(b, pop_node(a)))
	{
		return (1);
	}
	return (0);
}
