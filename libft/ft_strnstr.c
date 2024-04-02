/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:33:33 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 12:34:15 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0' && i < len)
	{
		if (needle[j] != '\0')
		{
			if (needle[j] == haystack[i])
				j++;
			else
			{
				i = i - j;
				j = 0;
			}
		}
		else
			return ((char *)&haystack[i - j]);
	}
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	return (NULL);
}

/*int	main(void)
{
	char str[] = "hola.barrr";
	char find[] = ".bar";
	char *re;
	re = ft_strnstr(str, find, ft_strlen(str));
	//re = strnstr(str,find, 2);
	printf("STR = %s\n", str);
	printf("FIND = %s\n", find);
	printf("Return = %s", re);
}*/