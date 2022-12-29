/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:11:20 by jaekkang          #+#    #+#             */
/*   Updated: 2022/12/29 17:30:39 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_node
{
	struct s_node	*pre;
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct s_node_info {
	struct s_node	head;
	struct s_node	tail;
	int				len;
}	t_node_info;

typedef struct s_info
{
	int	len;
	int	pi1;
	int	pi2;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_pb;
}	t_info;

t_node	*ft_newnode(int num);
void	ft_add_front(t_node **lst, t_node *new);
void	ft_add_node(t_node **a, t_node *node);
void	quick_sort(int *arr, int left, int right);
void	ft_swap(int *a, int *b);
t_node	*pop_node(t_node **list);
int		push_node(t_node **dst, t_node *src);
void	oper_sa(t_node *stack);
void	a_to_b(t_node **a, t_node **b, int len);
void	b_to_a(t_node **a, t_node **b, int len);
int		*put_value_in_arr(t_node *a, int len);
void	set_pivot(t_node *stack, int len, t_info *info, char target);
void	oper_p(t_node **a, t_node **b, char target);
void	oper_r(t_node **stack);
void	oper_s(t_node **stack);
void	oper_rr(t_node **stack);
void	oper_rrr(t_node **a, t_node **b);
void	run_rrr(t_node **a, t_node **b, int len);
void	ft_swap_node(t_node *a, t_node *b);
int	ft_atoi_int(const char *str);

#endif