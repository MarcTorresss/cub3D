/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:17:38 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double	length_vec2(t_vec2 v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y);
	return (length);
}

double	length_vec3(t_vec3 v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}
