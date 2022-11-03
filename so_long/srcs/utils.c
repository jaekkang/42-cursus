/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:48:28 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 14:56:26 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*strjoin_del_nl(char *s1, char *s2)
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
	while (s1[i] && s1[i] != '\n')
		ret[len++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[len++] = s2[i++];
	if (ret[len - 1] == '\n')
		len--;
	ret[len] = '\0';
	free(s1);
	free(s2);
	return (ret);
}

int	strchr_ri(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (0);
}
