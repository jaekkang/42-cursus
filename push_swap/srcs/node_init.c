/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:11:34 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/30 16:57:21 by jaekkang         ###   ########.fr       */
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
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		ret += get_arr_len(strs);
	}
	return (ret);
}

int	*get_int_arr(t_node *a, int len)
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
		a = a->pre;
	}
	return (ret);
}

char	*sum_arg(int ac, char **av)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;
	char	**strs;

	i = 0;
	ret = ft_strdup("");
	while (++i < ac)
	{
		strs = ft_split(av[i], ' ');
		j = -1;
		while (strs[++j])
		{
			tmp = ft_strjoin(ret, strs[j]);
			ret = ft_strjoin(tmp, " ");
		}
	}
	return (ret);
}
