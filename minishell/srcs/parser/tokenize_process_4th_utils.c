/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_process_4th_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:24:59 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/20 13:33:11 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_here_doc_acting(t_redir *new, char *tmp)
{
	char	*str;
	pid_t	pid;

	pid = fork_s();
	if (pid == 0)
	{
		ft_signal_child();
		while (1)
		{
			str = readline("> ");
			if (!str || ft_strcmp(tmp, str) == 0)
			{
				if (str)
					free_s(str);
				exit(0);
			}
			write(new->heredoc_fd, str, ft_strlen(str));
			write(new->heredoc_fd, "\n", 1);
			free_s(str);
		}
	}
}
