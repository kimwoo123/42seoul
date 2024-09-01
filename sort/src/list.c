/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:06:22 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/13 16:05:48 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_lstnew(int val, t_list *head, t_list *tail)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		exit(0);
	result->value = val;
	if (!head)
		result->next = result;
	else
		result->next = head;
	if (!tail)
		result->prev = result;
	else
		result->prev = tail;
	return (result);
}

void	ft_lstadd_back(t_list **lst, int value)
{
	t_list	*last;
	t_list	*new;

	if (!*lst)
	{
		*lst = ft_lstnew(value, NULL, NULL);
		return ;
	}
	last = (*lst)->prev;
	if (last == *lst)
	{
		new = ft_lstnew(value, *lst, last);
		last->next = new;
		last->prev = new;
	}
	else
	{
		new = ft_lstnew(value, *lst, last);
		last->next = new;
		(*lst)->prev = new;
	}
}

int	is_sorted(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next != *stack)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	check_stack(t_list *stack)
{
	if (is_sorted(&stack))
		exit(0);
	if (stack_size(&stack) < 4)
	{
		manual_sort(&stack);
		exit(0);
	}
}

void	free_list(t_list **stack)
{
	t_list	*node;
	t_list	*temp;

	node = *stack;
	while (node->next != *stack)
	{
		temp = node->next;
		if (node)
		{
			free(node);
			node = NULL;
		}
		node = temp;
	}
	exit(1);
}
