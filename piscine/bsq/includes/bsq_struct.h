/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:53:03 by myko              #+#    #+#             */
/*   Updated: 2022/06/08 05:46:05 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_STRUCT_H
# define BSQ_STRUCT_H

typedef struct s_words
{
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	filled;
}	t_words;

typedef struct s_pos
{
	int	x;
	int	y;
	int	length;
}	t_pos;

#endif