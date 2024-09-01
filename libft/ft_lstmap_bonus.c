/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:32:34 by wooseoki          #+#    #+#             */
/*   Updated: 2022/11/17 12:20:02 by wooseoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*lstnew(void *content, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*temp;

	temp = f(content);
	if (temp)
	{
		result = ft_lstnew(temp);
		if (!result)
		{
			del(temp);
			result = 0;
		}
		return (result);
	}
	else
		return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*head;

	head = 0;
	while (lst)
	{
		node = lstnew(lst->content, f, del);
		if (!node)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, node);
		node = node->next;
		lst = lst->next;
	}
	return (head);
}
