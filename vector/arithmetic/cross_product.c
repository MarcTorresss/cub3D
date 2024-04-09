/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:25:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 13:31:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	cross_vec2(t_vec2 v1, t_vec2 v2)
{
	double	res;

	res = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.z;
	return (v);
}
