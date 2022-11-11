/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:51:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/11 15:03:52 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	work_parent_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror_n_exit("Error\ninvalid outfile\n");
	if (dup2(data->fds[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
		perror("fd error\n");
	close(data->fds[1]);
	nav = argv_init(3, data);
	if (!nav)
		perror_n_exit("malloc");
	path = ft_path(nav[0], data->paths);
	if (!path)
		perror_n_exit("");
	if (execve(path, nav, data->env) == -1)
		perror_n_exit("Error\nexecve() fail\n");
}

void	work_child_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		perror_n_exit("Error\ninvalid infile\n");
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(data->fds[1], STDOUT_FILENO) == -1)
		perror_n_exit("fd error\n");
	close(data->fds[0]);
	if (!nav)
		perror_n_exit("");
	path = ft_path(nav[0], data->paths);
	if (!path)
		perror_n_exit("");
	if (execve(path, nav, data->env) == -1)
		perror_n_exit("Error\nexecve() fail\n");
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	pid_t	pid;

	if (ac != 5)
		perror_n_exit("pipex: Invaild argument\n");
	parse_data(&data, ac, av, envp);
	find_path(&data);
	if (pipe(data.fds) == -1)
		perror_n_exit("Error\npipe err\n");
	pid = fork();
	if (pid == -1)
		perror_n_exit("Error\nfork err\n");
	if (pid == 0)
		work_child_process(&data);
	else
		work_parent_process(&data);
	return (EXIT_SUCCESS);
}
