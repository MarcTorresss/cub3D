/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:52:45 by martorre          #+#    #+#             */
/*   Updated: 2024/03/07 11:14:30 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
		char			s1[] = "\200";
		char			s2[] = "\0";
		unsigned int	i = 0;
		unsigned int	n = 4;
		i = strncmp(s1,s2,n);
		//i = ft_strncmp(s1,s2,n);
		printf("S1 = %s\n",s1);
		printf("S2 = %s\n",s2);
		printf("Em torna STRCMP = %d\n",i);
}*/