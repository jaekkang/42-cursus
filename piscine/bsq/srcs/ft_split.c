/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:18:37 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/08 20:16:58 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_valid(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
		if (!ft_is_valid(str[i], charset) && ft_is_valid(str[i + 1], charset))
			count++;
	return (count);
}

void	ft_strdup(char **ret, int wlen, char *str, int j)
{
	int	i;

	i = -1;
	ret[j] = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!ret[j])
		return ;
	while (++i < wlen)
		ret[j][i] = str[i];
	ret[j][i] = '\0';
}

void	ft_split_dup(char *str, char *charset, char **ret)
{
	int	wlen;
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		wlen = 0;
		while (!ft_is_valid(str[i + wlen], charset))
			wlen++;
		if (wlen > 0)
			ft_strdup(ret, wlen, &str[i], j++);
		i += wlen;
	}
	ret[j] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**ret;

	word_count = ft_word_count(str, charset);
	ret = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (ret == 0)
		return (0);
	ft_split_dup(str, charset, ret);
	return (ret);
}
