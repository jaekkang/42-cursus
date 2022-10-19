/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:50:28 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/19 18:27:33 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	so_long(t_game *game)
{
	so_long_init(game);
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
			return (EXIT_FAILURE);
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
