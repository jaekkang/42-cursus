/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:51:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/03 23:03:40 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	work_parent_process(t_data *data)
{
	int	i;

	i = 0;
	while (data->paths[i] != NULL)
	{
		data->cmd2_path = ft_strjoin(data->paths[i], data->cmd2[0]);
		if (access(data->cmd2_path, X_OK) == 0)
			break ;
		i++;
		if (data->paths[i] == NULL)
			perror("Error\ncommand not found");
	}
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->out_fd, STDOUT_FILENO);
	close(data->fd[1]);
	if (execve(data->cmd2_path, data->cmd2, data->ep) == -1)
	{
		perror("Error\n");
		exit(1);
	}
}

void	work_child_process(t_data *data)
{
	int	i;

	i = 0;
	while (data->paths[i] != NULL)
	{
		data->cmd1_path = ft_strjoin(data->paths[i], data->cmd1[0]);
		if (access(data->cmd1_path, X_OK) == 0)
			break ;
		i++;
		if (data->paths[i] == NULL)
			perror("Error\ncommand not found");
	}
	dup2(data->in_fd, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	if (execve(data->cmd1_path, data->cmd1, data->ep) == -1)
	{
		perror("Error\n");
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
	{
		perror("Error\nneed 5 params only\n");
		exit(1);
	}
	parse_data(&data, ac, av, envp);
	find_path(&data);
	if (pipe(data.fd) == -1)
	{
		perror("Error\n-> in pipe\n");
		exit(1);
	}
	data.pid = fork();
	if (data.pid == -1)
	{
		perror("Error\n-> in fork()\n");
		exit(1);
	}
	if (data.pid == 0)
		work_child_process(&data);
	else
		work_parent_process(&data);
	return (0);
}
