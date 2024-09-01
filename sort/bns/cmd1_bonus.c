/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:05:12 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/16 11:28:12 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa_cmd(t_list **a_stack, int is_checker)
{
	int	temp_value;

	if (!*a_stack)
		return ;
	temp_value = (*a_stack)->value;
	(*a_stack)->value = (*a_stack)->next->value;
	(*a_stack)->next->value = temp_value;
	if (!is_checker)
		write(1, "sa\n", 3);
}

void	sb_cmd(t_list **b_stack, int is_checker)
{
	int	temp_value;

	if (!*b_stack)
		return ;
	temp_value = (*b_stack)->value;
	(*b_stack)->value = (*b_stack)->next->value;
	(*b_stack)->next->value = temp_value;
	if (!is_checker)
		write(1, "sb\n", 3);
}

void	ss_cmd(t_list **a_stack, t_list **b_stack, int is_checker)
{
	int	temp_value;

	if (!*a_stack || !*b_stack)
		return ;
	temp_value = (*b_stack)->value;
	(*b_stack)->value = (*b_stack)->next->value;
	(*b_stack)->next->value = temp_value;
	temp_value = (*a_stack)->value;
	(*a_stack)->value = (*a_stack)->next->value;
	(*a_stack)->next->value = temp_value;
	if (!is_checker)
		write(1, "ss\n", 3);
}
