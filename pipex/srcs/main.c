/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:51:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/03 15:33:37 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char **av, char **envp)
{
	int	fds[2];
	int	child_num = 0;
	pid_t pid = fork();
	printf("access return : %d\n", access("infile", X_OK | R_OK ));
	pipe(fds);
	if (pid != 0)
	{
		child_num++;
		pid = fork();
		close(fds[0]);
		close(fds[1]);
	}
	else
	{
		if (child_num == 0)
		{
			execvp("ls", &av[1]);
			close(fds[0]);
		}
		else if (child_num == 1)
		{
			printf("second\n");
			close(fds[1]);
		}
		printf("hello\n");
	}
	return (0);
}
