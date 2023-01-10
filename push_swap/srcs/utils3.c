/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:53:24 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 14:41:34 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_node_value(t_node **a)
{
	t_node	*tmp;
	int		ret;

	ret = (*a)->value;
	tmp = (*a)->next;
	while (tmp != *a)
	{
		if (tmp->value > ret)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

int	get_min_node_value(t_node **a)
{
	t_node	*tmp;
	int		ret;

	tmp = (*a)->next;
	ret = (*a)->value;
	while (tmp != *a)
	{
		if (ret > tmp->value)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

int	get_middle_node_value(t_node **a, int len)
{
	int	*tmp;
	int	ret;
	int	i;

	i = -1;
	tmp = get_int_arr(*a, len);
	quick_sort(tmp, 0, len - 1);
	ret = tmp[(len / 2)];
	free(tmp);
	return (ret);
}

int	is_sorted(t_node **a, int len)
{
	t_node	*head;

	head = (*a);
	while (len-- > 1)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_sorted_row(t_node **a, int len)
{
	t_node	*head;

	head = (*a);
	while (len-- > 1)
	{
		if (head->value < head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
