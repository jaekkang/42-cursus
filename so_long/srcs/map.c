/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gape <gape@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:18 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/21 15:39:01 by gape             ###   ########.fr       */
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
	int	wid;
	int	hei;

	hei = -1;
	while (++hei < game->map.h)
	{	
		wid = -1;
		while (++wid < game->map.w)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
								game->map.img.ground, wid * 64, hei * 64);
			if (game->map.line[hei * game->map.w + wid] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->map.img.wall, wid * 64, hei * 64);
			else if (game->map.line[hei * game->map.w + wid] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->map.img.itembox, wid * 64, hei * 64);
			else if (game->map.line[hei * game->map.w + wid] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
								game->map.img.exit, wid * 64, hei * 64);
		}
	}
	if (game->map.line[game->chac.y * game->map.w / 64 \
		+ game->chac.x / 64] == 'E' && game->map.info.col == 0)
		exit(EXIT_SUCCESS);
}
