/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:52:40 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/08 17:48:56 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>         // O_WRONLY
#include <unistd.h>        // write(), close()

#define  BUFF_SIZE   1024

int	write1();

int main()
{
   char   buff[BUFF_SIZE];
   int    fd;

   write1();
   if ( 0 < ( fd = open( "./test", O_RDONLY))){
      read( fd, buff, BUFF_SIZE);
      puts( buff);
      close( fd);
   } else {
      printf( "파일 열기에 실패했습니다.\n");
   }
   return 0;
}
