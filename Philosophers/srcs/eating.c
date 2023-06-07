/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:08:23 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/13 13:25:06 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thread_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->print);
	philo->check_d_time = get_time();
	print_action(info, "is eating", philo->id, philo->check_d_time);
	pthread_mutex_unlock(&info->print);
	philo->eat_cnt++;
	get_eat_time(info, philo);
}

void	pick_fork(t_info *info, t_philo *philo)
{
	while (check_die(info) == LIVE)
	{
		pthread_mutex_lock(&info->pick_up[philo->l_fork]);
		if (info->forks[philo->l_fork] == USING)
		{
			pthread_mutex_unlock(&info->pick_up[philo->l_fork]);
			usleep(0);
			continue ;
		}
		info->forks[philo->l_fork] = USING;
		pthread_mutex_lock(&info->pick_up[philo->r_fork]);
		if (info->forks[philo->r_fork] == USING)
		{
			info->forks[philo->l_fork] = NOT_USING;
			pthread_mutex_unlock(&info->pick_up[philo->r_fork]);
			pthread_mutex_unlock(&info->pick_up[philo->l_fork]);
			usleep(0);
			continue ;
		}
		info->forks[philo->r_fork] = USING;
		pthread_mutex_unlock(&info->pick_up[philo->r_fork]);
		pthread_mutex_unlock(&info->pick_up[philo->l_fork]);
		pthread_mutex_lock(&info->print);
		print_action(info, "has taken a fork", philo->id, get_time());
		print_action(info, "has taken a fork", philo->id, get_time());
		pthread_mutex_unlock(&info->print);
		break ;
	}
}

int	put_fork(t_info *info, int pos)
{
	pthread_mutex_lock(&info->pick_up[pos]);
	info->forks[pos] = NOT_USING;
	pthread_mutex_unlock(&info->pick_up[pos]);
	return (SUCCESS);
}

int	eating(t_info *info, t_philo *philo)
{
	pick_fork(info, philo);
	thread_eat(philo->info, philo);
	put_fork(info, philo->l_fork);
	put_fork(info, philo->r_fork);
	if (info->eat_check == ENOUGH)
		return (1);
	return (0);
}
