/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:17:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/04 17:43:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "math.h"

double	distance_vec2(t_vec2 p1, t_vec2 p2)
{
	double	dist;
	t_vec2	v;

	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	dist = sqrt(v.x * v.x + v.y * v.y);
	return (dist);
}

double	distance_vec3(t_vec3 p1, t_vec3 p2)
{
	double	dist;
	t_vec3	v;

	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	v.z = p1.z - p2.z;
	dist = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (dist);
}
