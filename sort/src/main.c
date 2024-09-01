/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:11:26 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/16 11:45:47 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_exit(char *msg, int fd)
{
	size_t	index;

	index = 0;
	while (msg[index])
		index++;
	write(fd, msg, index);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	t_info	*info;
	int		*num_list;

	if (argc < 2)
		exit(0);
	num_list = input_check(argc, argv);
	if (!num_list)
		error_exit("Error\n", STDERR_FILENO);
	a_stack = init_stack(argc, num_list);
	b_stack = NULL;
	check_stack(a_stack);
	select_pivot(num_list, 0, argc - 2);
	divide_stack(&a_stack, &b_stack, argc, num_list);
	if (!is_sorted(&a_stack))
		manual_sort(&a_stack);
	info = init_info(&a_stack, &b_stack, num_list[0]);
	greedy(info);
	return (0);
}
