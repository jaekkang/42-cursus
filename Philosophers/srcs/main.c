/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:36:32 by jaekkang          #+#    #+#             */
/*   Updated: 2023/03/10 13:11:31 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (init_info(&info, ac, av) == FAIL)
	{
		write(STDERR_FILENO, AC_WRONG_MSG, ft_strlen(AC_WRONG_MSG));
		return (EXIT_FAILURE);
	}	
	if (check_info(&info, ac))
	{
		write(STDERR_FILENO, WRONG_ARG_MSG, ft_strlen(WRONG_ARG_MSG));
		return (EXIT_FAILURE);
	}
	if (info.p_num == 1)
	{
		handle_one_philo(&info);
		return (EXIT_SUCCESS);
	}
	if (philosopher(&info) == FAIL)
	{
		write(STDERR_FILENO, RUN_FAIL_MSG, ft_strlen(RUN_FAIL_MSG));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
