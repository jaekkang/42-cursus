/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:19:06 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 13:56:34 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_action(t_info *info, char *str, int id, long long ts)
{
	if (check_die(info) == LIVE)
	{
		printf("%lld ", ts - info->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
}
