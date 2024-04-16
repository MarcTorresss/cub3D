/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:40:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:46:27 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"
#include "libft.h"
#include <stdlib.h>

static void	check_exit(t_keys *key, t_scene	*scene)
{
	if (key->esc)
	{
		free_mlx(scene);
		exit(0);
	}
}

int	render(void **pack)
{
	t_scene	*scene;
	t_keys	*keys;

	scene = (t_scene *)(pack[0]);
	keys = (t_keys *)(pack[1]);
	check_exit(keys, scene);
	check_space(keys, scene);
	check_key_move(keys, &scene->player, scene->map);
	check_key_rotate(keys, &scene->player);
	check_mouse_click(scene);
	
	draw(*scene);
	return (0);
}
