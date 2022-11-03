/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:18 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 14:55:19 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		printf("Error\nThe file name or data is incorrect.\n");
		exit(fd);
	}
	return (fd);
}

int	map_is_valid(t_game *game)
{
	if (game->map.w * game->map.h != (int)ft_strlen(game->map.line))
	{
		printf("Error\nMap must be rectangular.\n");
		return (FAILE);
	}
	if (!(check_map_wall(game) && check_map_object(game) \
		&& check_map_player(game)))
		return (FAILE);
	return (SUCCESS);
}

void	map_load(t_game *game)
{
	int		fd;
	char	*line;

	game->map.h = 0;
	fd = open_map_file(game->map.name);
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\nUnable to read map file.\n");
		exit(EXIT_FAILURE);
	}
	game->win_w = (ft_strlen(line) - 1) * 64;
	game->map.w = ft_strlen(line) - 1;
	game->map.line = line;
	while (line)
	{
		game->map.h++;
		line = get_next_line(fd);
		if (line)
			game->map.line = strjoin_del_nl(game->map.line, line);
	}
	game->win_h = game->map.h * 64;
	close(fd);
}

void	mapping(t_game *game)
{
	game->hei = -1;
	while (++game->hei < game->map.h)
	{	
		game->wid = -1;
		while (++game->wid < game->map.w)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
						game->map.img.ground, game->wid * 64, game->hei * 64);
			if (game->map.line[game->hei * game->map.w + game->wid] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
							game->map.img.wall, game->wid * 64, game->hei * 64);
			else if (game->map.line[game->hei * game->map.w + game->wid] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->map.img.itembox, game->wid * 64, game->hei * 64);
			else if (game->map.line[game->hei * game->map.w + game->wid] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
							game->map.img.exit, game->wid * 64, game->hei * 64);
		}
	}
	if (game->map.line[game->c.y * game->map.w / 64 + \
			game->c.x / 64] == 'E' && game->map.info.col == 0)
		exit(EXIT_SUCCESS);
}
