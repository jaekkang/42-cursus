/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:39:21 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:12:07 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		if (strs[i])
			free(strs[i]);
	}
	free(strs);
}

void	ft_nodeclear(t_node *lst)
{
	t_node	*res;

	if (lst == NULL)
		return ;
	lst->pre->next = NULL;
	while (lst)
	{
		res = lst->next;
		free(lst);
		lst = res;
	}
}
