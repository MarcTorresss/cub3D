/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:20:22 by martorre          #+#    #+#             */
/*   Updated: 2023/09/18 16:45:55 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countain(char *set, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			r = 1;
		i++;
	}
	if (r == 1)
		return (1);
	return (0);
}

void	trim_first(char *s1, char *set, int *start)
{
	int	out;
	int	i;

	out = 1;
	i = 0;
	while (out == 1)
	{
		out = countain(set, s1[i]);
		if (out == 1)
			i++;
	}
	(*start) = i;
}

void	trim_last(char *s1, char *set, int *end)
{
	int	j;
	int	out;

	j = ft_strlen(s1);
	out = 1;
	while (out == 1)
	{
		out = countain(set, s1[j - 1]);
		if (out == 1)
			j--;
	}
	(*end) = j;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		end;
	char	*new;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (s1[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	trim_first((char *)s1, (char *)set, &start);
	trim_last((char *)s1, (char *)set, &end);
	if (start > end)
		return (ft_strdup(""));
	len = end - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (free(new), NULL);
	while (start < end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}

/*int	main(void)
{
	char	*s1 = "1211zzzz2zb  bh111111   111111112la z1zzzzzzzz";
	char	*set = "z12";
	int		start = 0;
	int		end = 0;
	//start = ft_strtrim(result, "1");
	trim_first((char *)s1, (char *)set, &start);
	trim_last((char *)s1, (char *)set, &end);
	while (start < end)
	{
		printf("%c", s1[start]);
		start++;
	}
}*/
