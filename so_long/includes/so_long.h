/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:20:12 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 15:50:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../lib/libft.h"
# include "../gnl/get_next_line.h"

# define SUCCESS 1
# define FAILE 0

# define KEY_ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define X_EVENT_KEY_EXIT 17

typedef struct s_map_img {
	void	*ground;
	void	*wall;
	void	*itembox;
	void	*exit;
	int		w;
	int		h;
}				t_map_img;

typedef struct s_map_info {
	int	exit;
	int	col;
	int	player;
}			t_map_info;

typedef struct s_map {
	void		*map_ptr;
	char		*name;
	t_map_info	info;
	int			w;
	int			h;
	char		*line;
	t_map_img	img;
}				t_map;

typedef struct s_chac_img {
	void	*u;
	void	*d;
	void	*l;
	void	*r;
	void	*l2;
	void	*r2;
}	t_chac_img;

typedef struct s_chac
{
	t_chac_img	img;
	char		pos;
	int			w;
	int			h;
	int			x;
	int			y;
	int			move;

}				t_chac;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		map;
	t_chac		c;
	int			win_w;
	int			win_h;
	char		*mt;
	int			hei;
	int			wid;
}				t_game;

char	*get_next_line(int fd);
void	is_ber_file(char *filename);
void	map_load(t_game *game);
void	mapping(t_game *game);
int		key_press(int key_code, t_game *game);
void	so_long_init(t_game *game);
char	*strjoin_del_nl(char *s1, char *s2);
void	chac_draw(t_game *game);
int		strchr_ri(const char *s, int c);
int		map_is_valid(t_game *game);
int		check_map_player(t_game *game);
int		check_map_extension(char *filename);
int		check_map_wall(t_game *game);
int		check_map_object(t_game *game);

#endif
