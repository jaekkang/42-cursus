/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:20:52 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/07 13:56:13 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	handle_one_philo(t_info *info)
{
	printf("0 1 has taken a fork\n");
	printf("%d 1 died\n", info->time_to_die);
}
