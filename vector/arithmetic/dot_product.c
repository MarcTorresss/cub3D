/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:49:32 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:16:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_vec2(t_vec2 v1, t_vec2 v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y;
	return (res);
}

double	dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_mat2	dot_mat2(t_mat2 m1, t_mat2 m2)
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
			m.m[i][j] = m1.m[i][0] * m2.m[0][j] + \
						m1.m[i][1] * m2.m[1][j];
			j++;
		}
		i++;
	}
	return (m);
}

t_mat3	dot_mat3(t_mat3 m1, t_mat3 m2)
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
			m.m[i][j] = m1.m[i][0] * m2.m[0][j] + \
						m1.m[i][1] * m2.m[1][j] + \
						m1.m[i][2] * m2.m[2][j];
			j++;
		}
		i++;
	}
	return (m);
}
