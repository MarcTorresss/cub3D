/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_click_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:19:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	open_door(t_scene *scene, int x, int y)
{
	scene->map[x][y] = 'O';
}

void	close_door(t_scene *scene, int x, int y)
{
	scene->map[x][y] = 'D';
}

void	check_mouse_click(t_scene *scene)
{
	static int flag;
	t_vec2	action_point;
	int		x;
	int		y;
	
	if (scene->map[(int)scene->player.pos.x][(int)scene->player.pos.y] == 'O')
		return ;
	if (scene->left_m == 1 && flag == 0)
	{
		action_point = sum_vec2(scene->player.pos, \
						scalar_vec2(scene->player.dir, 0.4));
		x = (int)action_point.x;
		y = (int)action_point.y;
		if (scene->map[x][y] == 'D')
			open_door(scene, x, y);
		else if (scene->map[x][y] == 'O')
			close_door(scene, x, y);
		flag = 1;
	}
	else if (scene->left_m == 0 && flag == 1)
		flag = 0;
}
