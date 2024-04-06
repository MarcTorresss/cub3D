/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 21:08:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "image.h"
#include <stdlib.h>

void	draw_full_map(t_img *full_map, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				draw_square(full_map, \
				create_vector2d(j * GRID_UNIT, i * GRID_UNIT), \
				create_vector2d((j + 1) * GRID_UNIT, (i + 1)  * GRID_UNIT), \
				WALL_COLOR);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

static void	copy_minimap(t_img *full_map, t_img *map, t_vec2 center)
{
	(void) full_map;
	(void) map;
	(void) center;
}

static void	draw_player_icon(t_img *map, t_vec2 pos, t_vec2 dir)
{
	t_vec2	v;
	t_vec2	vertices[3];

	dir = normalize_vec2(dir);
	v.x = (pos.x + dir.x * 2 / 3) * GRID_UNIT;
	v.y = (pos.y + dir.y * 2 / 3) * GRID_UNIT;
	vertices[0] = v;
	v = translate(v, create_vector2d(-pos.x, -pos.y));
	v = rotate_vec2(v, 120);
	vertices[1] = translate(v, pos);
	v = rotate_vec2(v, 120);
	vertices[2] = translate(v, pos);
	draw_triangle(map, vertices, PLAYER_COLOR);
}

void	draw_minimap(t_scene scene, t_ray ray)
{
	static int	full_map;

	if (!full_map)
		draw_full_map(scene.full_map, scene.map);
	full_map = 1;
	copy_minimap(scene.full_map, scene.mmap, ray.from);
	draw_player_icon(scene.mmap, create_vector2d(10, 10), ray.dir);
}