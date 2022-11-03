/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:22:33 by jaekkang          #+#    #+#             */
/*   Updated: 2022/07/08 08:44:44 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
