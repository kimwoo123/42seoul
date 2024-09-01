/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:29 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/14 16:29:26 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	push_stack(t_list **stack, int value)
{
	t_list	*head;
	t_list	*tail;
	t_list	*new;

	if (!*stack)
	{
		*stack = ft_lstnew(value, NULL, NULL);
		return ;
	}
	head = (*stack);
	tail = (*stack)->prev;
	new = ft_lstnew(value, head, tail);
	head->prev = new;
	tail->next = new;
	*stack = new;
}

int	pop_stack(t_list **stack)
{
	t_list	*node;
	int		ret;

	ret = (*stack)->value;
	if ((*stack)->next == *stack)
	{
		free(*stack);
		*stack = NULL;
		return (ret);
	}
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	node = *stack;
	*stack = (*stack)->next;
	free(node);
	return (ret);
}

void	pa_cmd(t_list **a_stack, t_list **b_stack, int is_checker)
{
	int	value;

	if (!*b_stack)
		return ;
	value = pop_stack(b_stack);
	push_stack(a_stack, value);
	if (!is_checker)
		write(1, "pa\n", 3);
}

void	pb_cmd(t_list **a_stack, t_list **b_stack, int is_checker)
{
	int	value;

	if (!*a_stack)
		return ;
	value = pop_stack(a_stack);
	push_stack(b_stack, value);
	if (!is_checker)
		write(1, "pb\n", 3);
}

void	ra_cmd(t_list **a_stack, int is_checker)
{
	if (!*a_stack)
		return ;
	*a_stack = (*a_stack)->next;
	if (!is_checker)
		write(1, "ra\n", 3);
}
