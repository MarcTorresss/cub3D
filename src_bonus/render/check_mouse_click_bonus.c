/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_click_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:55 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:40:21 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	door_animation(t_scene *scene, int x, int y)
{
	t_door	*door;

	door = get_door_object(*scene, x, y);
	init_door_animation(door);
}

void	check_mouse_click(t_scene *scene)
{
	static int	flag;
	t_vec2		action_point;
	int			x;
	int			y;

	if (scene->map[(int)scene->player.pos.x][(int)scene->player.pos.y] == 'O')
		return ;
	if (scene->left_m == 1 && flag == 0)
	{
		action_point = sum_vec2(scene->player.pos, \
						scalar_vec2(scene->player.dir, 0.4));
		x = (int)action_point.x;
		y = (int)action_point.y;
		if (scene->map[x][y] == 'D' || scene->map[x][y] == 'O')
			door_animation(scene, x, y);
		flag = 1;
	}
	else if (scene->left_m == 0 && flag == 1)
		flag = 0;
}
