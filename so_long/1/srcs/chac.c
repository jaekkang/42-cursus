/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:39:43 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/17 16:25:07 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	chac_draw(t_game *game)
{
	if (game->chac.pos == 'U')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chac.img.l, game->chac.x, game->chac.y);
	}
	else if (game->chac.pos == 'D')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chac.img.l, game->chac.x, game->chac.y);
	}
	else if (game->chac.pos == 'L')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chac.img.l, game->chac.x, game->chac.y);
	}
	else if (game->chac.pos == 'R')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
			game->chac.img.r, game->chac.x, game->chac.y);
	}
}
