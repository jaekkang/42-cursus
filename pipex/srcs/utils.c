/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:50:04 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/16 16:46:19 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_str(int flag, char **new_argv)
{
	int		i;
	char	**tmp;

	i = -1;
	while (new_argv[++i])
	{
		if ((new_argv[i][0] == '\'' \
			&& new_argv[i][ft_strlen(new_argv[i]) - 1] == '\'') \
			|| (new_argv[i][0] == '"' \
			&& new_argv[i][ft_strlen(new_argv[i]) - 1] == '"'))
		{
			new_argv[i]++;
			new_argv[i][ft_strlen(new_argv[i]) - 1] = 0;
		}
	}
	if (flag)
	{
		tmp = ft_split(new_argv[1], '\\');
		i = -1;
		new_argv[1] = ft_strdup("");
		while (tmp[++i])
			new_argv[1] = ft_strjoin(new_argv[1], tmp[i]);
	}
}

static char	**exception2(int i, t_data *data)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	if (!new_argv)
		perror_n_exit("malloc", MALLOC);
	new_argv[0] = ft_strdup("/bin/bash");
	new_argv[1] = ft_strdup(data->av[i] + 2);
	new_argv[1] = ft_strtrim(new_argv[1], " 	");
	new_argv[2] = NULL;
	if (access(new_argv[1], X_OK) == -1 \
		&& access(new_argv[1], F_OK) == 0)
		perror_n_exit(new_argv[1], PERMISSION);
	check_str(1, new_argv);
	return (new_argv);
}

static char	**exception(int i, t_data *data, char *cmd)
{
	char	**new_argv;

	new_argv = (char **)malloc(sizeof(char *) * 3);
	if (!new_argv)
		perror_n_exit("malloc", MALLOC);
	new_argv[0] = ft_strdup(cmd);
	new_argv[1] = ft_strdup(data->av[i] + ft_strlen(cmd));
	new_argv[1] = ft_strtrim(new_argv[1], " 	");
	new_argv[2] = NULL;
	check_str(1, new_argv);
	return (new_argv);
}

char	*path_check(char *filename, char **path)
{
	int		i;
	char	*tmp;

	i = -1;
	while (path[++i])
	{
		if (path[i][ft_strlen(path[i]) - 1] != '/')
			tmp = ft_strjoin(path[i], "/");
		else
			tmp = ft_strdup(path[i]);
		tmp = ft_strjoin(tmp, filename);
		if (access(tmp, F_OK) == 0)
			return (tmp);
	}
	if (access(filename, F_OK) == 0 && ft_strchr(filename, '/'))
		return (filename);
	return (NULL);
}

char	**argv_init(int i, t_data *data)
{
	char	**new_argv;

	if (ft_strncmp(data->av[i], "awk", 3) == 0)
		new_argv = exception(i, data, "awk");
	else if (ft_strncmp(data->av[i], "sed", 3) == 0)
		new_argv = exception(i, data, "sed");
	else if (ft_strncmp(data->av[i], "./", 2) == 0)
		new_argv = exception2(i, data);
	else if (ft_strncmp(data->av[i], "grep", 4) == 0)
		new_argv = exception(i, data, "grep");
	else
	{
		new_argv = split_set(data->av[i], " 	");
		check_str(0, new_argv);
	}
	return (new_argv);
}
