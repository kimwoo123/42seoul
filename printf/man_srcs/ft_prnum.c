/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:15:21 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/05 10:46:31 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_to_hex(unsigned int number, int *count, char *hex_base)
{
	if (number < 16)
	{
		write(1, &hex_base[number], 1);
		(*count)++;
	}
	else
	{
		num_to_hex(number / 16, hex_base, count);
		num_to_hex(number % 16, hex_base, count);
	}
}

void	pr_hex(unsigned int number, int *count, char format)
{
	char	*hex_base;

	if (format == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	int_to_hex(number, count, hex_base);
}

void	pr_num(int number, int *count)
{
	char	temp;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
		(*count)++;
		pr_num(number, count);
	}
	else if (number < 10)
	{
		temp = number + '0';
		write(1, &temp, 1);
		(*count)++;
	}
	else
	{
		pr_num(number / 10, count);
		pr_num(number % 10, count);
	}
}

void	pr_unum(unsigned int number, int *count)
{
	char	temp;

	if (number < 10)
	{
		temp = number + '0';
		write(1, &temp, 1);
		(*count)++;
	}
	else
	{
		pr_unum(number / 10, count);
		pr_unum(number % 10, count);
	}
}
