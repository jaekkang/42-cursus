/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:32:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/03 23:12:52 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	find_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->ep[i] != NULL)
	{
		if (ft_strncmp("PATH=", data->ep[i], 5) == 0)
		{
			data->tmp_path = data->ep[i] + 5;
			break ;
		}
		i++;
	}
	data->paths = ft_split(data->tmp_path, ':');
	i = 0;
	while (data->paths[i] != NULL)
	{
		data->paths[i] = ft_strjoin(data->paths[i], "/");
		i++;
	}
}

void	parse_data(t_data *data, int ac, char **av, char **envp)
{
	data->argv = (char **)malloc(sizeof(char *) * (ac));
	if (!data->argv)
		return ;
	data->argv = av;
	data->argv[ac] = NULL;
	data->cmd1 = ft_split(data->argv[2], ' ');
	data->cmd2 = ft_split(data->argv[3], ' ');
	data->in_fd = open(av[1], O_RDONLY) < 0;
	if (data->in_fd < 0)
	{
		perror("Error\ninvalid infile");
		exit(1);
	}
	data->out_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->out_fd < 0)
	{
		perror("Error\ninvalid outfile");
		exit(1);
	}
	data->ep = envp;
}
