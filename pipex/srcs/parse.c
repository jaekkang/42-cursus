/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:32:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/11 14:51:21 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	path_init(t_data *data)
{
	if (!data->paths)
		perror_n_exit("Error\nCan't find PATH\n");
	data->paths[0] = ft_strdup("/usr/local/bin");
	data->paths[1] = ft_strdup("/usr/bin");
	data->paths[2] = ft_strdup("/bin");
	data->paths[3] = ft_strdup("/usr/sbin");
	data->paths[4] = ft_strdup("/sbin");
	data->paths[5] = NULL;
}

void	find_path(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->env[i] == NULL)
		path_init(data);
	while (data->env[i])
	{
		if (ft_strncmp("PATH=", data->env[i], 5) == 0)
		{
			tmp = data->env[i] + 5;
			break ;
		}
		i++;
	}
	data->paths = ft_split(tmp, ':');
	i = -1;
	while (data->paths[++i])
	{
		if (data->paths[i][ft_strlen(data->paths[i]) - 1] != '/')
			data->paths[i] = ft_strjoin(data->paths[i], "/");
	}
}

void	parse_data(t_data *data, int ac, char **av, char **envp)
{
	data->av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!data->av)
		perror_n_exit("malloc failed\n");
	data->av = av;
	data->env = envp;
}
