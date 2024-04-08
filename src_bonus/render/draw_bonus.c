/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 14:05:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"
#include <math.h>
#include <mlx.h>

void	draw(t_scene scene)
{
	int		x;
	t_ray	ray;
	double	height;
	
	draw_minimap(scene, scene.player);
	x = 0;
	while (x < scene.width)
	{
		set_ray(&ray, scene.player, scene.width, x);
		ray.v_dist = scene.player.v_dist;
		if (hit(&ray, scene.map, scene.rows, scene.cols) && ray.perp_dist >= 0.0001)
		{
			height = scene.height / ray.perp_dist * BOX_UNIT;
			draw_field(scene, ray, x, height);
		}
		else
			draw_field(scene, ray, x, 0);
		x++;
	}
	mlx_put_image_to_window(scene.mlx, scene.win, scene.screen->img, 0, 0);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.mmap->img, \
		scene.width - 50 - scene.mmap->width, \
		scene.height - 50 - scene.mmap->height);
}
