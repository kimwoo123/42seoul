/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:18:21 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/14 14:09:42 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	greedy(t_info *info)
{
	int	a_index;
	int	b_index;

	while (info->b_size)
	{
		a_index = 0;
		b_index = 0;
		find_best(info, &a_index, &b_index);
		rotate_both(info, &a_index, &b_index);
		rotate_a(info, a_index);
		rotate_b(info, b_index);
		pa_cmd(info->a_stack, info->b_stack, NOTCHECKER);
		(info->a_size)++;
		(info->b_size)--;
	}
	last_sort(info);
}

int	search_b(t_info *info, int find)
{
	t_list	*node;
	t_list	*prev;
	int		index;

	index = 0;
	node = *(info->a_stack);
	while (node)
	{
		prev = node->prev;
		if (prev->value > find && node->value > find && \
				prev->value > node->value)
			break ;
		if (prev->value < find && node->value > find && \
				prev->value < node->value)
			break ;
		if (prev->value < find && node->value < find && \
				prev->value > node->value)
			break ;
		node = node->next;
		++index;
	}
	if (index > info->a_size / 2)
		index = index - info->a_size;
	return (index);
}

int	total_compare(int a_i, int b_i, int a_mi, int b_mi)
{
	int	total;
	int	total_m;

	total = 0;
	if (a_i < 0)
		total -= a_i;
	else
		total += a_i;
	if (b_i < 0)
		total -= b_i;
	else
		total += b_i;
	total_m = 0;
	if (a_mi < 0)
		total_m -= a_mi;
	else
		total_m += a_mi;
	if (b_mi < 0)
		total_m -= b_mi;
	else
		total_m += b_mi;
	return (total < total_m);
}

void	find_best(t_info *info, int *a_min_index, int *b_min_index)
{
	t_list	*b_node;
	int		a_index;
	int		b_index;
	int		index;

	index = 0;
	b_node = *(info->b_stack);
	while (index < info->b_size)
	{
		a_index = search_b(info, b_node->value);
		if (index >= (info->b_size + 1) / 2)
			b_index = index - info->b_size;
		else
			b_index = index;
		if (!index || \
				total_compare(a_index, b_index, *a_min_index, *b_min_index))
		{
			*a_min_index = a_index;
			*b_min_index = b_index;
		}
		b_node = b_node->next;
		index++;
	}
}
