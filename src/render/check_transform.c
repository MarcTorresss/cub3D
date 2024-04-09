/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:02 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 21:44:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"
#include "libft.h"

void	check_space(t_keys *key, t_scene *scene)
{
	if (key->space)
		scene->player = set_player(scene->map);
}

static int    is_not_wall(char **map, t_vec2 move, t_player player)
{
    int x;
    int y;

    x = (int)(player.pos.x + move.x * 6);
    y = (int)(player.pos.y + move.y * 6);
    if (map[x][y] == '1')
        return (0);
    return (1);
}

void	check_key_move(t_keys *key, t_player *player, char **map)
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
    if (is_not_wall(map, move, *player))
	    player->pos = sum_vec2(player->pos, move);
}

void	check_key_rotate(t_keys *key, t_player *player)
{
	if (key->left)
	{
		player->dir = normalize_vec2(rotate_vec2(player->dir, 75 * FRQ));
		player->plane = normalize_vec2(rotate_vec2(player->plane, 75 * FRQ));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
	}
	if (key->right)
	{
		player->dir = normalize_vec2(rotate_vec2(player->dir, -75 * FRQ));
		player->plane = normalize_vec2(rotate_vec2(player->plane, -75 * FRQ));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
	}
	if (key->up)
	{
		if (player->v_dist < 1000)
			player->v_dist += 1000 * FRQ;
	}
	if (key->down)
	{
		if (player->v_dist > -1000)
		player->v_dist -= 1000 * FRQ;
	}
}
