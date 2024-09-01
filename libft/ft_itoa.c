/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:35:46 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/15 14:37:53 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	is_neg(long number)
{
	if (number < 0)
		return (1);
	return (0);
}

static size_t	count_len(long number)
{
	size_t	count;

	count = 0;
	while (number)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*convert_str(char *str, long number, int neg, int n_len)
{
	int	index;

	str[n_len + neg] = '\0';
	index = n_len + neg - 1;
	while (number)
	{
		str[index--] = number % 10 + '0';
		number /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	temp;
	int		n_len;
	int		neg;

	temp = n;
	neg = is_neg(temp);
	if (neg)
		temp *= -1;
	n_len = count_len(temp);
	if (!n_len)
		return (ft_strdup("0"));
	result = (char *)malloc(n_len + neg + 1);
	if (!result)
		return (0);
	convert_str(result, temp, neg, n_len);
	return (result);
}
