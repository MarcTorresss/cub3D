/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 17:18:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"

int	mouse_press_handler(int button, int x, int y, t_keys *key)
{
	(void) x;
	(void) y;
	if (button == 1)
		key->left_m = 1;
	else if (button == 3)
		key->right_m = 1;
	return (0);
}

int	mouse_release_handler(int button, int x, int y, t_keys *key)
{
	(void) x;
	(void) y;
	if (button == 1)
		key->left_m = 0;
	else if (button == 3)
		key->right_m = 0;
	return (0);
}
