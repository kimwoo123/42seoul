/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:13:18 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 21:06:53 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*src_ptr;

	if (dst == src)
		return (dst);
	src_ptr = (char *)src;
	ptr = (char *)dst;
	while (n-- > 0)
		*ptr++ = *src_ptr++;
	return (dst);
}
