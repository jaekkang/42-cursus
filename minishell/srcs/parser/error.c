/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:23:03 by jaekkang          #+#    #+#             */
/*   Updated: 2023/04/20 10:12:08 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syntax_error(t_p_data *pdata, t_word *word)
{
	write(2, "syntax Error!\n", 14);
	word->break_flag = ON;
	ft_clear_all_pdata(pdata);
}
