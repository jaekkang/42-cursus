/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:11:34 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 19:27:25 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_stack(char *str, t_node **a, t_node **b, t_cmd **cmd)
{
	t_node		*tmp;
	char		**strs;
	int			num;
	int			i;

	*a = 0;
	*b = 0;
	*cmd = 0;
	i = -1;
	strs = ft_split(str, ' ');
	if (*strs == NULL)
		print_err_msg();
	while (strs[++i])
	{
		num = ft_atoi_int(strs[i]);
		tmp = ft_newnode(num);
		ft_add_node(a, tmp);
		str++;
	}
	ft_free_all(strs);
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
		ft_free_all(strs);
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
		exit(EXIT_FAILURE);
	while (++i < len)
	{
		ret[i] = a->value;
		a = a->next;
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
		if (!*av[i])
			print_err_msg();
		strs = ft_split(av[i], ' ');
		j = -1;
		while (strs[++j])
		{
			tmp = ft_strjoin(ret, strs[j]);
			free(ret);
			ret = ft_strjoin(tmp, " ");
			free(tmp);
		}
		ft_free_all(strs);
	}
	return (ret);
}
