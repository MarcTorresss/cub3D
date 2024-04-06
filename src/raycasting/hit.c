/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:12:17 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:55:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include <math.h>

static void	set_hit_step(t_hit *hit, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		hit->stepX = -1;
		hit->sideDistX = (ray->from.x - (double)hit->mapx) * hit->deltaDistX;
	}
	else
	{
		hit->stepX = 1;
		hit->sideDistX = ((double)hit->mapx + 1.0f - ray->from.x) * \
							hit->deltaDistX;
	}
	if (ray->dir.y < 0)
	{
		hit->stepY = -1;
		hit->sideDistY = (ray->from.y - (double)hit->mapy) * hit->deltaDistY;
	}
	else
	{
		hit->stepY = 1;
		hit->sideDistY = ((double)hit->mapy + 1.0f - ray->from.y) * \
							hit->deltaDistY;
	}
}

static void	record_hit(t_ray *ray, t_hit hit, int side)
{
	double	ratio;

	if (side == 0)
	{
		if (hit.stepX == -1)
			ray->w_dir = 'N';
		else
			ray->w_dir = 'S';
		ray->perp_dist = hit.sideDistX - hit.deltaDistX;
	}
	else
	{
		if (hit.stepY == -1)
			ray->w_dir = 'W';
		else
			ray->w_dir = 'E';
		ray->perp_dist = hit.sideDistY - hit.deltaDistY;
	}
	ratio = ray->perp_dist / length_vec2(ray->p_dir);
	ray->hpoint.x = ray->from.x + ray->dir.x * ratio;
	ray->hpoint.y = ray->from.y + ray->dir.y * ratio;
}

static void	perform_dda(t_hit h, t_ray *r)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (h.sideDistX < h.sideDistY)
		{
			h.sideDistX += h.deltaDistX;
			h.mapx += h.stepX;
			side = 0;
		}
		else
		{
			h.sideDistY += h.deltaDistY;
			h.mapy += h.stepY;
			side = 1;
		}
		if (h.map[h.mapx][h.mapy] == '1')
		{
			hit = 1;
			record_hit(r, h, side);
		}
	}
}

void	hit(t_ray *ray, char **map)
{
	t_hit	hit;
	
	hit.map = map;
	hit.mapx = (ray->from.x);
	hit.mapy = (ray->from.y);
	if (ray->dir.x == 0)
		hit.deltaDistX = 1e308;
	else
		hit.deltaDistX = fabs(1.0f / ray->dir.x);
	if (ray->dir.y == 0)
		hit.deltaDistY = 1e308;
	else
		hit.deltaDistY = fabs(1.0f / ray->dir.y);
	
	set_hit_step(&hit, ray);
	perform_dda(hit, ray);
}
