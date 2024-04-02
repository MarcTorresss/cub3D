/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:10 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 16:48:46 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new = malloc(sizeof(t_list));
	tmp = new;
	if (!new)
		return (NULL);
	while (lst != NULL)
	{
		new->content = f((lst)->content);
		if (lst->next == NULL)
			new->next = NULL;
		else
		{
			new->next = malloc(sizeof(t_list));
			if (!new->next)
				return (ft_lstclear(&tmp, del), NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}
