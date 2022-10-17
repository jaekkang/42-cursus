/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:57:33 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/23 21:07:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	pos;
	int	tmp;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			pos = 0;
			tmp = 0;
			while (to_find[pos] != '\0')
			{
				if (str[pos] != to_find[pos])
					tmp = 1;
				pos++;
			}
			if (tmp == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
