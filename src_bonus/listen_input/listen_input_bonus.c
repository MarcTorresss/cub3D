/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 17:18:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"
#include <mlx.h>

int	mouse_moving_handler(int x, int y, t_scene *scene)
{
	static t_player	*player;
	static t_vec2	prev_point;
	t_vec2			step;
	// t_keys			*keys;

	if (player == NULL)
	{
		player = &scene->player;
		prev_point = create_vector2d(x, y);
	}
	// keys = ((t_keys *)((pack[1])));
	// if (keys->left_m == 1)
	// {
		step.x = (x - prev_point.x) * 2;
		step.y = (y - prev_point.y) * 40;
		player->dir = normalize_vec2(rotate_vec2(player->dir, step.x * FRQ));
		player->plane = normalize_vec2(rotate_vec2(player->plane, step.x * FRQ));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
		if (player->v_dist < 1000 && player->v_dist > -1000)
			player->v_dist += step.y * FRQ;
		prev_point = create_vector2d(x, y);
	// }
	return (0);
}

void	listen_input(t_scene *scene, t_keys *keys)
{
	mlx_hook(scene->win, KEY_PRESS, KEY_PRESS_MASK, \
			key_press_handler, keys);
	mlx_hook(scene->win, KEY_RELEASE, KEY_RELEASE_MASK, \
			key_release_handler, keys);
	mlx_hook(scene->win, ON_DESTROY, NO_EVENT_MASK, \
			finish_program, keys);
	mlx_hook(scene->win, MOUSE_DOWN, MOUSE_DOWN_MASK, \
			mouse_press_handler, keys);
	mlx_hook(scene->win, MOUSE_UP, MOUSE_UP_MASK, \
			mouse_release_handler, keys);
	mlx_hook(scene->win, ON_MOUSE_MOVE, MOUSE_MOVE_MASK, mouse_moving_handler, scene);
}