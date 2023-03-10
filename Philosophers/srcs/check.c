/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:08:32 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 13:58:26 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_info(t_info *info, int ac)
{
	return (info->p_num <= 0
		|| info->time_to_die <= 0
		|| info->time_to_die <= 0
		|| info->time_to_sleep <= 0
		|| (ac == 6 && info->must_eat_num <= 0));
}

int	check_die(t_info *info)
{
	pthread_mutex_lock(&info->c_die);
	if (info->die == DIE)
	{
		pthread_mutex_unlock(&info->c_die);
		return (DIE);
	}
	pthread_mutex_unlock(&info->c_die);
	return (LIVE);
}

void	ft_eat_check(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (info->must_eat_num != 0 && i < info->p_num && \
		philo[i].eat_cnt > info->must_eat_num)
		i++;
	if (i == info->p_num)
		info->eat_check = ENOUGH;
}
