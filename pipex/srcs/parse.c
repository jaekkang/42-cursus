/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:32:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/09 18:14:16 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	find_path(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->env[i])
	{
		if (data->env[i] == NULL)
			perror_n_exit("Error\nCan't find PATH\n");
		else if (ft_strncmp("PATH=", data->env[i], 5) == 0)
		{
			tmp = data->env[i] + 5;
			break ;
		}
		i++;
	}
	data->paths = ft_split(tmp, ':');
	i = 0;
	while (data->paths[i])
	{
		if (data->paths[i][ft_strlen(data->paths[i]) - 1] != '/')
			data->paths[i] = ft_strjoin(data->paths[i], "/");
		i++;
	}
}

void	parse_data(t_data *data, int ac, char **av, char **envp)
{
	data->av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!data->av)
		perror_n_exit("malloc failed\n");
	data->av = av;
	data->env = envp;
	data->cmd1 = ft_split(data->av[2], ' ');
	data->cmd2 = ft_split(data->av[3], ' ');
}
