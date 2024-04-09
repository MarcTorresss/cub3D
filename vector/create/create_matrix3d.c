/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:58:05 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:10:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_mat3	create_matrix3d_empty(void)
{
	t_mat3	m;
	int		i;

	i = 0;
	while (i < 9)
		m.arr[i++] = 0;
	return (m);
}

t_mat3	create_matrix3d_identity(void)
{
	t_mat3	m;
	int		i;

	i = 0;
	while (i < 9)
		m.arr[i++] = 0;
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	return (m);
}

t_mat3	create_matrix3d_vec2d(t_vec2 v1, t_vec2 v2, t_vec2 v3)
{
	t_mat3	m;

	m.v[0] = create_vector3d_vec2d(v1);
	m.v[1] = create_vector3d_vec2d(v2);
	m.v[2] = create_vector3d_vec2d(v3);
	return (m);
}

t_mat3	create_matrix3d_vec(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_mat3	m;

	m.v[0] = v1;
	m.v[1] = v2;
	m.v[2] = v3;
	return (m);
}

t_mat3	create_matrix3d_arr(double arr1[3], double arr2[3], double arr3[3])
{
	t_mat3	m;
	int		i;

	i = 0;
	while (i < 3)
	{
		m.m[0][i] = arr1[i];
		m.m[1][i] = arr2[i];
		m.m[2][i] = arr3[i];
		i++;
	}
	return (m);
}
