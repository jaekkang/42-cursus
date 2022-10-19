/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:11:26 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/18 13:31:07 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_util(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\n' && line[idx] != '\0')
		idx++;
	if (line[idx] == '\0')
		return (NULL);
	ret = ft_substr(line, idx + 1, ft_strlen(line) - idx);
	if (!info->ret)
		return (NULL);
	if (!info->ret[0])
	{
		free(info->ret);
		info->ret = NULL;
		return (NULL);
	}
	info->line[info->idx + 1] = '\0';
	return (info->ret);
}

static char	*ft_read_line(char *buf, int fd)
{
	int		idx;
	char	*save;
	char	*ret;

	idx = 0;
	while (idx)
	{
		idx = read(fd, buf, BUFFER_SIZE);
		if (idx == -1)
			return (NULL);
		else if (idx == 0)
			break ;
		buf[idx] = '\0';
		if (!save)
			save = ft_strdup("");
		ret = save;
		save = ft_strjoin(ret, buf);
		if (!save)
			return (NULL);
		free(ret);
		ret = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	char	*save;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	line = ft_read_line(buf, fd);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	// save = ft_util(&info);
	return (line);
}
