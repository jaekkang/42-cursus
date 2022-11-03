/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chac_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:39:43 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 15:19:42 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	chac_drow_up(t_game *game)
{
	if ((game->c.y / 64) % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.u, game->c.x, game->c.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
				game->c.img.l, game->c.x, game->c.y);
}

static void	chac_drow_down(t_game *game)
{
	if ((game->c.y / 64) % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.d, game->c.x, game->c.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.l, game->c.x, game->c.y);
}

static void	chac_drow_left(t_game *game)
{
	if ((game->c.x / 64) % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.l, game->c.x, game->c.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.l2, game->c.x, game->c.y);
}

static void	chac_drow_right(t_game *game)
{
	if ((game->c.x / 64) % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.r, game->c.x, game->c.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
			game->c.img.r2, game->c.x, game->c.y);
}

void	chac_draw(t_game *game)
{
	if (game->c.pos == 'U')
		chac_drow_up(game);
	else if (game->c.pos == 'D')
		chac_drow_down(game);
	else if (game->c.pos == 'L')
		chac_drow_left(game);
	else if (game->c.pos == 'R')
		chac_drow_right(game);
}
