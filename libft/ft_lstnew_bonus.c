/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:16:18 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 16:48:53 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(node);
		return (0);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

/*int main ()
{
	t_list	*node;
	//t_list	*node2;
	char i[2] = "5";
	char j[3] = "10";

	node = malloc(sizeof(t_list));
	//node2 = malloc(sizeof(t_list));
	node->content = i;
	node->next = ft_lstnew(j);
	//node2->content = j;
	printf("%s\n", node->content);
	node = node->next;
	printf("%s\n", node->content);
	return (1);
}*/