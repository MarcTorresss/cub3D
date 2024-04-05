/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 21:08:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"

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

	(void) scene;
	(void) h;
	(void) w;
	if (ray.w_dir == 'N')
	{
		w = ray.hpoint.y - (int)ray.hpoint.y;
		//get_texture_color(scene.Nwall, w, h);
		return (0x00FF0000);
	}
	else if (ray.w_dir == 'E')
	{
		w = ray.hpoint.x - (int)ray.hpoint.x;
		//get_texture_color(scene.Ewall, w, h);
		return (0x0000FF00);
	}
	else if (ray.w_dir == 'S')
	{
		w = 1 - (ray.hpoint.y - (int)ray.hpoint.y);
		//get_texture_color(scene.Swall, w, h);
		return (0x000000FF);
	}
	else
	{
		w = 1 - (ray.hpoint.x - (int)ray.hpoint.x);
		//get_texture_color(scene.Wwall, w, h);
		return (0x00FFFF00);
	}
}

static void	draw_line(t_scene scene, t_ray ray, int x, double h)
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
		color = get_color_pixel(scene, ray, start / size);
		put_pixel(scene.screen, x, start, color);
		start--;
	}
	draw_ceiling(scene, x, end);
	(void)draw_floor;
	(void)draw_ceiling;
	(void)color;
	(void)x;
}

#include <stdio.h>

void	draw(t_scene scene)
{
	int		x;
	t_ray	ray;
	double	height;

	x = 0;
	while (x < scene.width)
	{
		set_ray(&ray, scene.player, scene.width, x);
		hit(&ray, scene.map);
		height = BOX_UNIT / ray.perp_dist;
		draw_line(scene, ray, x, height);
		x++;
	}
	mlx_put_image_to_window(scene.mlx, scene.win, scene.screen->img, 0, 0);
}
