/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:34:20 by martorre          #+#    #+#             */
/*   Updated: 2023/09/18 11:43:40 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	i = 0;
	lendst = 0;
	lensrc = ft_strlen(src);
	while (dst[lendst] != '\0' && lendst < dstsize)
		lendst++;
	while (src[i] != '\0' && i < dstsize - lendst - 1 && lendst < dstsize)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	if (i > 0)
		dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
/*
#include <string.h>

int	main(void)
{
	char src[10] = "Buenas";
	char dst[15] = "Pep";
	int i = 0;

	//i = strlcat(dst, src, 6);
	i = ft_strlcat(dst, src, 1);
	printf("SRC = %s\n", src);
	printf("dst = %s\n", dst);
	printf("Return = %d\n", i);
}*/