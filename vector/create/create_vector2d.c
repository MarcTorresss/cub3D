/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:08:33 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 20:55:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	create_vector2d(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	create_vector2d_arr(double arr[2])
{
	t_vec2	v;

	v.v[0] = arr[0];
	v.v[1] = arr[1];
	return (v);
}

t_vec2	create_vector2d_vec3d(t_vec3 v)
{
	t_vec2	_v;

	_v.x = v.x;
	_v.y = v.y;
	return (_v);
}
