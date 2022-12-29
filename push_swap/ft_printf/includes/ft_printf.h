/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:49:56 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/29 14:08:00 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../lib/libft.h"

//main
int		ft_printf(const char *str, ...);

//option
int		type_c(va_list ap);
int		type_s(va_list ap);
int		type_d(va_list ap);
int		type_u(va_list ap);
int		type_x(char c, va_list ap);
int		type_p(va_list ap);
int		type_per(void);

//utils
int		ft_putchar(int c);
int		ft_putstr(char *str);
void	ft_putunnbr(unsigned int nb);
int		ft_putptr(uintptr_t ptr);
int		ft_num_length(long long lnum, int base);
int		ft_convert_base(unsigned int nb, const char *base);

#endif
