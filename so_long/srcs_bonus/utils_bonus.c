/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:48:28 by jaekkang          #+#    #+#             */
/*   Updated: 2022/10/24 15:19:18 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

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

static size_t	ft_count_number(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa2(int n, t_game *game)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_count_number(n);
	i = 0;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		i = 1;
		n *= -1;
	}
	while (len-- > i)
	{
		ret[len] = n % 10 + '0';
		n /= 10;
	}
	game->mt = ret;
	free(ret);
	return (game->mt);
}
