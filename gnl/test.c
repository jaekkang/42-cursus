/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:23:13 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/14 19:09:59 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char *ab(size_t a,int b){
	char *t;
	char c=0;
	char k=read(b,&c,1);
	if(k<0||(k==0&&a==0))
		return NULL;
	if(k==0||c=='\n')
		t=malloc(a+2);
	else
		t=ab(a+1,b);
	if(t)
		t[a]=c,t[a+1]=t[a+1]*(c!='\n');
	return t;
}
char *get_next_line(int fd){
	return ab(0,fd);
}
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("./test", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
