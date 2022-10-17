/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:52:18 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/08 17:19:31 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int write1()
{
    FILE* fp = fopen("test","w"); //test파일을 w(쓰기) 모드로 열기

    for (int i = 0; i < 5; i++) {
        fputs("test\n",fp); //문자열 입력
    }
    fputs("end", fp);

    fclose(fp); //파일 포인터 닫기

    return 0;
}
