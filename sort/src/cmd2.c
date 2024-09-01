/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:09:44 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:10:26 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb_cmd(t_list **b_stack, int is_checker)
{
	*b_stack = (*b_stack)->next;
	if (!is_checker)
		write(1, "rb\n", 3);
}

void	rra_cmd(t_list **a_stack, int is_checker)
{
	*a_stack = (*a_stack)->prev;
	if (!is_checker)
		write(1, "rra\n", 4);
}

void	rrb_cmd(t_list **b_stack, int is_checker)
{
	*b_stack = (*b_stack)->prev;
	if (!is_checker)
		write(1, "rrb\n", 4);
}

void	rr_cmd(t_list **a_stack, t_list **b_stack, int is_checker)
{
	*a_stack = (*a_stack)->next;
	*b_stack = (*b_stack)->next;
	if (!is_checker)
		write(1, "rr\n", 3);
}

void	rrr_cmd(t_list **a_stack, t_list **b_stack, int is_checker)
{
	*a_stack = (*a_stack)->prev;
	*b_stack = (*b_stack)->prev;
	if (!is_checker)
		write(1, "rrr\n", 4);
}
