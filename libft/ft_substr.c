/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:58:12 by martorre          #+#    #+#             */
/*   Updated: 2024/04/08 18:01:38 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (i < len && start < ft_strlenz(s) && s[start + i])
		i++;
	new = malloc(i +1);
	if (!new)
	{
		ft_putstr_fd("cub3d: malloc failed\n", 2);
		exit(1);
	}
	while (j < i && start < ft_strlenz((char *)s))
	{
		new[j] = s[start + j];
		j++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main (void)
{
	char			*s;
	unsigned int	start = 3;
	size_t			len = 3;
	s = ft_substr("Tardes", start, len);
	printf("%s", s);
}*/
