/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 19:19:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"

static void	draw_ceiling(t_scene scene, int x, int end)
{
	int	y;

	y = 0;
	while (y < end)
	{
		put_pixel(scene.screen, x, y, scene.ccolor);
		y++;
	}
}

static void	draw_floor(t_scene scene, int x, int start)
{
	int	y;

	y = scene.height - 1;
	while (y > start)
	{
		put_pixel(scene.screen, x, y, scene.fcolor);
		y--;
	}
}

static unsigned int	get_color_pixel(t_scene scene, t_ray ray, double h)
{
	double	w;

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
	int				size;
	int				start;
	int				end;
	unsigned int	color;

	start = scene.height * (h + 1) * 0.5f;
	end = scene.height * (1 - h) * 0.5f;
	size = start - end;
	if (start >= scene.height)
		start = scene.height - 1;
	if (end < 0)
		end = 0;
	draw_floor(scene, x, start);
	while (start >= end)
	{
		color = get_color_pixel(scene, ray, (double)(start - end) / size);
		put_pixel(scene.screen, x, start, color);
		start--;
	}
	draw_ceiling(scene, x, end);
}
