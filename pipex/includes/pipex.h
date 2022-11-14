/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:35 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 15:05:58 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h" // need utils
# include <unistd.h> // close , read -
# include <stdlib.h> // malloc
# include <stdio.h> // perror
# include <fcntl.h> // open()

typedef enum errortypes {
	ARGC_ERROR = 0,
	PIPE_ERROR = 1,
	FORK_ERROR = 2,
	FD_ERROR = 3,
	MALLOC_ERROR = 4,
	COMMAND_ERROR = 5,
	RUN_ERROR = 6,
	PERMISSION_ERROR = 7,
	EXIT_PERMOSSION_ERROR = 126,
	EXIT_COMMAND_ERROR = 127,
}	t_errortypes;
typedef struct s_data
{
	int		fds[2];
	char	**av;
	char	**paths;
	char	**env;
}			t_data;

void	find_path(t_data *data);
void	perror_n_exit(char *msg, int errornum);
char	**ft_split_set(char *str, char *charset);
void	check_str(int flag, char **new_argv);
char	*ft_path(char *filename, char **path);
char	**argv_init(int i, t_data *data);

#endif