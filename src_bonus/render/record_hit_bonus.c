/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_hit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:22 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 22:42:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

void	record_wall_hit(t_ray *ray, t_hit hit, int side)
{
	double	ratio;

	if (side == 0)
	{
		if (hit.stepx == -1)
			ray->w_dir = 'N';
		else
			ray->w_dir = 'S';
		ray->perp_dist = hit.sidedist_x - hit.deltadist_x;
	}
	else
	{
		if (hit.stepy == -1)
			ray->w_dir = 'W';
		else
			ray->w_dir = 'E';
		ray->perp_dist = hit.sidedist_y - hit.deltadist_y;
	}
	ratio = ray->perp_dist / length_vec2(ray->p_dir);
	ray->hpoint.x = ray->from.x + ray->dir.x * ratio;
	ray->hpoint.y = ray->from.y + ray->dir.y * ratio;
}

#include <stdio.h>

int	hit_door(t_hit hit_, t_ray *ray, int side)
{
	record_wall_hit(ray, hit_, side);
	double	m, n, v;
	m = ray->dir.x / ray->dir.y;
	n = ray->hpoint.x - ray->hpoint.y * m;
	v = (ray->hpoint.y + 0.5f) * m + n;
	if (v < (int)ray->hpoint.x || v > (int)ray->hpoint.x + 1)
		return (0);
	ray->hpoint.x = v;
	ray->hpoint.y += 0.5f;
	ray->perp_dist = length_vec2(ray->p_dir) * distance_vec2(ray->hpoint, ray->from) / length_vec2(ray->dir);
	printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", ray->dir.x, ray->dir.y, ray->hpoint.x, ray->hpoint.y, m, n, v);
	return (1);
}

int	record_door_hit(t_ray *ray, t_hit hit, int side)
{
	return (hit_door(hit, ray, side));
}