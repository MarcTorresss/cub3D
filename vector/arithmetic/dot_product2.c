/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:47:26 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 12:52:54 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	dot_mat2_vec2(t_mat2 m1, t_vec2 v1)
{
	t_vec2	v;

	v.x = m1.arr[0] * v1.x + m1.arr[1] * v1.y;
	v.y = m1.arr[2] * v1.x + m1.arr[3] * v1.y;
	return (v);
}

t_vec3	dot_mat3_vec3(t_mat3 m1, t_vec3 v1)
{
	t_vec3	v;

	v.x = m1.arr[0] * v1.x + m1.arr[1] * v1.y + m1.arr[2] * v1.z;
	v.y = m1.arr[3] * v1.x + m1.arr[4] * v1.y + m1.arr[5] * v1.z;
	v.z = m1.arr[6] * v1.x + m1.arr[7] * v1.y + m1.arr[8] * v1.z;
	return (v);
}
