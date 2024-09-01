/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:36:11 by wooseoki          #+#    #+#             */
/*   Updated: 2022/12/21 20:35:38 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	char	*str_ptr;

	str_ptr = str;
	while (*str_ptr)
	{
		if (*str_ptr == (char)c)
			return (str_ptr);
		str_ptr++;
	}
	if (*str_ptr == (char)c)
		return (str_ptr);
	return (0);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	index;
	size_t	str_len;
	char	*substr;

	str_len = ft_strlen(str);
	if (str_len <= start)
		return (ft_strjoin("", ""));
	if (str_len - start < len)
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	index = 0;
	while (str[start + index] && index < len)
	{
		substr[index] = str[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*result;
	char	*temp;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (0);
	temp = result;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (result);
}
