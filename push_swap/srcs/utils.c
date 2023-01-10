/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:13:34 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 14:43:45 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_node(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

t_node	*ft_newnode(int num)
{
	t_node	*ret_node;

	ret_node = (t_node *)malloc(sizeof(t_node));
	if (!ret_node)
		exit(1);
	ret_node->value = num;
	ret_node->pre = ret_node;
	ret_node->next = ret_node;
	return (ret_node);
}

void	ft_add_node(t_node **a, t_node *node)
{
	if (!*a)
		*a = node;
	else
	{
		(*a)->pre->next = node;
		node->pre = (*a)->pre;
		(*a)->pre = node;
		node->next = (*a);
	}
}
