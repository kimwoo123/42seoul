/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:11:25 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/16 13:41:31 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_striteri(char *s, void (*f)(unsigned int,
char *))
{
	size_t	s_len;
	size_t	index;

	s_len = strlen(s);
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
	return ;
}
