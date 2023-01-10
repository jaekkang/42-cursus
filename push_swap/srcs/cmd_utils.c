/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:56 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:32:30 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cmddelone(t_cmd *lst)
{
	if (lst == NULL)
		return ;
	lst->value = 0;
	free(lst);
}

void	check_cmd_r(t_cmd **lst)
{
	t_cmd	*tmp;
	t_cmd	*del;

	tmp = (*lst);
	if (tmp->next == NULL)
		return ;
	if ((!ft_strncmp(tmp->value, "ra", 2) && \
		!ft_strncmp(tmp->next->value, "rb", 2)) || \
			(!ft_strncmp(tmp->value, "rb", 2) && \
				!ft_strncmp(tmp->next->value, "ra", 2)))
	{
		tmp->value = "rr";
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
	}
}

void	check_cmd_s(t_cmd **lst)
{
	t_cmd	*tmp;
	t_cmd	*del;

	tmp = (*lst);
	if (tmp->next == NULL)
		return ;
	if ((!ft_strncmp(tmp->value, "sa", 2) && \
		!ft_strncmp(tmp->next->value, "sb", 2)) || \
			(!ft_strncmp(tmp->value, "sb", 2) && \
				!ft_strncmp(tmp->next->value, "sa", 2)))
	{
		tmp->value = "ss";
		del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
	}
}

void	cut_cmd(t_cmd **lst)
{
	t_cmd	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->value, "s", 1))
			check_cmd_s(&tmp);
		else if (!ft_strncmp(tmp->value, "r", 1))
			check_cmd_r(&tmp);
		tmp = tmp->next;
	}
}
