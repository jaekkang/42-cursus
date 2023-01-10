/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:01:29 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:26:39 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_cmd **cmd)
{
	t_cmd	*next;

	while ((*cmd))
	{
		ft_printf("%s\n", (*cmd)->value);
		next = (*cmd)->next;
		free((*cmd));
		(*cmd) = next;
	}
}

t_cmd	*ft_lstnew_cmd(char *content)
{
	t_cmd	*ret_list;

	ret_list = (t_cmd *)malloc(sizeof(t_cmd));
	if (!ret_list)
		return (0);
	ret_list->next = NULL;
	ret_list->value = content;
	return (ret_list);
}

t_cmd	*ft_lstlast_cmd(t_cmd *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new_list)
{
	t_cmd	*last;

	if (!lst || !new_list)
		return ;
	if (!*lst)
	{
		*lst = new_list;
		return ;
	}
	last = ft_lstlast_cmd(*lst);
	last->next = new_list;
}

void	add_cmd(t_cmd **cmd, char *op)
{
	t_cmd	*tmp;

	tmp = ft_lstnew_cmd(op);
	ft_lstadd_back_cmd(cmd, tmp);
}
