/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:57:09 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_mat2	transpose_mat2(t_mat2 m1)
{
	t_mat2	m;
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			m.m[i][j] = m1.m[j][i];
			j++;
		}
		i++;
	}
	return (m);
}

t_mat3	transpose_mat3(t_mat3 m1)
{
	t_mat3	m;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m.m[i][j] = m1.m[j][i];
			j++;
		}
		i++;
	}
	return (m);
}
