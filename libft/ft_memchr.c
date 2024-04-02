/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:42:39 by martorre          #+#    #+#             */
/*   Updated: 2023/09/14 11:16:08 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*sc;

	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		if (sc[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
