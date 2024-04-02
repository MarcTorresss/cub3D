/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:09:57 by martorre          #+#    #+#             */
/*   Updated: 2024/02/14 17:19:46 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	num_ut(long *num, int *col_count, int *col_val)
{
	if (*num < 0)
	{
		(*col_count)++;
		(*num) *= -1;
	}
	while (*num / *col_val >= 10)
	{
		(*col_count)++;
		(*col_val) *= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		i;
	int		col_count;
	int		col_val;
	long	num;

	num = (long)n;
	col_count = 2;
	col_val = 1;
	i = 0;
	num_ut(&num, &col_count, &col_val);
	buffer = malloc(sizeof(char) * (col_count));
	if (!buffer)
		exit(1);
	if (n < 0)
		buffer[i++] = '-';
	while (i < col_count - 1)
	{
		buffer[i] = (num / col_val) % 10 + '0';
		col_val /= 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
