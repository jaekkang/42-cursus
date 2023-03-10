/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:17:21 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:57 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	get_sleep_time(t_info *info, t_philo *philo)
{
	long long	start_s_time;
	long long	now;

	pthread_mutex_lock(&info->print);
	start_s_time = get_time();
	print_action(info, "is sleeping", philo->id, start_s_time);
	pthread_mutex_unlock(&info->print);
	while (1)
	{
		if (check_die(info) == DIE)
			break ;
		now = get_time();
		if (now - start_s_time >= info->time_to_sleep)
			break ;
		usleep(10);
	}
}

void	get_eat_time(t_info *info, t_philo *philo)
{
	long long	eat_time;
	long long	start_e_time;

	eat_time = (long long)(info->time_to_eat);
	start_e_time = philo->check_d_time;
	while (1)
	{
		if (check_die(info) == DIE)
			break ;
		if ((get_time() - start_e_time) >= eat_time)
			break ;
		usleep(10);
	}
}
