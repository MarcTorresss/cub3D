/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/11 12:33:52 by martorre         ###   ########.fr       */
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
		&& map[y][x] != ' ' && map[y][x] != '\0')
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
	int	y;
	int	x;
	int	qtt;

	y = 0;
	x = -1;
	qtt = 0;
	while (map != NULL && map[y] != NULL)
	{
		if (map[y][++x] == '\0')
		{
			x = -1;
			y++;
		}
		else
		{
			if (is_this_player(map, x, y) == 1)
			{
				qtt++;
				parser->letterplayer = map[y][x];
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
	int	qtt;

	y = 0;
	x = 0;
	qtt = 0;
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
