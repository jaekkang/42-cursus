/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:50:28 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 15:19:36 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	so_long(t_game *game)
{
	so_long_init(game);
	mlx_string_put(game->mlx, game->win, 2 * 64, 1 * 64, 999999, "0");
	mapping(game);
	chac_draw(game);
	mlx_hook(game->win, 2, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (ac == 2 && game)
	{
		game->map.name = av[1];
		if (!check_map_extension(av[1]))
		{
			printf("Error\nUsage : ./so_long [MAP_FILE.ber]\n");
			exit(EXIT_FAILURE);
		}
		so_long(game);
		free(game);
	}
	else if (ac != 2)
	{
		printf("Error\nPlease enter only one map file.\n");
		free(game);
	}
	return (0);
}
