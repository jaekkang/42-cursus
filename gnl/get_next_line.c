/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:11:26 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/20 15:40:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_util(char *line)
{
	char	*ret;
	int		idx;

	idx = 0;
	while (line[idx] != '\n' && line[idx] != '\0')
		idx++;
	if (line[idx] == '\0')
		return (NULL);
	ret = ft_substr(line, idx + 1, ft_strlen(line) - idx);
	if (!ret)
		return (NULL);
	if (!ret[0])
	{
		free(ret);
		ret = NULL;
		return (NULL);
	}
	line[idx + 1] = '\0';
	return (ret);
}

static char	*ft_read_line(char *buf, int fd)
{
	char	*save;
	char	*ret;
	int		idx;

	idx = 0;
	while (idx)
	{
		idx = read(fd, buf, BUFFER_SIZE);
		printf("%s\n", buf);
		printf("idx : %d\n", idx);
		if (idx == -1)
			return (NULL);
		else if (idx == 0)
			break ;
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
	printf("%s\n", line);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	save = ft_util(line);
	return (line);
}
