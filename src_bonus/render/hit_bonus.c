/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:12:17 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:59:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "hit.h"
#include <math.h>

static int	check_object(t_hit h, t_ray *r, int side, t_scene scene)
{
	if (h.map[h.mapx][h.mapy] == '1')
		return (record_wall_hit(r, h, side), 1);
	if (h.map[h.mapx][h.mapy] == 'D')
		return (record_door_hit(r, h, side, scene));
	return (0);
}

static int	perform_dda(t_hit h, t_ray *r, t_scene scene)
{
	int	side;

	while (1)
	{
		if (h.sidedist_x < h.sidedist_y)
		{
			h.sidedist_x += h.deltadist_x;
			h.mapx += h.stepx;
			side = 0;
		}
		else
		{
			h.sidedist_y += h.deltadist_y;
			h.mapy += h.stepy;
			side = 1;
		}
		if (h.mapx < 0 || h.mapx >= h.rows || h.mapy < 0 || h.mapy >= h.cols)
			return (0);
		else if (check_object(h, r, side, scene))
			return (1);
	}
	return (0);
}

static void	set_hit_step(t_hit *hit, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		hit->stepx = -1;
		hit->sidedist_x = (ray->from.x - (double)hit->mapx) * hit->deltadist_x;
	}
	else
	{
		hit->stepx = 1;
		hit->sidedist_x = ((double)hit->mapx + 1.0f - ray->from.x) * \
							hit->deltadist_x;
	}
	if (ray->dir.y < 0)
	{
		hit->stepy = -1;
		hit->sidedist_y = (ray->from.y - (double)hit->mapy) * hit->deltadist_y;
	}
	else
	{
		hit->stepy = 1;
		hit->sidedist_y = ((double)hit->mapy + 1.0f - ray->from.y) * \
							hit->deltadist_y;
	}
}

int	hit(t_ray *ray, t_scene scene)
{
	t_hit	hit;

	if (ray->from.x < 0 || ray->from.x >= scene.rows || \
		ray->from.y < 0 || ray->from.y >= scene.cols)
		return (0);
	hit.map = scene.map;
	hit.mapx = (ray->from.x);
	hit.mapy = (ray->from.y);
	hit.rows = scene.rows;
	hit.cols = scene.cols;
	if (ray->dir.x == 0)
		hit.deltadist_x = 1e308;
	else
		hit.deltadist_x = fabs(1.0f / ray->dir.x);
	if (ray->dir.y == 0)
		hit.deltadist_y = 1e308;
	else
		hit.deltadist_y = fabs(1.0f / ray->dir.y);
	set_hit_step(&hit, ray);
	return (perform_dda(hit, ray, scene));
}
