/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:47:03 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 18:52:27 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

t_list	*ft_lstnew(int vla, t_list *head, t_list*tail);
t_list	*init_stack(int argc, int *num_list);
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
void	error_exit(char *msg, int fd);
int		search_cmd(char *line, t_list **a_stack, t_list **b_stack);
int		*input_check(int argc, char **argv);
int		is_sorted(t_list **stack);
int		main(int argc, char **argv);
int		ft_atoi(char *str);
#endif
