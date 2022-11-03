/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:32:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/04 03:23:07 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	find_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->ep[i])
	{
		if (ft_strncmp("PATH=", data->ep[i], 5) == 0)
		{
			data->tmp_path = data->ep[i] + 5;
			break ;
		}
		i++;
		if (data->ep[i] == NULL)
			print_errmsg_n_exit(1, "Error\nCan't find PATH\n");
	}
	data->paths = ft_split(data->tmp_path, ':');
	i = 0;
	while (data->paths[i])
	{
		data->paths[i] = ft_strjoin(data->paths[i], "/");
		i++;
	}
}

void	parse_data(t_data *data, int ac, char **av, char **envp)
{
	data->argv = (char **)malloc(sizeof(char *) * (ac));
	if (!data->argv)
		print_errmsg_n_exit(1, "Error\nmalloc failed\n");
	data->argv = av;
	data->argv[ac] = NULL;
	data->cmd1 = ft_split(data->argv[2], ' ');
	data->cmd2 = ft_split(data->argv[3], ' ');
	data->in_fd = open(av[1], O_RDONLY) < 0;
	if (data->in_fd < 0)
		print_errmsg_n_exit(1, "Error\ninvalid infile\n");
	data->out_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->out_fd < 0)
		print_errmsg_n_exit(1, "Error\ninvalid outfile\n");
	data->ep = envp;
}
