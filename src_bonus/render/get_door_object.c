/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:55:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:36:17 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "cub3D.h"

t_door	*get_door_object(t_scene scene, int i, int j)
{
	t_door	*door;

	door = scene.doors;
	while (door != NULL)
	{
		if (door->x == j && door->y == i)
			return (door);
		door = door->next;
	}
	return (NULL);
}

int	qtts_okei_bonus(t_parser parser)
{
	if (parser.elem.qtt.no != 1 || parser.elem.qtt.so != 1
		|| parser.elem.qtt.we != 1 || parser.elem.qtt.ea != 1
		|| parser.elem.qtt.f != 1 || parser.elem.qtt.c != 1
		|| parser.elem.qtt.is_zero != 0 || parser.elem.qtt.door != 1)
		return (1);
	return (0);
}

t_point	init_pos(void)
{
	t_point	pos;

	pos.x = -1;
	pos.y = 0;
	return (pos);
}
