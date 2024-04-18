/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:17:30 by martorre          #+#    #+#             */
/*   Updated: 2024/04/18 12:46:41 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cont_words(char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			cont++;
		else if ((i != 0) && (s[i - 1] == c && s[i] != c))
			cont++;
		i++;
	}
	return (cont);
}

int	ft_delimiter(char *s, int pos, char c)
{
	while (s[pos] == c)
	{
		pos++;
	}
	return (pos);
}

int	cont_letter(char *s, int pos, char c)
{
	int	cont;

	cont = 0;
	pos = ft_delimiter(s, pos, c);
	while (s[pos] != '\0' && s[pos] != c)
	{
		cont++;
		pos++;
	}
	return (cont);
}

char	**ft_free_mat(char **mat, int i)
{
	int		j;

	j = 0;
	while (i > j)
	{
		free(mat[j]);
		j++;
	}
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		pos;
	char	**mat;
	int		words;
	int		j;

	i = -1;
	pos = 0;
	words = cont_words((char *)s, c);
	mat = malloc(sizeof(char *) * (words + 1));
	if (!mat)
		return (0);
	while (++i < words)
	{
		j = 0;
		mat[i] = malloc(sizeof(char) * (cont_letter((char *)s, pos, c) + 1));
		if (!mat[i])
			return (ft_free_mat(mat, i));
		pos = ft_delimiter((char *)s, pos, c);
		while (s[pos] != c && s[pos] != '\0')
			mat[i][j++] = s[pos++];
		mat[i][j] = '\0';
	}
	mat[i] = NULL;
	return (mat);
}
/*int	main(void)
{
	int		i;
	char	**mat;

	i = 0;
	mat = ft_split("      split       this for   me  !       ", ' ');
	while (mat[i])
	{
		printf("%i --> %s\n", i, mat[i]);
		i++;
	}
}*/