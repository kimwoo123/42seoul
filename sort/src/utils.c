/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:22:39 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 14:45:22 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_num(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	stack_size(t_list **stack)
{
	t_list	*node;
	int		count;

	node = *stack;
	count = 0;
	while (node)
	{
		++count;
		node = node->next;
		if (node == *stack)
			break ;
	}
	return (count);
}
