/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/29 14:16:52 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_stack(int ac, char **av, t_node **a, t_node **b)
{
	char		**arr;
	int			i;

	*a = 0;
	*b = 0;
	if (ac == 2)
	{
		i = -1;
		arr = ft_split(av[1], ' ');
		while (arr[++i])
		{
			ft_add_node(a, ft_newnode(ft_atoi(arr[i])));
		}
		return ;
	}
	i = 0;
	while (av[++i])
	{
		ft_add_node(a, ft_newnode(ft_atoi(av[i])));
	}
	return ;
}

int	get_nodes_size(int ac, char **av)
{
	char	**str;
	int		i;

	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		while (str[i])
		{
			i++;
		}
		return (i);
	}
	else if (ac > 2)
		return (ac - 1);
	return (-1);
}

int	*put_value_in_arr(t_node *a, int len)
{
	int	*ret;
	int	i;

	i = -1;
	ret = (int *)malloc(sizeof(int) * (len));
	if (!ret)
		exit(-1);
	while (++i < len)
	{
		ret[i] = a->value;
		a = a->next;
	}
	return (ret);
}

void	sort_nodes(t_node **a, t_node **b, int len)
{
	a_to_b(a, b, len);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	int			len;

	if (ac < 2)
		return (0);
	len = get_nodes_size(ac, av);
	init_nodes_stack(ac, av, &a, &b);
	sort_nodes(&a, &b, len);
	for (int i =0;i<len;i++)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	ft_printf("\n");
	return (0);
}
