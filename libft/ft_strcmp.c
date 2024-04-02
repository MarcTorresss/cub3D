/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:58:17 by martorre          #+#    #+#             */
/*   Updated: 2024/02/04 18:59:23 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i])
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s1[] = "hola";
	char	s2[] = "hslaa";
	int		i = 0;
	//i = strcmp(s1,s2);
	i = ft_strcmp(s1,s2);
	printf("S1 = %s\n",s1);
	printf("S2 = %s\n",s2);
	printf("Em torna STRCMP = %d\n",i);
}*/
