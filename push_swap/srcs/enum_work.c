/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:19:56 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/10 16:01:52 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enum_work(char *op, t_node **a, t_node **b, t_cmd **cmd)
{
	if (!ft_strcmp(op, "sa") && oper_s(a))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("sa"));
	else if (!ft_strcmp(op, "sb") && oper_s(b))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("sb"));
	else if (!ft_strcmp(op, "ra") && oper_r(a))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("ra"));
	else if (!ft_strcmp(op, "rb") && oper_r(b))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("rb"));
	else if (!ft_strcmp(op, "rra") && oper_rr(a))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("rra"));
	else if (!ft_strcmp(op, "rrb") && oper_rr(b))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("rrb"));
	else if (!ft_strcmp(op, "pa") && oper_p(a, b, 'a'))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("pa"));
	else if (!ft_strcmp(op, "pb") && oper_p(a, b, 'b'))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("pb"));
	else if (!ft_strcmp(op, "rrr") && oper_rrr(a, b))
		ft_lstadd_back_cmd(cmd, ft_lstnew_cmd("rrr"));
}
