/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:35 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/16 16:46:29 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h" // utils
# include <unistd.h> // close , read
# include <stdlib.h> // malloc
# include <stdio.h> // perror
# include <fcntl.h> // open()

typedef enum errcode {
	ARGC = 0,
	PIPE = 1,
	FORK = 2,
	FD = 3,
	MALLOC = 4,
	COMMAND = 5,
	RUN = 6,
	PERMISSION = 7,
	EXIT_PERMOSSION = 126,
	EXIT_COMMAND = 127,
}	t_errortypes;
typedef struct s_data
{
	int		fds[2];
	char	**av;
	char	**paths;
	char	**env;
}			t_data;

void	perror_n_exit(char *msg, int errornum);
char	**split_set(char *str, char *charset);
void	check_str(int flag, char **new_argv);
char	*path_check(char *filename, char **path);
char	**argv_init(int i, t_data *data);

#endif