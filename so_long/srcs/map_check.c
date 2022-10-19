/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:36:08 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/19 16:17:07 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename) - 1;
	if (filename[len - 3] != '.' || filename[len - 2] != 'b' \
		|| filename[len - 1] != 'e' || filename[len] != 'r' )
		return (FAILE);
	return (SUCCESS);
}

int	check_map_object(t_game *game)
{
	int	i;
	int	ret;

	i = -1;
	ret = SUCCESS;
	while (++i < (int)ft_strlen(game->map.line))
		if (!(game->map.line[i] == '1' || game->map.line[i] == '0' || \
			game->map.line[i] == 'E' || game->map.line[i] == 'P' || \
			game->map.line[i] == 'C'))
				ret = FAILE;
	if (game->map.info.col == 0 || game->map.info.exit == 0)
		ret = FAILE;
	if (ret == FAILE)
		printf("Error\nThe map contains an object that is not allowed.\n");
	return (ret);
}

int	check_map_player(t_game *game)
{
	int	ret;

	ret = SUCCESS;
	if (game->map.info.player == 0)
	{
		printf("Error\nCan't find player!\n");
		ret = FAILE;
	}
	else if (game->map.info.player > 1)
	{
		printf("Error\nThere are more than 2 players on the map!\n");
		ret = FAILE;
	}
	return (ret);
}

int	check_map_wall(t_game *game)
{
	int	i;
	int	ret;

	i = -1;
	ret = SUCCESS;
	while (++i < (int)ft_strlen(game->map.line))
	{
		if (i < game->map.w || i % game->map.w == 0 \
			|| i % game->map.w == game->map.w - 1)
		{
			if (game->map.line[i] != '1')
				ret = FAILE;
		}
		else if (i > (int)ft_strlen(game->map.line) - game->map.w)
		{
			if (game->map.line[i] != '1')
				ret = FAILE;
		}
	}
	if (ret == FAILE)
		printf("Error\nMap must be closed/surrounded by walls\n");
	return (ret);
}
