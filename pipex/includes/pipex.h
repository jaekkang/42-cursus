/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:35 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/04 01:02:08 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h" // need utils
# include <sys/wait.h> // wait && waitpid
# include <unistd.h> // close , read -
# include <stdlib.h> // malloc
# include <stdio.h> // perror
# include <errno.h> 
# include <fcntl.h> // open()
# include <string.h>

# define BUFSIZE 1024
# define E2BIG	7

typedef struct s_data
{
	int		fd[2];
	char	**argv;
	char	**cmd1;
	char	**cmd2;
	char	*tmp_path;
	char	**paths;
	int		in_fd;
	int		out_fd;
	char	**ep;
	char	*cmd1_path;
	char	*cmd2_path;
	char	buffer[BUFSIZE];
	pid_t	pid;
}			t_data;

void	find_path(t_data *data);
void	parse_data(t_data *data, int ac, char **av, char **envp);
void	print_errmsg_n_exit(int err, char *msg);

#endif