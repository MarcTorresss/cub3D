/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/18 12:44:31 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	is_this_player(char **map, int x, int y)
{
	if (map[y][x] == 'W' || map[y][x] == 'S' || map[y][x] == 'E'
		|| map[y][x] == 'N')
		return (1);
	return (0);
}

int	check_num(char *str, t_parser *parser)
{
	if (str != NULL)
	{
		if (str[0] != '1')
		{
			parser->elem.qtt.is_zero++;
			return (free(str), 1);
		}
	}
	free(str);
	return (0);
}

int	ft_check(char **map, int x, int y, char letterplayer)
{
	if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != letterplayer
		&& map[y][x] != ' ' && map[y][x] != '\0' && map[y][x] != '\n')
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && y == 0)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && (map[y - 1][x] == ' '
			|| map[y + 1][x] == ' '))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && map[y + 1] == NULL)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && (map[y][x + 1] == ' '
			|| map[y][x + 1] == '\0'))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	check_player(char **map, t_parser *parser)
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
			if (is_this_player(map, pos.x, pos.y) == 1)
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

int	check_map(t_parser *parser, t_scene scene)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (check_player(scene.map, parser) == 1)
		return (1);
	while (scene.map != NULL && scene.map[y] != NULL)
	{
		if (scene.map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		else
		{
			if (ft_check(scene.map, x, y, parser->letterplayer) == 1)
				return (1);
		}
		x++;
	}
	return (0);
}
