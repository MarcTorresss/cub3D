/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/18 12:33:21 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "player.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>

void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir = create_vector2d(-1, 0);
		player->plane = create_vector2d(0, 1);
	}
	else if (dir == 'E')
	{
		player->dir = create_vector2d(0, 1);
		player->plane = create_vector2d(1, 0);
	}
	else if (dir == 'S')
	{
		player->dir = create_vector2d(1, 0);
		player->plane = create_vector2d(0, -1);
	}
	else if (dir == 'W')
	{
		player->dir = create_vector2d(0, -1);
		player->plane = create_vector2d(-1, 0);
	}
}

t_player	set_player(char **map)
{
	int			i;
	int			j;
	t_player	player;

	ft_memset(&player, 0, sizeof(t_player));
	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map[i][j]) != NULL)
			{
				player.pos = create_vector2d((double)i + 0.5, (double)j + 0.5);
				set_player_direction(&player, map[i][j]);
				player.dir_len = length_vec2(player.dir);
				player.plane = scalar_vec2(player.plane, PLANE_SCALE);
				player.v_dist = 0;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	delete_enter(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
}

t_point	init_pos(void)
{
	t_point	pos;

	pos.x = -1;
	pos.y = 0;
	return (pos);
}
