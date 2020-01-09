/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 10:54:46 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/22 11:39:39 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_del(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*next;
	void	(*d)(void *, size_t);

	d = ft_del;
	if (!lst || !f)
		return (NULL);
	new = f(lst);
	first = new;
	lst = lst->next;
	while (lst != NULL)
	{
		next = f(lst);
		if (!next)
		{
			ft_lstdel(&new, d);
			return (new);
		}
		new->next = next;
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
