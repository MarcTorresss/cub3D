/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 17:18:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"
#include <mlx.h>
#include <stdlib.h>

static int    key_press_handler(int keycode, t_keys *keys)
{
	if (keycode == KEY_EXIT)
		keys->esc = 1;
	if (keycode == KEY_UP)
        keys->up = 1;
	if (keycode == KEY_DOWN)
        keys->down = 1;
	if (keycode == KEY_LEFT)
        keys->left = 1;
	if (keycode == KEY_RIGHT)
        keys->right = 1;
	if (keycode == KEY_W)
        keys->w = 1;
	if (keycode == KEY_S)
        keys->s = 1;
	if (keycode == KEY_A)
        keys->a = 1;
	if (keycode == KEY_D)
        keys->d = 1;
	if (keycode == KEY_SPACE)
		keys->space = 1;
	return (0);
}

static int    key_release_handler(int keycode, t_keys *keys)
{
	if (keycode == KEY_UP)
        keys->up = 0;
	if (keycode == KEY_DOWN)
        keys->down = 0;
	if (keycode == KEY_LEFT)
        keys->left = 0;
	if (keycode == KEY_RIGHT)
        keys->right = 0;
	if (keycode == KEY_W)
        keys->w = 0;
	if (keycode == KEY_S)
        keys->s = 0;
	if (keycode == KEY_A)
        keys->a = 0;
	if (keycode == KEY_D)
        keys->d = 0;
	if (keycode == KEY_SPACE)
		keys->space = 0;
	return (0);
}

static int	finish_program(t_keys *key)
{
	key->esc = 1;
	return (0);
}

void	listen_input(t_scene scene, t_keys *keys)
{
	mlx_hook(scene.win, KEY_PRESS, KEY_PRESS_MASK, key_press_handler, keys);
	mlx_hook(scene.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release_handler, keys);
	mlx_hook(scene.win, ON_DESTROY, NO_EVENT_MASK, finish_program, keys);
}