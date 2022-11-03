/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:27:32 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 15:19:27 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

static void	move_up(t_game *game, int coor)
{
	if (game->map.line[coor - game->map.w] != '1')
	{
		if (game->map.line[coor - game->map.w] == 'C')
		{
			game->map.line[coor - game->map.w] = '0';
			game->map.info.col--;
			printf("number of boxes left : %d\n", game->map.info.col);
		}
		game->c.y -= 64;
		game->c.pos = 'U';
		game->c.move++;
		printf("current number of steps taken : %d\n", game->c.move);
	}
}

static void	move_down(t_game *game, int coor)
{
	if (game->map.line[coor + game->map.w] != '1')
	{
		if (game->map.line[coor + game->map.w] == 'C')
		{
			game->map.line[coor + game->map.w] = '0';
			game->map.info.col--;
			printf("number of boxes left : %d\n", game->map.info.col);
		}
		game->c.y += 64;
		game->c.pos = 'D';
		game->c.move++;
		printf("current number of steps taken : %d\n", game->c.move);
	}
}

static void	move_left(t_game *game, int coor)
{
	if (game->map.line[coor - 1] != '1')
	{
		if (game->map.line[coor - 1] == 'C')
		{
			game->map.line[coor - 1] = '0';
			game->map.info.col--;
			printf("number of boxes left : %d\n", game->map.info.col);
		}
		game->c.x -= 64;
		game->c.pos = 'L';
		game->c.move++;
		printf("current number of steps taken : %d\n", game->c.move);
	}
}

static void	move_right(t_game *game, int coor)
{
	if (game->map.line[coor + 1] != '1')
	{
		if (game->map.line[coor + 1] == 'C')
		{
			game->map.line[coor + 1] = '0';
			game->map.info.col--;
			printf("number of boxes left : %d\n", game->map.info.col);
		}
		game->c.x += 64;
		game->c.pos = 'R';
		game->c.move++;
		printf("current number of steps taken : %d\n", game->c.move);
	}
}

int	key_press(int key_code, t_game *game)
{
	int		coor;

	coor = game->c.y * game->map.w / 64 + game->c.x / 64;
	if (key_code == KEY_W && game->c.y != 0)
		move_up(game, coor);
	else if (key_code == KEY_S && game->c.y < game->win_h - 64)
		move_down(game, coor);
	else if (key_code == KEY_A && game->c.x != 0)
		move_left(game, coor);
	else if (key_code == KEY_D && game->c.x < game->win_w - 64)
		move_right(game, coor);
	else if (key_code == KEY_ESC)
	{
		free(game->map.line);
		free(game);
		exit(EXIT_SUCCESS);
	}
	mapping(game);
	chac_draw(game);
	return (0);
}
