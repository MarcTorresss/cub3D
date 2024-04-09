/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:40:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:10 by junghwle         ###   ########.fr       */
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

static void	check_move(t_keys *key, t_player *player)
{
	t_vec2	move;

	ft_memset(&move, 0, sizeof(t_vec2));
	if (key->w)
	{
		move.x += player->dir.x * FRQ;
		move.y += player->dir.y * FRQ;
	}
	if (key->s)
	{
		move.x -= player->dir.x * FRQ;
		move.y -= player->dir.y * FRQ;
	}
	if (key->a)
	{
		move.x -= player->dir.y * FRQ;
		move.y += player->dir.x * FRQ;
	}
	if (key->d)
	{
		move.x += player->dir.y * FRQ;
		move.y -= player->dir.x * FRQ;
	}
	player->pos = sum_vec2(player->pos, move);
}

int	render(void **pack)
{
	t_scene	*scene;
	t_keys	*keys;

	scene = (t_scene *)(pack[0]);
	keys = (t_keys *)(pack[1]);
	check_exit(keys, scene);
	check_space(keys, scene);
	check_move(keys, &scene->player);
	check_key_rotate(keys, &scene->player);
	draw(*scene);
	return (0);
}
