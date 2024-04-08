/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:40:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 12:18:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"

static void	check_exit(int keycode, t_scene	*scene)
{
	if (keycode == KEY_EXIT)
	{
		free_mlx(scene);
		exit(0);
	}
}

static void	check_move(int keycode, t_player *player)
{
	if (keycode == KEY_UP)
	{
		player->pos.x += player->dir.x * 0.1;
		player->pos.y += player->dir.y * 0.1;
	}
	else if (keycode == KEY_DOWN)
	{
		player->pos.x -= player->dir.x * 0.1;
		player->pos.y -= player->dir.y * 0.1;
	}
	else if (keycode == KEY_LEFT)
	{
		player->pos.x -= player->dir.y * 0.1;
		player->pos.y += player->dir.x * 0.1;
	}
	else if (keycode == KEY_RIGHT)
	{
		player->pos.x += player->dir.y * 0.1;
		player->pos.y -= player->dir.x * 0.1;
	}
}

static void	check_rotate(int keycode, t_player *player)
{
	if (keycode == KEY_A)
	{
		player->dir = normalize_vec2(rotate_vec2(player->dir, 10));
		player->plane = normalize_vec2(rotate_vec2(player->plane, 10));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
	}
	if (keycode == KEY_D)
	{
		player->dir = normalize_vec2(rotate_vec2(player->dir, -10));
		player->plane = normalize_vec2(rotate_vec2(player->plane, -10));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
	}
}

int	key_hook(int keycode, t_scene *scene)
{
	check_exit(keycode, scene);
	check_move(keycode, &scene->player);
	check_rotate(keycode, &scene->player);
	draw(*scene);
	return (0);
}
