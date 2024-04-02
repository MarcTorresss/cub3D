/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:26:47 by martorre          #+#    #+#             */
/*   Updated: 2023/09/18 11:20:02 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/*
 #include <string.h>
int	main (void)
{
	char *src = "\0";
	char *d1 = strrchr(src, 'a');
	char *d2 = ft_strrchr(src, 'a');

	//printf("%s\n", d1);
	printf("%s\n", d2);
}*/
