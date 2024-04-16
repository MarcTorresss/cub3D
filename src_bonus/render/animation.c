/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:21:30 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 16:53:47 by martorre         ###   ########.fr       */
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

void	finish_animation(t_door *door, t_scene *scene)
{
	if (door->state == 'o')
		door->state = 'O';
	if (door->state == 'd')
		door->state = 'D';
	scene->prev_frame = 0;
}

void	update_timer(t_door *door, t_scene *scene)
{
	int	time;

	time = 0;
	if (scene->prev_frame == 0)
		time = get_current_time() - scene->prev_frame;
	else
	{
		if (door->state == 'd' || door->state == 'o')
			time = get_current_time() - door->timer;
		if (time < 0)
			finish_animation(door, scene);
		scene->prev_frame = get_current_time();
	}
}

void	init_door_animation(t_door *door)
{
	if (door->state == 'O')
	{
		door->state = 'd';
		door->timer = 1;
	}
	else
	{
		door->state = 'o';
		door->timer = get_current_time();
	}
}
