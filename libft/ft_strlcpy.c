/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:31:57 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 18:43:37 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	index;

	src_len = strlen(src);
	index = 0;
	while (index < src_len && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = 0;
	return (src_len);
}
