/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:33:33 by myko              #+#    #+#             */
/*   Updated: 2023/04/17 21:33:33 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env_node *head)
{
	char	*path;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
		tmp = ft_getenv(head, "PWD");
	path = ft_strjoin_s(tmp, "\n");
	free_s(tmp);
	ft_putstr_fd(path, STDOUT_FILENO);
	free_s(path);
	g_exit_status = 0;
}
