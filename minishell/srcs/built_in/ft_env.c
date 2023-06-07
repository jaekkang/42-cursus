/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:33:33 by myko              #+#    #+#             */
/*   Updated: 2023/04/17 21:33:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env_node *head)
{
	g_exit_status = 0;
	head = head->next;
	while (head)
	{
		if (head->value)
			printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}
