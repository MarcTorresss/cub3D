/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:07:54 by martorre          #+#    #+#             */
/*   Updated: 2023/09/14 13:10:31 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (src[i] != '\0')
	{
		len = ft_strlen(src);
		if (dstsize != 0)
		{
			while (src[i] != '\0' && i < (dstsize - 1))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	else
		dst[i] = '\0';
	return (len);
}

/*
int	main(void)
{
		unsigned int i = 0;
		char    s1[] = "Buenas Tardes";
		char    s2[] = "Malas Noches";

		//i=strlcpy(s2,s1,13);
		i=ft_strlcpy(s2,s1,0);
		printf("S1 = %s\n",s1);
		printf("S2 = %s\n",s2);
		printf("Lo que devuelve strlcpy: %d", i);
}*/