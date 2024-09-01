/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:47:26 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/14 09:04:23 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	char	*s_ptr;
	char	*ret;

	ret = 0;
	s_ptr = (char *)s;
	while (*s_ptr)
	{
		if (*s_ptr == (char)c)
			ret = s_ptr;
		s_ptr++;
	}
	if (*s_ptr == (char)c)
		ret = s_ptr;
	return (ret);
}
