/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 14:56:24 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_check(char **map, int x, int y, char letterplayer)
{
	if (map[y][x] != '1' && map[y][x] != '0'
		&& map[y][x] != letterplayer
		&& map[y][x] != ' ' && map[y][x] != '\n')
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && y == 0)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && (map[y - 1][x] == ' '
		|| map[y + 1][x] == ' '))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer) && map[y + 1] == NULL)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letterplayer)
		&& (map[y][x + 1] == ' ' || map[y][x + 1] == '\n'))
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
	while (map[y] != NULL && map[y][++x] != '\0')
	{
		if (map[y][x] == 'W' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'N')
		{
			qtt++;
			parser->letterplayer = map[y][x];
		}
		if (map[y][x] == '\n')
		{
			x = -1;
			y++;
		}
	}
	if (qtt != 1)
		return (1);
	return (0);
}

int	check_map(t_data data, t_parser *parser)
{
	int		y;
	int		x;
	int		qtt;

	y = 0;
	x = -1;
	qtt = 0;
	if (check_player(data.map, parser) == 1)
		return (1);
	while (data.map[y] != NULL && data.map[y][++x] != '\0')
	{

		if (ft_check(data.map, x, y, parser->letterplayer) == 1)
			return (1);
		if (data.map[y][x] == '\n')
		{
			x = -1;
			y++;
		}
	}
	return (0);
}
