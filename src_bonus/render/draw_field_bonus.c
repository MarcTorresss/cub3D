/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:15:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"

static void	draw_ceiling(t_scene scene, int x, int end)
{
	int	y;

	y = 0;
	while (y < end && y < scene.height)
	{
		put_pixel(scene.screen, x, y, scene.ccolor);
		y++;
	}
}

static void	draw_floor(t_scene scene, int x, int start)
{
	int	y;

	y = scene.height - 1;
	while (y > start && y >= 0)
	{
		put_pixel(scene.screen, x, y, scene.fcolor);
		y--;
	}
}

static t_img	*get_wall_img(t_scene scene, t_ray ray)
{
	if (ray.door != NULL)
		return (scene.door);
	else if (ray.w_dir == 'N')
		return (scene.n_wall);
	else if (ray.w_dir == 'E')
		return (scene.e_wall);
	else if (ray.w_dir == 'S')
		return (scene.s_wall);
	else
		return (scene.w_wall);
}

static t_uint	get_color_pixel(t_scene scene, t_ray ray, double h)
{
	double	w;
	t_img	*img;

	h = 1 - h;
	if (ray.w_dir == 'N')
		w = ray.hpoint.y - (int)ray.hpoint.y;
	else if (ray.w_dir == 'E')
		w = ray.hpoint.x - (int)ray.hpoint.x;
	else if (ray.w_dir == 'S')
		w = 1 - (ray.hpoint.y - (int)ray.hpoint.y);
	else
		w = 1 - (ray.hpoint.x - (int)ray.hpoint.x);
	img = get_wall_img(scene, ray);
	if (ray.door != NULL && ray.door->state == 'o')
		w += 1 - ray.door->timer;
	else if (ray.door != NULL && ray.door->state == 'd')
		w += ray.door->timer;
	return (get_texture_color(img, w, h));
}

void	draw_field(t_scene scene, t_ray ray, int x, double h)
{
	int		size;
	int		start;
	int		end;
	t_uint	color;

	start = (scene.height - h) * 0.5 + ray.v_dist;
	end = (scene.height + h) * 0.5f + ray.v_dist;
	size = end - start;
	if (start < 0)
		start = 0;
	if (end < 0)
		end = 0;
	draw_ceiling(scene, x, start);
	while (start <= end && start < scene.height && size > 0)
	{
		color = get_color_pixel(scene, ray, (double)(end - start) / size);
		put_pixel(scene.screen, x, start, color);
		start++;
	}
	draw_floor(scene, x, end);
}
