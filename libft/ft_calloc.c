/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:20:58 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/17 12:21:03 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_byte;
	size_t	index;
	char	*temp;

	if (!count)
		total_byte = 0;
	else
	{
		total_byte = count * size;
		if (total_byte / count != size)
			return (0);
	}
	temp = (char *)malloc(total_byte);
	if (!temp)
		return (0);
	index = 0;
	while (index < total_byte)
	{
		temp[index] = 0;
		index++;
	}
	return ((void *)temp);
}
