/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 16:38:46 by martorre         ###   ########.fr       */
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
}
