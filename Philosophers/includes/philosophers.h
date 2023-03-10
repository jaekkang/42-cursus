/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:58:48 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 20:19:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define AC_WRONG_MSG "ERROR\nWrong argument\n"
# define RUN_FAIL_MSG "ERROR\nrun_philo() function running fail\n"
# define WRONG_ARG_MSG "ERROR\nInvalid data\n"

typedef enum s_return
{
	SUCCESS,
	FAIL,
}	t_return;

typedef enum s_flags
{
	SUCCESS_FLAG,
	FAIL_FLAG,
	LIVE,
	DIE,
	ENOUGH,
	NOT_ENOUGH,
	USING,
	NOT_USING,
}	t_flags;

typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_cnt;
	long long		check_d_time;
	struct s_info	*info;
}				t_philo;

typedef struct s_info
{
	int				p_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				die;
	int				eat_check;
	int				*forks;
	long long		start_time;
	long long		last_eat_time;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	pthread_mutex_t	*pick_up;
	pthread_mutex_t	c_die;
	t_philo			*philo;
}				t_info;

// Utils
int			ft_strlen(char *str);
int			ft_atoi(char *str);
void		get_eat_time(t_info *info, t_philo *philo);
void		get_sleep_time(t_info *info, t_philo *philo);
void		ft_eat_check(t_info *info, t_philo *philo);
void		ft_philo_eat(t_info *info, t_philo *philo);
long long	get_time(void);
int			check_die(t_info *info);

// Init
int			check_info(t_info *info, int ac);
int			init_info(t_info *info, int ac, char **av);

// Main
void		print_action(t_info *info, char *str, int id, long long ts);
void		*routine(void *philo);
void		handle_one_philo(t_info *info);
int			eating(t_info *info, t_philo *philo);
void		mornitor(t_info *info, t_philo *philo);
int			philosopher(t_info *info);
void		end_philo(t_info *info);

#endif