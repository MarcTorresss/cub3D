/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:25:52 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 20:28:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	sum_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_vec3	sum_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_mat2	sum_mat2(t_mat2 m1, t_mat2 m2)
{
	t_mat2	m;
	int		i;

	i = 0;
	while (i < 4)
	{
		m.arr[i] = m1.arr[i] + m2.arr[i];
		i++;
	}
	return (m);
}

t_mat3	sum_mat3(t_mat3 m1, t_mat3 m2)
{
	t_mat3	m;
	int		i;

	i = 0;
	while (i < 9)
	{
		m.arr[i] = m1.arr[i] + m2.arr[i];
		i++;
	}
	return (m);
}
