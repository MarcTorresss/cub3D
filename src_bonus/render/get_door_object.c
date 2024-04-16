/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:55:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:22:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

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