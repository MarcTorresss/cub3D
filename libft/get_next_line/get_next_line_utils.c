/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:27:17 by martorre          #+#    #+#             */
/*   Updated: 2023/11/30 11:50:42 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*gtnl_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (free((char *)s1), NULL);
	lens1 = gtnl_strlen((char *)s1);
	lens2 = gtnl_strlen((char *)s2);
	new = malloc((lens1 + lens2) + 1);
	if (!new)
		return (free((char *)s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	new[i] = '\0';
	free((char *)s1);
	return (new);
}

char	*gtnl_strchr(const char *s, size_t c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	len = gtnl_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gtnl_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (i < len && start < gtnl_strlen(s) && s[start + i])
		i++;
	new = malloc(i + 1);
	if (!new)
		return (0);
	while (j < i && start < gtnl_strlen((char *)s))
	{
		new[j] = s[start + j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*gtnl_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(gtnl_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	gtnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
