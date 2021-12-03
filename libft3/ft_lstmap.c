/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:04:11 by pleveque          #+#    #+#             */
/*   Updated: 2021/11/27 12:34:19 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlst)
			return (NULL);
		lst = lst->next;
		while (lst)
		{
			tmp = ft_lstnew(f(lst->content));
			if (!tmp)
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, tmp);
			lst = lst->next;
		}
		return (newlst);
	}
	return (NULL);
}
