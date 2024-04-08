/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:44:22 by martorre          #+#    #+#             */
/*   Updated: 2024/04/08 16:39:04 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	if (!s1)
		return (NULL);
	i = 0;
	dup = malloc(ft_strlen(s1) +1);
	if (!dup)
	{
		ft_putstr_fd("cub3d: malloc failed\n", 2);
		exit(1);
	}
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
