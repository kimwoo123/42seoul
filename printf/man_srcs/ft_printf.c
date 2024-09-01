/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:19:00 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/05 11:37:08 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_format(va_list ap, char format, int *count)
{
	if (format == 'c')
		pr_char(va_arg(ap, int), count);
	else if (format == 's')
		pr_str(va_arg(ap, char *), count);
	else if (format == 'p')
		pr_ptr(va_arg(ap, void *), count);
	else if (format == 'd' || format == 'i')
		pr_num(va_arg(ap, int), count);
	else if (format == 'u')
		pr_unum(va_arg(ap, unsigned int), count);
	else if (format == 'x' || format == 'X')
		pr_hex(va_arg(ap, unsigned int), count, format);
	else if (format == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	return (0);
}

void	print_string(va_list ap, const char *string, int *count)
{
	int	flag;

	flag = 0;
	while (*string)
	{
		if (flag)
		{
			convert_format(ap, *string, count);
			flag = 0;
		}
		else if (*string == '%')
			flag = 1;
		else
		{
			write(1, string, 1);
			(*count)++;
		}
		string++;
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	va_start(ap, string);
	print_string(ap, string, &count);
	va_end(ap);
	if (count < 0)
		count = -1;
	return (count);
}
