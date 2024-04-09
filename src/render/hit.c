/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:12:17 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include <math.h>

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

static void	record_hit(t_ray *ray, t_hit hit, int side)
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

int	perform_dda(t_hit h, t_ray *r)
{
	int	side;

	while (h.mapx >= 0 && h.mapx < h.rows && h.mapy >= 0 && h.mapy < h.cols)
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
		if (h.mapx >= 0 && h.mapx < h.rows && h.mapy >= 0 && h.mapy < h.cols \
			&& h.map[h.mapx][h.mapy] == '1')
		{
			record_hit(r, h, side);
			return (1);
		}
	}
	return (0);
}

int	hit(t_ray *ray, char **map, int rows, int cols)
{
	t_hit	hit;

	if (ray->from.x < 0 || ray->from.x >= rows || \
		ray->from.y < 0 || ray->from.y >= cols)
		return (0);
	hit.map = map;
	hit.mapx = (ray->from.x);
	hit.mapy = (ray->from.y);
	hit.rows = rows;
	hit.cols = cols;
	if (ray->dir.x == 0)
		hit.deltadist_x = 1e308;
	else
		hit.deltadist_x = fabs(1.0f / ray->dir.x);
	if (ray->dir.y == 0)
		hit.deltadist_y = 1e308;
	else
		hit.deltadist_y = fabs(1.0f / ray->dir.y);
	set_hit_step(&hit, ray);
	return (perform_dda(hit, ray));
}
