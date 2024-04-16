/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fullmap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:31:31 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 16:39:39 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "scene.h"

static void	draw_element(t_img *full_map, int x, int y, t_uint color)
{
	int	pad;

	pad = MMAP_SIZE * GRID_UNIT / 2;
	draw_square(full_map, create_vector2d(y * GRID_UNIT + pad, x * GRID_UNIT
			+ pad), create_vector2d((y + 1) * GRID_UNIT + pad, (x + 1)
			* GRID_UNIT + pad), color);
}

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
				draw_element(full_map, i, j, WALL_COLOR);
			else if (map[i][j] == 'D')
				draw_element(full_map, i, j, CLOSED_DOOR_COLOR);
			else if (map[i][j] == 'O')
				draw_element(full_map, i, j, OPENED_DOOR_COLOR);
			j++;
		}
		i++;
	}
}
