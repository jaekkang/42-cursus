/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:35 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/11 14:52:08 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h" // need utils
# include <unistd.h> // close , read -
# include <stdlib.h> // malloc
# include <stdio.h> // perror
# include <fcntl.h> // open()
# include <string.h>

typedef struct s_data
{
	int		fds[2];
	char	**av;
	char	**paths;
	char	**env;
}			t_data;

void	find_path(t_data *data);
void	perror_n_exit(char *msg);
void	parse_data(t_data *data, int ac, char **av, char **envp);
char	**ft_split_set(char *str, char *charset);
void	check_str(int flag, char **new_argv);
char	*ft_path(char *filename, char **path);
char	**argv_init(int i, t_data *data);

#endif