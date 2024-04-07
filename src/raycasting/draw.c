/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 19:08:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"
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
		hit(&ray, scene.map);
		height = BOX_UNIT / ray.perp_dist;
		draw_field(scene, ray, x, height);
		x++;
	}
	draw_minimap(scene, ray, scene.player);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.screen->img, 0, 0);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.mmap->img, \
		scene.width - 50 - scene.mmap->width, \
		scene.height - 50 - scene.mmap->height);
}
