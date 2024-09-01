/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:31:26 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/16 11:36:26 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	search_cmd(char *line, t_list **a_stack, t_list **b_stack)
{
	if (ft_strnstr(line, "sa\n", 3))
		sa_cmd(a_stack, ISCHECKER);
	else if (ft_strnstr(line, "sb\n", 3))
		sb_cmd(b_stack, ISCHECKER);
	else if (ft_strnstr(line, "ss\n", 3))
		ss_cmd(a_stack, b_stack, ISCHECKER);
	else if (ft_strnstr(line, "pa\n", 3))
		pa_cmd(a_stack, b_stack, ISCHECKER);
	else if (ft_strnstr(line, "pb\n", 3))
		pb_cmd(a_stack, b_stack, ISCHECKER);
	else if (ft_strnstr(line, "ra\n", 3))
		ra_cmd(a_stack, ISCHECKER);
	else if (ft_strnstr(line, "rb\n", 3))
		rb_cmd(b_stack, ISCHECKER);
	else if (ft_strnstr(line, "rr\n", 3))
		rr_cmd(a_stack, b_stack, ISCHECKER);
	else if (ft_strnstr(line, "rra\n", 4))
		rra_cmd(a_stack, ISCHECKER);
	else if (ft_strnstr(line, "rrb\n", 4))
		rrb_cmd(b_stack, ISCHECKER);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr_cmd(a_stack, b_stack, ISCHECKER);
	else
		return (0);
	return (1);
}

void	error_exit(char *msg, int fd)
{
	size_t	index;

	index = 0;
	while (msg[index])
		index++;
	write(fd, msg, index);
	exit(1);
}

int	*input_check(int argc, char **argv)
{
	int		*num_list;
	int		index;
	int		r_index;

	num_list = (int *)malloc(sizeof(int) * (argc - 1));
	if (!num_list)
		return (NULL);
	index = 1;
	while (argv[index])
	{
		num_list[index - 1] = ft_atoi(argv[index]);
		r_index = 0;
		while (r_index < index - 1)
		{
			if (num_list[index - 1] == num_list[r_index])
				return (NULL);
			r_index++;
		}
		index++;
	}
	return (num_list);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_list	*a_stack;
	t_list	*b_stack;
	int		*num_list;

	if (argc < 2)
		exit(0);
	num_list = input_check(argc, argv);
	a_stack = init_stack(argc, num_list);
	b_stack = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!search_cmd(line, &a_stack, &b_stack))
			error_exit("Error\n", STDERR_FILENO);
		free(line);
	}
	if (is_sorted(&a_stack) && !b_stack)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	return (0);
}
