/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_click_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 13:04:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	open_door(void)
{
	
}

void	close_door(void)
{
	
}

void	check_mouse_click(t_scene *scene)
{
	static int flag;
	t_vec2	action_point;
	int		x;
	int		y;
	
	if (scene->left_m == 1 && flag == 0)
	{
		action_point = sum_vec2(scene->player.pos, \
						scalar_vec2(scene->player.dir, 0.4));
		x = (int)action_point.x;
		y = (int)action_point.y;
		if (scene->map[x][y] == 'D')
		{
			open_door();
			scene->map[x][y] = 'O';
		}
		else if (scene->map[x][y] == 'O')
		{
			close_door();
			scene->map[x][y] = 'D';
		}
		flag = 1;
	}
	else if (scene->left_m == 0 && flag == 1)
		flag = 0;
}
