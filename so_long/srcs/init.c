/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gape <gape@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:28:55 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/03 23:55:35 by gape             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_count_object(t_game *game)
{
	int	i;

	i = 0;
	game->map.info.exit = 0;
	game->map.info.player = 0;
	game->map.info.col = 0;
	while (i < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'E')
			game->map.info.exit++;
		else if (game->map.line[i] == 'P')
			game->map.info.player++;
		else if (game->map.line[i] == 'C')
			game->map.info.col++;
		i++;
	}
}

static void	map_data_init(t_game *game)
{
	game->c.move = 0;
	map_count_object(game);
	game->map.img.ground = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/ground.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.wall = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/wall.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.itembox = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/itembox.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.exit = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/exit.xpm", &game->map.img.w, &game->map.img.h);
	if (game->map.img.exit == 0 || game->map.img.ground == 0 \
		|| game->map.img.wall == 0 || game->map.img.itembox == 0)
	{
		printf("Error\nCan't load the image (this is Invalid Path)\n");
		exit(EXIT_FAILURE);
	}
	if (!map_is_valid(game))
		exit(EXIT_FAILURE);
}

static void	chac_data_init(t_game *game)
{
	game->c.x = (strchr_ri(game->map.line, 'P') % game->map.w) * 64;
	game->c.y = (strchr_ri(game->map.line, 'P') / game->map.w) * 64;
	game->c.move = 0;
	game->c.pos = 'L';
	game->c.img.u = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/up.xpm", &game->c.w, &game->c.h);
	game->c.img.d = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/down.xpm", &game->c.w, &game->c.h);
	game->c.img.l = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/left.xpm", &game->c.w, &game->c.h);
	game->c.img.r = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/right.xpm", &game->c.w, &game->c.h);
	game->c.img.l2 = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/left2.xpm", &game->c.w, &game->c.h);
	game->c.img.r2 = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/right2.xpm", &game->c.w, &game->c.h);
	if (game->c.img.d == 0 || game->c.img.l == 0 || game->c.img.r == 0 \
		|| game->c.img.u == 0 || game->c.img.l2 == 0 || game->c.img.r2 == 0)
	{
		printf("Error\nCan't load the image (this is Invalid Path)\n");
		exit(EXIT_FAILURE);
	}
}

void	so_long_init(t_game *game)
{
	game->mlx = mlx_init();
	map_load(game);
	map_data_init(game);
	chac_data_init(game);
	game->win = mlx_new_window(game->mlx, \
		game->win_w, game->win_h, "./so_long");
}
