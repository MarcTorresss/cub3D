/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 19:27:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"
#include <mlx.h>

void	listen_input(t_scene *scene, t_keys *keys)
{
	mlx_hook(scene->win, KEY_PRESS, KEY_PRESS_MASK, \
			key_press_handler, keys);
	mlx_hook(scene->win, KEY_RELEASE, KEY_RELEASE_MASK, \
			key_release_handler, keys);
	mlx_hook(scene->win, ON_DESTROY, NO_EVENT_MASK, \
			finish_program, keys);
	mlx_hook(scene->win, MOUSE_DOWN, MOUSE_DOWN_MASK, \
			mouse_press_handler, scene);
	mlx_hook(scene->win, MOUSE_UP, MOUSE_UP_MASK, \
			mouse_release_handler, scene);
	mlx_hook(scene->win, ON_MOUSE_MOVE, MOUSE_MOVE_MASK, \
			mouse_moving_handler, scene);
}
