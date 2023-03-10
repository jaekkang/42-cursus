/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:00:37 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 20:08:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	mutex_init(t_info *info)
{
	int	i;

	info->pick_up = malloc(sizeof(pthread_mutex_t) * info->p_num);
	if (!info->pick_up)
		return (1);
	i = -1;
	if (pthread_mutex_init(&info->print, NULL))
		return (1);
	if (pthread_mutex_init(&info->eating, NULL))
		return (1);
	if (pthread_mutex_init(&info->c_die, NULL))
		return (1);
	return (0);
}

int	fork_init(t_info *info)
{
	int	i;

	info->forks = malloc(sizeof(int) * info->p_num);
	if (!info->forks)
		return (1);
	i = -1;
	while (++i < info->p_num)
		info->forks[i] = NOT_USING;
	return (0);
}

int	philo_init(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_info) * info->p_num);
	if (!info->philo)
		return (1);
	i = -1;
	while (++i < info->p_num)
	{
		info->philo[i].id = i;
		info->philo[i].eat_cnt = 0;
		info->philo[i].check_d_time = 0;
		if (i % 2)
		{
			info->philo[i].l_fork = i;
			info->philo[i].r_fork = (i + 1) % info->p_num;
		}
		else
		{
			info->philo[i].l_fork = (i + 1) % info->p_num;
			info->philo[i].r_fork = i;
		}
		info->philo[i].info = info;
	}
	return (0);
}

int	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	info->p_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat_num = 0;
	info->die = LIVE;
	info->eat_check = NOT_ENOUGH;
	if (ac == 6)
		info->must_eat_num = ft_atoi(av[5]);
	if (mutex_init(info) || philo_init(info) || fork_init(info))
		return (FAIL);
	return (SUCCESS);
}
