/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:43:18 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/16 11:44:29 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	divide_stack(t_list **a_stack, t_list **b_stack, int argc, int *n_l)
{
	int	pivot_large;
	int	pivot_small;

	pivot_small = n_l[(argc - 1) / 3];
	pivot_large = n_l[(argc - 1) / 3 * 2];
	argc--;
	while (argc--)
	{
		if (pivot_large > (*a_stack)->value)
		{
			pb_cmd(a_stack, b_stack, NOTCHECKER);
			if (pivot_small > (*b_stack)->value)
				rb_cmd(b_stack, NOTCHECKER);
		}
		else
			ra_cmd(a_stack, NOTCHECKER);
	}
	while (stack_size(a_stack) > 3)
		pb_cmd(a_stack, b_stack, NOTCHECKER);
}

t_info	*init_info(t_list **a_stack, t_list **b_stack, int min_num)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		exit (1);
	info->a_stack = a_stack;
	info->b_stack = b_stack;
	info->min_num = min_num;
	info->a_size = stack_size(a_stack);
	info->b_size = stack_size(b_stack);
	return (info);
}

int	*input_check(int argc, char **argv)
{
	int		*num_list;
	size_t	index;
	size_t	r_index;

	num_list = (int *)malloc(sizeof(int) * (argc - 1));
	if (!num_list)
		exit(1);
	index = 1;
	while (argv[index])
	{
		num_list[index - 1] = ft_atoi(argv[index]);
		r_index = 0;
		while (r_index < index - 1)
		{
			if (num_list[r_index] == num_list[index - 1])
			{
				free(num_list);
				return (NULL);
			}
			r_index++;
		}
		index++;
	}
	return (num_list);
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

void	select_pivot(int *num_list, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && num_list[i] <= num_list[pivot])
			i++;
		while (j > start && num_list[j] >= num_list[pivot])
			j--;
		if (i > j)
			swap_num(&num_list[j], &num_list[pivot]);
		else
			swap_num(&num_list[i], &num_list[j]);
	}
	select_pivot(num_list, start, j - 1);
	select_pivot(num_list, j + 1, end);
}
