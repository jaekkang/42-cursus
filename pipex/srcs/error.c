/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:42:02 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 16:11:09 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	perror_n_exit(char *msg, int errornum)
{
	msg = ft_strjoin("pipex: ", msg);
	if (errornum == ARGC)
		ft_putstr_fd("pipex: Invaild argument\n", STDERR_FILENO);
	else if (errornum == COMMAND)
	{
		msg = ft_strjoin(msg, ": command not found\n");
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(EXIT_COMMAND);
	}
	else if (errornum == PERMISSION)
	{
		msg = ft_strjoin(msg, ": permission denied\n");
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(EXIT_PERMOSSION);
	}
	else
		perror(msg);
	exit(EXIT_FAILURE);
}
