/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:09:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:10:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_mat2	create_matrix2d_empty(void)
{
	t_mat2	m;
	int		i;

	i = 0;
	while (i < 4)
		m.arr[i++] = 0;
	return (m);
}

t_mat2	create_matrix2d_identity(void)
{
	t_mat2	m;
	int		i;

	i = 0;
	while (i < 4)
		m.arr[i++] = 0;
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	return (m);
}

t_mat2	create_matrix2d_vec3d(t_vec3 v1, t_vec3 v2)
{
	t_mat2	m;

	m.v[0] = create_vector2d_vec3d(v1);
	m.v[1] = create_vector2d_vec3d(v2);
	return (m);
}

t_mat2	create_matrix2d_vec(t_vec2 v1, t_vec2 v2)
{
	t_mat2	m;

	m.v[0] = v1;
	m.v[1] = v2;
	return (m);
}

t_mat2	create_matrix2d_arr(double arr1[2], double arr2[2])
{
	t_mat2	m;

	m.m[0][0] = arr1[0];
	m.m[0][1] = arr1[1];
	m.m[1][0] = arr2[0];
	m.m[1][1] = arr2[1];
	return (m);
}
