/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:41:35 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 20:55:06 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	create_vector3d(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	create_vector3d_arr(double arr[3])
{
	t_vec3	v;

	v.v[0] = arr[0];
	v.v[1] = arr[1];
	v.v[2] = arr[2];
	return (v);
}

t_vec3	create_vector3d_vec2d(t_vec2 v)
{
	t_vec3	_v;

	_v.x = v.x;
	_v.y = v.y;
	_v.z = 0;
	return (_v);
}
