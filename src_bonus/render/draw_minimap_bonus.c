/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 20:38:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "image.h"
#include "libft.h"
#include <stdlib.h>

void	draw_full_map(t_img *full_map, char **map)
{
	int	i;
	int	j;
	int	pad;

	pad = MMAP_SIZE * GRID_UNIT / 2;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1')
				draw_square(full_map, \
				create_vector2d(j * GRID_UNIT + pad, i * GRID_UNIT + pad), \
				create_vector2d((j + 1) * GRID_UNIT + pad, \
								(i + 1) * GRID_UNIT + pad), \
				WALL_COLOR);
			j++;
		}
		i++;
	}
}

static void	copy_minimap(t_img *full_map, t_img *map, t_vec2 center)
{
	t_vec2	pmin;
	t_vec2	pmax;

	pmin.x = center.y * GRID_UNIT;
	pmin.y = center.x * GRID_UNIT;
	pmax.x = ft_min(pmin.x + MMAP_SIZE * GRID_UNIT, full_map->width);
	pmax.y = ft_min(pmin.y + MMAP_SIZE * GRID_UNIT, full_map->height);
	copy_image(map, full_map, pmin, pmax);
}

static void	draw_player_icon(t_img *map, t_vec2 dir)
{
	t_vec2	center;
	t_vec2	v;
	t_vec2	triangle[2][3];

	center = create_vector2d(MMAP_SIZE * GRID_UNIT / 2, \
								MMAP_SIZE * GRID_UNIT / 2);
	v = scalar_vec2(normalize_vec2(create_vector2d(dir.y, dir.x)), \
					GRID_UNIT * 0.5);
	triangle[0][0] = translate_vec2(v, center);
	triangle[0][1] = translate_vec2(translate_vec2(rotate_vec2(v, 120), \
									scalar_vec2(v, -0.5)), center);
	triangle[0][2] = translate_vec2(scalar_vec2(v, -0.5), center);
	triangle[1][0] = triangle[0][0];
	triangle[1][1] = translate_vec2(translate_vec2(rotate_vec2(v, 240), \
									scalar_vec2(v, -0.5)), center);
	triangle[1][2] = triangle[0][2];
	draw_triangle(map, triangle[0], PLAYER_COLOR);
	draw_triangle(map, triangle[1], PLAYER_COLOR);
}

void	draw_minimap(t_scene scene, t_player player)
{
	static int	full_map;

	if (!full_map)
	{
		draw_full_map(scene.full_map, scene.map);
		full_map = 1;
	}
	copy_minimap(scene.full_map, scene.mmap, player.pos);
	draw_player_icon(scene.mmap, player.dir);
}
