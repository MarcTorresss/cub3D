/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:33:56 by martorre          #+#    #+#             */
/*   Updated: 2024/04/16 17:46:23 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_doors(char **map, int x, int y)
{
	if (map[y][x] == 'D' || map[y][x] == 'O')
	{
		if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
			return (0);
		if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
			return (0);
		return (1);
	}
	return (0);
}

t_door	*is_door(int x, int y, char state)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (!door)
		return (NULL);
	door->x = x;
	door->y = y;
	door->state = state;
	door->timer = 0;
	door->next = NULL;
	return (door);
}

t_door	*ft_last_door(t_door *door)
{
	t_door	*last;

	if (!door)
		return (0);
	last = door;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_door_addback(t_door **door, t_door *newdoor)
{
	t_door	*last;

	if (*door != NULL)
	{
		last = ft_last_door(*door);
		last->next = newdoor;
	}
	else
		*door = newdoor;
}

t_door	*init_door(char **map)
{
	int		x;
	int		y;
	t_door	*newdoor;
	t_door	*door;

	x = -1;
	y = 0;
	door = NULL;
	while (map != NULL && map[y] != NULL)
	{
		if (map[y][++x] == '\0')
		{
			x = 0;
			y++;
		}
		else
		{
			if (map[y][x] == 'D' || map[y][x] == 'O')
			{
				newdoor = is_door(x, y, map[y][x]);
				ft_door_addback(&door, newdoor);
			}
		}
	}
	return (door);
}
