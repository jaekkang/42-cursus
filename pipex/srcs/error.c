/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:42:02 by jaekkang          #+#    #+#             */
/*   Updated: 2022/11/04 01:28:42 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	print_errmsg_n_exit(int err, char *msg)
{
	if (err && msg[0])
	{
		ft_putstr_fd(msg, 2);
	}
	exit(err);
}