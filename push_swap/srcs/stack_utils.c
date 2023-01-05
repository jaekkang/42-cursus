/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:42:53 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/04 18:24:11 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_node(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (!*list)
		return (0);
	if (*list == (*list)->next)
		*list = 0;
	else
	{
		(*list)->pre->next = (*list)->next;
		(*list)->next->pre = (*list)->pre;
		(*list) = (*list)->next;
		tmp->next = tmp;
		tmp->pre = tmp;
	}
	return (tmp);
}

int	push_node(t_node **dst, t_node *src)
{
	if (!src)
		return (1);
	if (*dst)
	{
		(*dst)->pre->next = src;
		src->pre = (*dst)->pre;
		(*dst)->pre = src;
		src->next = *dst;
	}
	*dst = src;
	return (1);
}
