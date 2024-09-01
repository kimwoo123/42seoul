/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:46:51 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 09:19:08 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	index;

	if (dst == src)
		return (dst);
	src_ptr = (char *)src;
	dst_ptr = (char *)dst;
	index = 0;
	if (dst < src)
	{
		while (index < len)
		{
			dst_ptr[index] = src_ptr[index];
			index++;
		}
	}
	else
	{
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	}
	return (dst);
}
