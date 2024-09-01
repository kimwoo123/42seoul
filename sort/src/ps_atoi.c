/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:23:30 by wooseoki          #+#    #+#             */
/*   Updated: 2023/02/12 18:31:51 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	check_sign(char c)
{
	if (c == '-' || c == '+' || is_digit(c))
		return (c);
	return (0);
}

static int	num_len(long long num)
{
	int	count;

	count = 0;
	while (num)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static int	convert_str(char *str, size_t index, char sign)
{
	long long	number;

	number = 0;
	while (str[index])
	{
		if (is_digit(str[index]))
		{
			number *= 10;
			number += str[index] - '0';
		}
		else
			error_exit("Error\n", STDERR_FILENO);
		index++;
	}
	if (sign == '-')
		number *= -1;
	if (number > INTMAX || number < INTMIN || num_len(number) >= 12)
		error_exit("Error\n", STDERR_FILENO);
	return (number);
}

int	ft_atoi(char *str)
{
	size_t	index;
	char	sign;
	int		number;

	index = 0;
	sign = check_sign(str[index]);
	if (sign == '-' || sign == '+')
		index++;
	if (!sign)
		error_exit("Error\n", STDERR_FILENO);
	number = convert_str(str, index, sign);
	return (number);
}
