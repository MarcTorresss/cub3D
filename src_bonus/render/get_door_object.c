/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:55:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 11:15:17 by junghwle         ###   ########.fr       */
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
