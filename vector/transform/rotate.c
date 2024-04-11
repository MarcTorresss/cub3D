/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:09:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 19:23:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

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
