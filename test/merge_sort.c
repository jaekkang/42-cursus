/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:04:46 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/30 13:15:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int sorted[8];

void merge(int *list, int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	//분할 정렬된 list의 합병
	while (i<=mid && j<=right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// 남아 있는 값들을 일괄 복사
	if (i > mid)
	{
		for (l=j; l<=right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l=i; l<=mid; l++)
			sorted[k++] = list[l];
	}
	for (l=left; l<=right; l++)
	{
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left,  int right)
{
	int mid;
	
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int	main(void)
{
	int n = 8;
	int list[8] = {21, 10, 12, 20, 25, 13, 15, 22};
	
	merge_sort(list, 0, n - 1);
	for (int i=0;i<n;i++)
	{
		printf("%d ", list[i]);
	}
	return (0);
}
