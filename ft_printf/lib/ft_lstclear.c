/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:49:19 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 17:07:56 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*res;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		res = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = res;
	}
	*lst = NULL;
}
