/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:37:45 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 21:17:39 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	run_both(char *op, t_node **a, t_node **b)
{
	if (!ft_strncmp(op, "ss\n", 4))
	{
		oper_s(a);
		oper_s(b);
	}
	else if (!ft_strncmp(op, "rr\n", 4))
	{
		oper_r(a);
		oper_r(b);
	}
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		oper_rr(a);
		oper_rr(b);
	}
}

void	run_op(char *op, t_node **a, t_node **b)
{
	if (!ft_strncmp(op, "sa\n", 4))
		oper_s(a);
	else if (!ft_strncmp(op, "sb\n", 4))
		oper_s(b);
	else if (!ft_strncmp(op, "ss\n", 4))
		run_both(op, a, b);
	else if (!ft_strncmp(op, "pa\n", 4))
		oper_p(a, b, 'a');
	else if (!ft_strncmp(op, "pb\n", 4))
		oper_p(a, b, 'b');
	else if (!ft_strncmp(op, "ra\n", 4))
		oper_r(a);
	else if (!ft_strncmp(op, "rb\n", 4))
		oper_r(b);
	else if (!ft_strncmp(op, "rr\n", 4))
		run_both(op, a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		oper_rr(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		oper_rr(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		run_both(op, a, b);
	else
		print_err_msg();
}

void	checker(t_node **a, t_node **b)
{
	char	*op;

	op = 0;
	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		run_op(op, a, b);
		free(op);
	}
}

int	get_stack_size(t_node **stack)
{
	t_node	*tmp;
	int		i;

	i = 1;
	if (!*stack)
		return (0);
	tmp = (*stack)->next;
	while (tmp != (*stack))
	{
		*stack = (*stack)->next;
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_cmd		*cmd;
	int			len;
	char		*str;

	if (ac < 2)
		return (0);
	len = get_nodes_size(ac, av);
	str = sum_arg(ac, av);
	init_nodes_stack(str, &a, &b, &cmd);
	free(str);
	if (is_double_val(&a))
		print_err_msg();
	checker(&a, &b);
	if (get_stack_size(&b) == 0 && is_sorted(&a, len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_nodeclear(a);
	ft_nodeclear(b);
	return (0);
}
