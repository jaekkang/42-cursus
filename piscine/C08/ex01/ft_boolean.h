/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:25:54 by jaekkang          #+#    #+#             */
/*   Updated: 2022/06/04 14:40:01 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have odd number of arguments.\n"
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define EVEN(nbr) (nbr % 2 == 0)

typedef int	t_bool;

#endif
