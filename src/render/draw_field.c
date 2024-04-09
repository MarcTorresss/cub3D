/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 16:48:26 by martorre         ###   ########.fr       */
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

static t_uint	get_color_pixel(t_scene scene, t_ray ray, double h)
{
	double	w;

	h = 1 - h;
	if (ray.w_dir == 'N')
	{
		w = ray.hpoint.y - (int)ray.hpoint.y;
		return (get_texture_color(scene.n_wall, w, h));
	}
	else if (ray.w_dir == 'E')
	{
		w = ray.hpoint.x - (int)ray.hpoint.x;
		return (get_texture_color(scene.e_wall, w, h));
	}
	else if (ray.w_dir == 'S')
	{
		w = 1 - (ray.hpoint.y - (int)ray.hpoint.y);
		return (get_texture_color(scene.s_wall, w, h));
	}
	else
	{
		w = 1 - (ray.hpoint.x - (int)ray.hpoint.x);
		return (get_texture_color(scene.w_wall, w, h));
	}
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
	while (start <= end && start < scene.height&& size > 0)
	{
		color = get_color_pixel(scene, ray, (double)(end - start) / size);
		put_pixel(scene.screen, x, start, color);
		start++;
	}
	draw_floor(scene, x, end);
}
