/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:51:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/16 16:45:10 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	path_init(t_data *data)
{
	data->paths = malloc(sizeof(char *) * 6);
	if (!data->paths)
		perror_n_exit("malloc", MALLOC);
	data->paths[0] = ft_strdup("/usr/local/bin");
	data->paths[1] = ft_strdup("/usr/bin");
	data->paths[2] = ft_strdup("/bin");
	data->paths[3] = ft_strdup("/usr/sbin");
	data->paths[4] = ft_strdup("/sbin");
	data->paths[5] = NULL;
}

static void	find_path(t_data *data)
{
	int		i;

	i = -1;
	while (data->env[++i])
	{
		if (ft_strncmp(data->env[i], "PATH", 4) == 0)
		{
			data->paths = ft_split(data->env[i] + 5, ':');
			break ;
		}
	}
	if (data->env[i] == NULL)
		path_init(data);
}

static void	work_parent_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[4], O_RDWR | O_CREAT | O_TRUNC, 420);
	if (fd == -1)
		perror_n_exit("fd", FD);
	if (dup2(data->fds[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
		perror_n_exit("fd", FD);
	close(data->fds[1]);
	nav = argv_init(3, data);
	if (!nav)
		perror_n_exit("malloc", MALLOC);
	path = path_check(nav[0], data->paths);
	if (!path)
		perror_n_exit(nav[0], COMMAND);
	if (execve(path, nav, data->env) == -1)
		perror_n_exit(nav[0], RUN);
}

static void	work_child_process(t_data *data)
{
	char	*path;
	char	**nav;
	int		fd;

	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		perror_n_exit(data->av[1], FD);
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(data->fds[1], STDOUT_FILENO) == -1)
		perror_n_exit("fd", FD);
	close(data->fds[0]);
	nav = argv_init(2, data);
	if (!nav)
		perror_n_exit("malloc", MALLOC);
	path = path_check(nav[0], data->paths);
	if (!path)
		perror_n_exit(nav[0], COMMAND);
	if (execve(path, nav, data->env) == -1)
		perror_n_exit(nav[0], RUN);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	pid_t	pid;

	if (ac != 5)
		perror_n_exit("", ARGC);
	data.av = av;
	data.env = envp;
	find_path(&data);
	if (pipe(data.fds) == -1)
		perror_n_exit("pipe", PIPE);
	pid = fork();
	if (pid == -1)
		perror_n_exit("fork", FORK);
	if (pid == 0)
		work_child_process(&data);
	else
		work_parent_process(&data);
	return (EXIT_SUCCESS);
}
