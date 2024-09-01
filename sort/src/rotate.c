/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:13:09 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 14:25:45 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_both(t_info *info, int *a, int *b)
{
	while ((*a > 0 && *b > 0) && *a && *b)
	{
		rr_cmd(info->a_stack, info->b_stack, NOTCHECKER);
		--*a;
		--*b;
	}
	while ((*a < 0 && *b < 0) && *a && *b)
	{
		rrr_cmd(info->a_stack, info->b_stack, NOTCHECKER);
		++*a;
		++*b;
	}
}

void	rotate_a(t_info *info, int a)
{
	if (a > 0)
	{
		while (a)
		{
			ra_cmd(info->a_stack, NOTCHECKER);
			--a;
		}
	}
	else
	{
		while (a)
		{
			rra_cmd(info->a_stack, NOTCHECKER);
			++a;
		}
	}
}

void	rotate_b(t_info *info, int b)
{
	if (b > 0)
	{
		while (b)
		{
			rb_cmd(info->b_stack, NOTCHECKER);
			--b;
		}
	}
	else
	{
		while (b)
		{
			rrb_cmd(info->b_stack, NOTCHECKER);
			++b;
		}
	}
}

int	need_rotate(t_info *info)
{
	t_list	*node;
	int		index;

	index = 0;
	node = *(info->a_stack);
	while (node->value != info->min_num)
	{
		if (node->value > node->next->value)
			return (index);
		index++;
		node = node->next;
	}
	return (0);
}

void	last_sort(t_info *info)
{
	int		rotate_count;
	t_list	*head;

	head = *(info->a_stack);
	rotate_count = need_rotate(info);
	if (rotate_count > info->a_size / 2)
	{
		while ((*(info->a_stack))->value != info->min_num)
			rra_cmd(info->a_stack, NOTCHECKER);
	}
	else
	{
		while ((*(info->a_stack))->value != info->min_num)
			ra_cmd(info->a_stack, NOTCHECKER);
	}
}
