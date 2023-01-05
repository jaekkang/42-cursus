/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:23 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 18:09:39 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_free(char **s)
{
	int	i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i])
			free(s[i]);
	}
	free(s);
}

void	print_err_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi_int(const char *str)
{
	long long	ret;
	int			sign;

	sign = 1;
	ret = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
		if (*str == '\0')
			print_err_msg();
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_err_msg();
		ret = ret * 10 + (*str - '0');
		str++;
	}
	ret *= sign;
	if (ret > 2147483647 || ret < -2147483648)
		print_err_msg();
	return (ret);
}

int	is_double_val(t_node **a)
{
	t_node	*tmp;
	t_node	*head;

	head = *a;
	tmp = (*a)->next;
	while (head != tmp)
	{
		tmp = head->next;
		while (tmp != *a)
		{
			if (head->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

int	is_sorted(t_node **a, int len)
{
	t_node	*head;

	head = (*a);
	while (len-- > 1)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
