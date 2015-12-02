/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:45:35 by mfortin           #+#    #+#             */
/*   Updated: 2015/11/23 21:01:16 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;

	if (lst != NULL && f != NULL)
	{
		newlist = f(lst);
		if (newlist != NULL && lst->next != NULL)
			newlist->next = ft_lstmap(lst->next, f);
		return (newlist);
	}
	return (NULL);
}
