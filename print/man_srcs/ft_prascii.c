/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:24:26 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/05 10:48:42 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pr_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	pr_str(char	*str, int *count)
{
	int	str_len;

	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	str_len = 0;
	while (str[str_len])
		str_len++;
	write(1, str, str_len);
	*count += str_len;
}

void	num_to_hex(unsigned long num, char *hex_base, int *count)
{
	if (num < 16)
	{
		write(1, &hex_base[num], 1);
		(*count)++;
	}
	else
	{
		num_to_hex(num / 16, hex_base, count);
		num_to_hex(num % 16, hex_base, count);
	}
}

void	pr_ptr(void	*ptr, int *count)
{
	char	*hex_base;

	write(1, "0x", 2);
	*count += 2;
	hex_base = "0123456789abcdef";
	num_to_hex((unsigned long)ptr, hex_base, count);
}
