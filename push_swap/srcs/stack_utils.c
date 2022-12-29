/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:42:53 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/27 01:17:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_node(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (!*list)
		return (0);
	if (*list == (*list)->pre)
		*list = 0;
	else
	{
		(*list)->next->pre = (*list)->pre;
		(*list)->pre->next = (*list)->next;
		(*list) = (*list)->pre;
		tmp->pre = tmp;
		tmp->next = tmp;
	}
	return (tmp);
}

int	push_node(t_node **dst, t_node *src)
{
	if (!src)
		return (1);
	if (*dst)
	{
		(*dst)->next->pre = src;
		src->next = (*dst)->next;
		(*dst)->next = src;
		src->pre = *dst;
	}
	*dst = src;
	return (1);
}
