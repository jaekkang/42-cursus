/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:13:38 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:52 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	end_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->p_num)
		pthread_join(info->philo[i].tid, NULL);
	i = -1;
	while (++i < info->p_num)
		pthread_mutex_destroy(&info->pick_up[i]);
	free(info->philo);
	free(info->forks);
	pthread_mutex_destroy(&info->eating);
	pthread_mutex_destroy(&info->print);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2)
		usleep(100);
	while (1)
	{
		if (check_die(info) == DIE)
			break ;
		if (eating(info, philo))
			break ;
		get_sleep_time(info, philo);
		pthread_mutex_lock(&info->print);
		print_action(info, "is thinking", philo->id, get_time());
		pthread_mutex_unlock(&info->print);
	}
	return (NULL);
}

int	philosopher(t_info *info)
{
	void	*arg;
	int		i;

	info->start_time = get_time();
	i = -1;
	while (++i < info->p_num)
	{
		info->philo[i].check_d_time = get_time();
		arg = (void *)&(info->philo[i]);
		if (pthread_create(&(info->philo[i].tid), NULL, routine, arg))
			return (FAIL);
	}
	mornitor(info, info->philo);
	end_philo(info);
	return (SUCCESS);
}
