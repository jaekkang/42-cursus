/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:27:41 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/05 13:53:27 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str1[i])
		i++;
	while (str2[++j])
		str1[i + j] = str2[j];
	str1[i + j] = '\0';
	return (str1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * size - 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		*str = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * ft_total_len(size, strs, sep));
	if (!str)
		return (NULL);
	*str = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size -1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
