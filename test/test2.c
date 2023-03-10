/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:42:03 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/13 13:37:41 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// char *ab(size_t a,int b)
// {
// 	char*t,c=0,k=read(b,&c,1);
// 	if(k<0||k==0&&a==0)
// 		return NULL;
// 	if(k==0||c=='\n')
// 		t=malloc(a+2);
// 	else t=_(a+1,b);
// 	if(t)t[a]=c,t[a+1]=t[a+1]*(c!='\n');
// 	return t;
// 	}

// char *get_next_line(int fd)
// {
// 	return ab(0, fd);
// }

#include <unistd.h>

char *ab(size_t a, int b)
{
	char *t, c=0, k=read(b, &c, 1);

	if (k<0 || (k==0 && a==0))
		return NULL;
	if (k==0 || c =='\n')
		t=malloc(a+2);
	else
		t=ab(a+1, b);
	if (t)
		t[a]=c, t[a+1]= t[a+1] * (c != '\n');
	return t;	
}

char *get_next_line(int fd)
{
	return (ab(0, fd));
}