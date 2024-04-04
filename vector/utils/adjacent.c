/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:09:29 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_mat2	adjacent_mat2(t_mat2 m)
{
	t_mat2	adj;

	adj.m[0][0] = m.m[1][1];
	adj.m[0][1] = -m.m[0][1];
	adj.m[1][0] = -m.m[1][0];
	adj.m[1][1] = m.m[0][0];
	return (adj);
}

static t_mat2	cofactor_mat2(t_mat3 m, int idxi, int idxj)
{
	t_mat2	cofm;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i != idxi && j != idxj)
				cofm.arr[k++] = m.m[i][j];
			j++;
		}
		i++;
	}
	return (cofm);
}

t_mat3	adjacent_mat3(t_mat3 m)
{
	t_mat3	adj;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			adj.m[i][j] = determinant_mat2(cofactor_mat2(m, i, j));
			if ((i + j) % 2 == 1)
				adj.m[i][j] *= -1;
			j++;
		}
		i++;
	}
	return (adj);
}
