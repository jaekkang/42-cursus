/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:28:55 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/17 19:09:49 by jaekkang         ###   ########.fr       */
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
	game->chac.move = 0;
	map_count_object(game);
	game->map.img.ground = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/ground.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.wall = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/wall.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.itembox = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/itembox.xpm", &game->map.img.w, &game->map.img.h);
	game->map.img.exit = mlx_xpm_file_to_image(game->mlx, \
			"./asset/objects/exit.xpm", &game->map.img.w, &game->map.img.h);
	if (!map_is_valid(game))
		exit(EXIT_FAILURE);
}

static void	chac_data_init(t_game *game)
{
	game->chac.x = (strchr_ri(game->map.line, 'P') % game->map.w) * 64;
	game->chac.y = (strchr_ri(game->map.line, 'P') / game->map.w) * 64;
	game->chac.move = 0;
	game->chac.pos = 'L';
	game->chac.img.u = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/std_right.xpm", &game->chac.w, &game->chac.h);
	game->chac.img.d = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/std_right.xpm", &game->chac.w, &game->chac.h);
	game->chac.img.l = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/std_left.xpm", &game->chac.w, &game->chac.h);
	game->chac.img.r = mlx_xpm_file_to_image(game->mlx, \
			"./asset/character/std_right.xpm", &game->chac.w, &game->chac.h);
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
