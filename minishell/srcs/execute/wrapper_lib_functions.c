/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_lib_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:33:33 by myko              #+#    #+#             */
/*   Updated: 2023/04/20 10:12:49 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_s(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc_s(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	temp = str;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

char	*ft_strdup_s(const char *s1)
{
	size_t	len;
	char	*copy;
	char	*temp;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc_s(sizeof(char) * (len + 1));
	temp = copy;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (copy);
}
