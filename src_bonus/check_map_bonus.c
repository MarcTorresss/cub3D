/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/16 17:18:35 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_this_char(char **map, int x, int y, char letterplayer)
{
	if (map[y][x] == '0' || map[y][x] == letterplayer || map[y][x] == 'D'
		|| map[y][x] == 'O')
		return (1);
	return (0);
}

int	ft_check_bonus(char **map, int x, int y, char letterplayer)
{
	if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != letterplayer
		&& map[y][x] != ' ' && map[y][x] != 'D' && map[y][x] != 'O'
		&& map[y][x] != '\0')
		return (1);
	if (is_this_char(map, x, y, letterplayer) == 1 && y == 0)
		return (1);
	if ((is_this_char(map, x, y, letterplayer) == 1) && (map[y - 1][x] == ' '
		|| map[y + 1][x] == ' '))
		return (1);
	if ((is_this_char(map, x, y, letterplayer) == 1) && map[y + 1] == NULL)
		return (1);
	if ((is_this_char(map, x, y, letterplayer) == 1) && (map[y][x + 1] == ' '
		|| map[y][x - 1] == ' '))
		return (1);
	if (ft_check_doors(map, x, y) == 1)
		return (1);
	return (0);
}

int	check_player_bonus(char **map, t_parser *parser)
{
	t_point	pos;
	int		qtt;

	pos = init_pos();
	qtt = 0;
	while (map != NULL && map[pos.y] != NULL)
	{
		if (map[pos.y][++pos.x] == '\0')
		{
			pos.x = -1;
			pos.y++;
		}
		else
		{
			if (map[pos.y][pos.x] == 'W' || map[pos.y][pos.x] == 'S'
				|| map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'N')
			{
				qtt++;
				parser->letterplayer = map[pos.y][pos.x];
			}
		}
	}
	if (qtt != 1)
		return (1);
	return (0);
}

int	check_map_bonus(t_parser *parser, t_scene scene)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	if (check_player_bonus(scene.map, parser) == 1)
		return (1);
	while (scene.map != NULL && scene.map[y] != NULL)
	{
		if (scene.map[y][++x] == '\0')
		{
			x = -1;
			y++;
		}
		else
		{
			if (ft_check_bonus(scene.map, x, y, parser->letterplayer) == 1)
				return (1);
		}
	}
	return (0);
}
