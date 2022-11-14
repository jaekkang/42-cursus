/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:51:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 15:42:17 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	work_parent_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[4], O_RDWR | O_CREAT | O_TRUNC, 420);
	if (fd == -1)
		perror_n_exit("fd", FD_ERROR);
	if (dup2(data->fds[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
		perror_n_exit("fd", FD_ERROR);
	close(data->fds[1]);
	nav = argv_init(3, data);
	if (!nav)
		perror_n_exit("malloc", MALLOC_ERROR);
	path = ft_path(nav[0], data->paths);
	if (!path)
		perror_n_exit(nav[0], COMMAND_ERROR);
	if (execve(path, nav, data->env) == -1)
		perror_n_exit(nav[0], RUN_ERROR);
}

void	work_child_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		perror_n_exit(data->av[1], FD_ERROR);
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(data->fds[1], STDOUT_FILENO) == -1)
		perror_n_exit("fd", FD_ERROR);
	close(data->fds[0]);
	nav = argv_init(2, data);
	if (!nav)
		perror_n_exit("malloc", MALLOC_ERROR);
	path = ft_path(nav[0], data->paths);
	if (!path)
		perror_n_exit(nav[0], COMMAND_ERROR);
	if (execve(path, nav, data->env) == -1)
		perror_n_exit(nav[0], RUN_ERROR);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	pid_t	pid;

	if (ac != 5)
		perror_n_exit("", ARGC_ERROR);
	data.av = av;
	data.env = envp;
	find_path(&data);
	if (pipe(data.fds) == -1)
		perror_n_exit("pipe", PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		perror_n_exit("fork", FORK_ERROR);
	if (pid == 0)
		work_child_process(&data);
	else
		work_parent_process(&data);
	return (EXIT_SUCCESS);
}
