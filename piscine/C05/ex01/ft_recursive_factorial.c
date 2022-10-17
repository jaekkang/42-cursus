/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:45:56 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/31 23:46:00 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial_re(int n)
{
	if (n < 0)
		return (0);
	if (n == 0 || n == 1)
		return (1);
	return (n * ft_factorial_re(n - 1));
}

int	ft_recursive_factorial(int nb)
{
	return (ft_factorial_re(nb));
}
