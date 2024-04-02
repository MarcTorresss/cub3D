/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:18:19 by martorre          #+#    #+#             */
/*   Updated: 2023/09/13 12:28:43 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dstc;
	char	*srcc;

	i = 0;
	dstc = (char *)dst;
	srcc = (char *)src;
	if (!dstc && !srcc)
		return (0);
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dstc);
}
