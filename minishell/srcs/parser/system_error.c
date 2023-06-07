/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:23:12 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/20 10:11:38 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_allocation_error(void)
{
	write(2, "Allocation Error!\n", 18);
	exit(1);
}

void	ft_open_error(void)
{
	write(2, "Open system call Error!\n", 24);
	exit(1);
}
