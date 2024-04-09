/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_hit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:22 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 22:01:11 by junghwle         ###   ########.fr       */
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

int	record_door_hit(t_ray *ray, t_hit hit, int side)
{
	(void) ray;
	(void) hit;
	(void) side;
	return (0);
}