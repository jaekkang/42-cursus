/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:04:21 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/26 20:10:41 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *arr, int left, int right)
{
	int	pi;
	int	i;
	int	j;

	pi = left;
	i = pi + 1;
	j = right;
	if (left >= right)
		return ;
	while (i <= j)
	{
		while (i <= right && arr[i] <= arr[pi])
			i++;
		while (j > left && arr[j] >= arr[pi])
			j--;
		if (i > j)
			ft_swap(&arr[j], &arr[pi]);
		else
			ft_swap(&arr[i], &arr[j]);
	}
	quick_sort(arr, left, pi - 1);
	quick_sort(arr, pi + 1, right);
}
