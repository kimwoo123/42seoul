/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:32:26 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 18:32:54 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	two_elem_sort(t_list **stack)
{
	t_list	*node;

	node = *stack;
	if (node->value > node->next->value)
		sa_cmd(stack, NOTCHECKER);
}

void	manual_sort(t_list **a_stack)
{
	int		size;

	size = stack_size(a_stack);
	if (size == 3)
		three_elem_sort(a_stack);
	else if (size == 2)
		two_elem_sort(a_stack);
}

void	three_elem_sort(t_list **stack)
{
	t_list	*node;

	node = *stack;
	if ((node->value > node->next->value && \
		node->value < node->prev->value) || \
		(node->value > node->next->value && \
		node->next->value > node->prev->value) || \
			(node->value < node->prev->value && \
		node->prev->value < node->next->value))
		sa_cmd(stack, NOTCHECKER);
	if ((node->value < node->next->value && \
				node->value > node->prev->value))
		rra_cmd(stack, NOTCHECKER);
	if ((node->value > node->next->value && \
				node->value > node->prev->value))
		ra_cmd(stack, NOTCHECKER);
}
