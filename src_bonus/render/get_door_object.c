/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:55:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:56:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_door	*get_door_object(t_scene scene, int x, int y)
{
	t_door	*door;

	while (door != NULL)
	{
		if (door->x == x && door->y == y)
			return (door);
		door = door->next;
	}
	return (NULL);
}