/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:40 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/29 18:49:25 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_stack(char *str, t_node **a, t_node **b)
{
	char	**strs;
	int		num;
	int		i;

	*a = 0;
	*b = 0;
	i = -1;
	strs = ft_split(str, ' ');
	while (strs[++i])
	{
		num = ft_atoi_int(strs[i]);
		ft_add_node(a, ft_newnode(num));
		str++;
	}
}

int	get_arr_len(char **strs)
{
	int	count_num;

	count_num = 0;
	while (*strs)
	{
		count_num++;
		strs++;
	}
	return (count_num);
}

int	get_nodes_size(int ac, char **av)
{
	char	**strs;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		ret += get_arr_len(strs);
	}
	return (ret);
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

char	*sum_arg(int ac, char **av)
{
	int		i;
	int		j;
	char	*ret;
	char	**strs;

	i = 0;
	ret = ft_strdup("");
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = -1;
		while (strs[++j])
		{
			ret = ft_strjoin(ret, strs[j]);
			ret = ft_strjoin(ret, " ");
		}
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_node		*head;
	int			len;
	char		*str;
	int			i;

	if (ac < 2)
		return (0);
	len = get_nodes_size(ac, av);
	str = sum_arg(ac, av);
	init_nodes_stack(str, &a, &b);
	head = a;
	i = 0;
	while (i < len)
	{
		ft_printf("%d ", a->value);
		a = a->pre;
		i++;
	}
	ft_printf("\n");
	sort_nodes(&a, &b, len);
	i = 0;
	a = head;
	while (i < len)
	{
		ft_printf("%d ", a->value);
		a = a->pre;
		i++;
	}
	return (0);
}
