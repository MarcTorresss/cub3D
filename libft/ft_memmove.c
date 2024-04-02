/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:57:09 by martorre          #+#    #+#             */
/*   Updated: 2023/09/21 11:50:15 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstc;
	char	*srcc;
	size_t	i;

	dstc = (char *)dst;
	srcc = (char *)src;
	i = -1;
	if (!dstc && !srcc)
		return (0);
	if (src < dst)
	{
		while (len)
		{
			dstc[len - 1] = srcc[len - 1];
			len--;
		}
	}
	else
	{
		while (len > ++i)
			dstc[i] = srcc[i];
	}
	return (dst);
}
/*int main() {
    char buffer[] = "Hello, World!";
    printf("Resultado: %lu\n", ft_strlen(buffer));
    ft_memmove(buffer + 7, buffer + 7 + 3, ft_strlen(buffer) - 7 + 1);
    printf("Resultado: %s\n", buffer);
    return 0;
}*/