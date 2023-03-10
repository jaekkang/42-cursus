/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:17:46 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 17:00:03 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	mornitor(t_info *info, t_philo *philo)
{
	int			i;
	long long	time;

	while (info->eat_check == NOT_ENOUGH)
	{
		i = -1;
		while (++i < info->p_num && check_die(info) == LIVE)
		{
			pthread_mutex_lock(&info->print);
			time = get_time();
			if ((time - info->philo[i].check_d_time) > info->time_to_die)
			{
				print_action(info, "died", i, time);
				pthread_mutex_lock(&info->c_die);
				info->die = DIE;
				pthread_mutex_unlock(&info->c_die);
			}
			pthread_mutex_unlock(&info->print);
		}
		if (check_die(info) == DIE)
			break ;
		ft_eat_check(info, philo);
	}
}
