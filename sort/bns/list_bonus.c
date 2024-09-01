/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:06:22 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 18:34:18 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_list	*ft_lstnew(int val, t_list *head, t_list *tail)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (0);
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

void	free_list(t_list **a)
{
	t_list	*node;
	t_list	*temp;

	node = *a;
	while (node->next != *a)
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

t_list	*init_stack(int argc, int *num_list)
{
	int		index;
	t_list	*node;

	if (!num_list)
		error_exit("Error\n", STDERR_FILENO);
	node = NULL;
	index = 0;
	while (index < argc - 1)
	{
		ft_lstadd_back(&node, num_list[index]);
		index++;
	}
	return (node);
}
