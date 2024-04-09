/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 19:25:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"

int	key_press_handler(int keycode, t_keys *keys)
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

int	key_release_handler(int keycode, t_keys *keys)
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

int	finish_program(t_keys *key)
{
	key->esc = 1;
	return (0);
}
