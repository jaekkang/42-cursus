/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:43:24 by jaekkang          #+#    #+#             */
/*   Updated: 2022/07/12 20:29:59 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret_list;

	ret_list = (t_list *)malloc(sizeof(t_list));
	if (!ret_list)
		return (0);
	ret_list->next = NULL;
	ret_list->content = content;
	return (ret_list);
}
