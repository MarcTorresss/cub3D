/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:04:16 by martorre          #+#    #+#             */
/*   Updated: 2023/09/12 19:01:47 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	c[] = "holAA1AA";
	int	i;
	i = ft_isprint(c);
	printf("Nos ha devuelto: %d",i);
}*/