/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:32:39 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 15:54:09 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	path_init(t_data *data)
{
	data->paths = malloc(sizeof(char *) * 6);
	if (!data->paths)
		perror_n_exit("malloc", MALLOC_ERROR);
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
		if (ft_strncmp(data->env[i], "PATH", 4) == 0)
		{
			tmp = data->env[i] + 5;
			break ;
		}
		i++;
	}
	data->paths = ft_split(tmp, ':');
}
