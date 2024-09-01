/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:27:47 by wooseoki          #+#    #+#             */
/*   Updated: 2023/05/24 15:10:16 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dst;
	char	*ret;

	s1_len = ft_strlen(s1);
	dst = (char *)malloc(s1_len + 1);
	if (!dst)
		return (0);
	ret = dst;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (ret);
}

static size_t	count_len(t_time number)
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

static char	*convert_str(char *str, t_time number, int num_len)
{
	int	index;

	str[num_len] = '\0';
	index = num_len - 1;
	while (number)
	{
		str[index--] = number % 10 + '0';
		number /= 10;
	}
	return (str);
}

char	*ft_itoa(t_time number)
{
	char	*result;
	int		num_len;

	num_len = count_len(number);
	if (num_len == 0)
		return (ft_strdup("0"));
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (0);
	convert_str(result, number, num_len);
	return (result);
}
