/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:11:13 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/13 13:49:55 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define INTMAX 2147483647
# define INTMIN -2147483648
# define ISCHECKER 1
# define NOTCHECKER 0

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_info
{
	int				a_size;
	int				b_size;
	int				min_num;
	struct s_list	**a_stack;
	struct s_list	**b_stack;
}	t_info;

t_info	*init_info(t_list **a_stack, t_list **b_stack, int min_num);
t_list	*ft_lstnew(int vla, t_list *head, t_list*tail);
t_list	*init_stack(int argc, int *num_list);
void	free_list(t_list **stack);
void	swap_num(int *a, int *b);
void	greedy(t_info *info);
void	last_sort(t_info *info);
void	check_stack(t_list *stack);
void	rotate_both(t_info *info, int *a, int *b);
void	rotate_a(t_info *info, int a);
void	rotate_b(t_info *info, int b);
void	sa_cmd(t_list **a_stack, int is_checker);
void	sb_cmd(t_list **b_stack, int is_checker);
void	ss_cmd(t_list **a_stack, t_list **b_stack, int is_checker);
void	pa_cmd(t_list **a_stack, t_list **b_stack, int is_checker);
void	pb_cmd(t_list **a_stack, t_list **b_stack, int is_checker);
void	ra_cmd(t_list **a_stack, int is_checker);
void	rb_cmd(t_list **b_stack, int is_checker);
void	rra_cmd(t_list **a_stack, int is_checker);
void	rrb_cmd(t_list **b_stack, int is_checker);
void	rr_cmd(t_list **a_stack, t_list **b_stack, int is_checker);
void	rrr_cmd(t_list **a_stack, t_list **b_stack, int is_checker);
void	ft_lstadd_back(t_list **list, int value);
void	push_stack(t_list **stack, int value);
void	error_exit(char *msg, int fd);
void	select_pivot(int *num_list, int start, int end);
void	find_best(t_info *info, int *a_min_index, int *b_min_index);
void	manual_sort(t_list **a_stack);
void	three_elem_sort(t_list **stack);
void	two_elem_sort(t_list **stack);
void	divide_stack(t_list **a_stack, t_list **b_stack, int argc, int *n_l);
int		stack_size(t_list **stack);
int		search_b(t_info *info, int find);
int		total_compare(int a_i, int b_i, int a_mi, int b_mi);
int		need_rotate(t_info *info);
int		*input_check(int argc, char **argv);
int		pop_stack(t_list **stack);
int		is_sorted(t_list **stack);
int		ft_atoi(char *str);
int		main(int argc, char **argv);

#endif
