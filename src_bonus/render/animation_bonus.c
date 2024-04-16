/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:21:30 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:47:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	finish_animation(t_door *door, char **map)
{
	if (door->state == 'o')
	{
		map[door->y][door->x] = 'O';
		door->state = 'O';
	}
	if (door->state == 'd')
		door->state = 'D';
	door->timer = 0;
}

void	update_timer(t_door *door, char **map, long prev_frame)
{
	int	time;

	if (door->state == 'd' || door->state == 'o')
	{
		time = get_current_time() - prev_frame;
		door->timer -= (double)time / 1000.0f;
		if (door->timer < 0)
			finish_animation(door, map);
	}
}

void	init_door_animation(t_door *door, char **map)
{
	if (door->state == 'O' && door->timer == 0)
	{
		map[door->y][door->x] = 'D';
		door->state = 'd';
		door->timer = 1.0f;
	}
	else if (door->state == 'D' && door->timer == 0)
	{
		door->state = 'o';
		door->timer = 1.0f;
	}
}