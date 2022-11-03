/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:10:52 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/27 17:19:53 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i])
		ret[len++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[len++] = s2[i++];
	ret[len] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return ((void *)0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start + 1;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			ret[j++] = s[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
