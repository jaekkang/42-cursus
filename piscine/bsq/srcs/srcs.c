/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:54:10 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/08 20:24:10 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

#include <stdio.h>

char	**ft_split(char *str, char *charset);

#define  BUFF_SIZE   1024

void	ft_strput(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\n')
		str++;
	while (str[i])
		i++;
	return (i);
}

int ft_read()
{
   char   buff[BUFF_SIZE];
   char		**arr;
   int    fd;
   int		i;

   i = -1;
   if ( 0 < ( fd = open( "./test", O_RDONLY))){
      read( fd, buff, BUFF_SIZE);
      ft_strput( buff);
	  arr = ft_split(buff, "\n");
	  printf("read file buff_size : %d\n", ft_strlen( buff));
      printf("put str buff[0] : %s\n", arr[0]);
	  printf("str buff[1] : %s\n", arr[1]);
	  close( fd);
   } else {
      write(1, "파일 열기에 실패했습니다.\n" , 16);
   }
   return 0;
}
