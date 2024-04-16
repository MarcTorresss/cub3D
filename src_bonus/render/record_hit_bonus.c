/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_hit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:47:22 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:47:35 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "scene.h"

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

static int	hit_door_horizontal(t_ray *ray, t_hit hit, t_scene scene)
{
	double	v;

	(void) scene;
	if (ray->w_dir == 'W')
		v = ray->hpoint.x - 0.5f * ray->dir.x / ray->dir.y;
	else
		v = ray->hpoint.x + 0.5f * ray->dir.x / ray->dir.y;
	if (v < (int)ray->hpoint.x || v > (int)ray->hpoint.x + 1)
		return (0);
	if (check_door_in_action(scene, ray, hit, v) == 0)
		return (0);
	ray->hpoint.x = v;
	if (ray->w_dir == 'W')
		ray->hpoint.y -= 0.5f;
	else
		ray->hpoint.y += 0.5f;
	ray->perp_dist = length_vec2(ray->p_dir) * distance_vec2(ray->hpoint,
			ray->from) / length_vec2(ray->dir);
	ray->door = get_door_object(scene, hit.mapx, hit.mapy);
	return (1);
}

static int	hit_door_vertical(t_ray *ray, t_hit hit, t_scene scene)
{
	double	v;
	
	if (ray->w_dir == 'N')
		v = ray->hpoint.y - 0.5f * ray->dir.y / ray->dir.x;
	else
		v = ray->hpoint.y + 0.5f * ray->dir.y / ray->dir.x;
	if (v < (int)ray->hpoint.y || v > (int)ray->hpoint.y + 1)
		return (0);
	if (check_door_in_action(scene, ray, hit, v) == 0)
		return (0);
	ray->hpoint.y = v;
	if (ray->w_dir == 'N')
		ray->hpoint.x -= 0.5f;
	else
		ray->hpoint.x += 0.5f;
	ray->perp_dist = length_vec2(ray->p_dir) * distance_vec2(ray->hpoint,
			ray->from) / length_vec2(ray->dir);
	ray->door = get_door_object(scene, hit.mapx, hit.mapy);
	return (1);
}

int	record_door_hit(t_ray *ray, t_hit hit, int side, t_scene scene)
{
	record_wall_hit(ray, hit, side);
	if (side == 1)
		return (hit_door_horizontal(ray, hit, scene));
	else
		return (hit_door_vertical(ray, hit, scene));
}
