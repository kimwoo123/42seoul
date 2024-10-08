/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:16:19 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/05 11:22:58 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_bonus.h"

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		total_len;

	va_start(ap, string);
	total_len = print_string(ap, string);
	va_end(ap);
	if (total_len < 0)
		total_len = -1;
	return (total_len);
}
