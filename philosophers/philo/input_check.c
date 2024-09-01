/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:35:12 by wooseoki          #+#    #+#             */
/*   Updated: 2023/06/10 16:25:37 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_positive_int(char *argument)
{
	size_t	index;

	index = 0;
	if (argument[index] == '-')
		return (FALSE);
	if (argument[index] == '+')
		index++;
	while (argument[index])
	{
		if (is_digit(argument[index]) == FALSE)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	is_valid_input(int argc, char **argv)
{
	size_t	index;

	if (argc == 5 || argc == 6)
	{
		index = 1;
		while (argv[index])
		{
			if (is_positive_int(argv[index]) == FALSE)
				return (FALSE);
			index++;
		}
		return (TRUE);
	}
	return (FALSE);
}
