/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 19:26:08 by junghwle         ###   ########.fr       */
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
}
