/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_in_action.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:01 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 11:25:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"

static int	check_closing_door(t_door *door, t_ray *ray, double v)
{
	if (ray->w_dir == 'N' && (v < (int)ray->hpoint.y || \
								v > (int)ray->hpoint.y + 1 - door->timer))
		return (0);
	else if (ray->w_dir == 'S' && (v < (int)ray->hpoint.y + door->timer || \
								v > (int)ray->hpoint.y + 1))
		return (0);
	else if (ray->w_dir == 'E' && (v < (int)ray->hpoint.x || \
								v > (int)ray->hpoint.x + 1 - door->timer))
		return (0);
	else if (ray->w_dir == 'W' && (v < (int)ray->hpoint.x + door->timer || \
								v > (int)ray->hpoint.x + 1))
		return (0);
	return (1);
}

static int	check_opening_door(t_door *door, t_ray *ray, double v)
{
	if (ray->w_dir == 'N' && (v < (int)ray->hpoint.y || \
								v > (int)ray->hpoint.y + door->timer))
		return (0);
	else if (ray->w_dir == 'S' && (v < (int)ray->hpoint.y + 1 - door->timer || \
								v > (int)ray->hpoint.y + 1))
		return (0);
	else if (ray->w_dir == 'E' && (v < (int)ray->hpoint.x || \
								v > (int)ray->hpoint.x + door->timer))
		return (0);
	else if (ray->w_dir == 'W' && (v < (int)ray->hpoint.x + 1 - door->timer || \
								v > (int)ray->hpoint.x + 1))
		return (0);
	return (1);
}

int	check_door_in_action(t_scene scene, t_ray *ray, t_hit hit, double v)
{
	t_door	*door;

	door = get_door_object(scene, hit.mapx, hit.mapy);
	if (door == NULL)
		return (0);
	if (door->state == 'D')
		return (1);
	if (door->state == 'd' && check_closing_door(door, ray, v))
		return (1);
	else if (door->state == 'o' && check_opening_door(door, ray, v))
		return (1);
	return (0);
}
