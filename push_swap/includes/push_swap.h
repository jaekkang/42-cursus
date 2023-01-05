/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:11:20 by jaekkang          #+#    #+#             */
/*   Updated: 2023/01/05 14:40:03 by jaekkang         ###   ########.fr       */
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

// for init -> make int arr
void	init_nodes_stack(char *str, t_node **a, t_node **b);
int		get_arr_len(char **strs);
int		get_nodes_size(int ac, char **av);
int		*get_int_arr(t_node *a, int len);
char	*sum_arg(int ac, char **av);
int		ft_atoi_int(const char *str);
// for init -> make new node & linked list
t_node	*ft_newnode(int num);
void	ft_add_front(t_node **lst, t_node *new);
void	ft_add_node(t_node **a, t_node *node);
// for sorting 
void	set_pivot(t_node *stack, int len, t_info *info, char target);
void	quick_sort(int *arr, int left, int right);
t_node	*pop_node(t_node **list);
int		push_node(t_node **dst, t_node *src);
void	a_to_b(t_node **a, t_node **b, int len);
void	b_to_a(t_node **a, t_node **b, int len);
void	ft_swap_node(t_node *a, t_node *b);
void	ft_swap(int *a, int *b);
void	sort_3_arg(t_node **a, t_node **b, int len);
void	sort_4_arg(t_node **a, t_node **b, int len);
void	sort_5_arg(t_node **a, t_node **b, int len);
int		is_sorted(t_node **a, int len);
int		is_sorted_row(t_node **a, int len);
// opers
int		oper_p(t_node **a, t_node **b, char target);
int		oper_r(t_node **stack);
int		oper_s(t_node **stack);
int		oper_rr(t_node **stack);
int		oper_rrr(t_node **a, t_node **b);
void	run_rrr(t_node **a, t_node **b, int len);
//utils
void	print_node(t_node **a);
void	print_err_msg(void);
int		is_double_val(t_node **a);
void	enum_work(char *op, t_node **a, t_node **b);
int		get_min_node_value(t_node **a);
int		get_max_node_value(t_node **a);
int		get_middle_node_value(t_node **a, int len);
#endif