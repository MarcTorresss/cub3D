/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:23:07 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:54 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	normalize_vec2(t_vec2 v)
{
	double	length;

	length = length_vec2(v);
	v.x /= length;
	v.y /= length;
	return (v);
}

t_vec3	normalize_vec3(t_vec3 v)
{
	double	length;

	length = length_vec3(v);
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}
