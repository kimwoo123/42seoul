/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:01:55 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/17 12:41:37 by wooseoki         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_index;
	size_t	src_len;

	src_len = strlen(src);
	if (!dstsize)
		return (src_len);
	dst_index = 0;
	while (dst[dst_index])
		dst_index++;
	if (dst_index >= dstsize)
		return (src_len + dstsize);
	index = 0;
	while (src[index] && index + dst_index + 1 < dstsize)
	{
		dst[dst_index + index] = src[index];
		index++;
	}
	dst[dst_index + index] = 0;
	return (dst_index + src_len);
}
