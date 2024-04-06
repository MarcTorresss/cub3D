/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:09:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:10:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>
#define M_PI 3.14159265358979323846

t_vec2	rotate_vec2(t_vec2 p, double angle)
{
	double	theta;
	double	cs;
	double	sn;
	t_vec2	point;

	theta = angle / 360 * 2 * M_PI;
	cs = cos(theta);
	sn = sin(theta);
	point.x = p.x * cs - p.y * sn;
	point.y = p.x * sn + p.y * cs;
	return (point);
}