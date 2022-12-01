/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:03 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/01 16:06:27 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		num;
	int		i;
	char	s[6];
	int		idx;
	int		stack[10000];

	i = 0;
	scanf("%d", &num);
	while (i < num)
	{
		scanf("%s", s);
		if (!strcmp(s, "push"))
		{
			scanf("%d", &idx);
			printf("check push %d\n", idx);
		}
		else if (!strcmp(s, "pop"))
		{
			printf("check pop\n");
		}
		else if (!strcmp(s, "size"))
		{
			printf("check size\n");
		}
		else if (!strcmp(s, "empty"))
		{
			printf("check empty\n");
		}
		else if (!strcmp(s, "top"))
		{
			printf("check top\n");
		}
		i++;
	}
	return (0);
}
