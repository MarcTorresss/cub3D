/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:24:18 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 19:23:05 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_letter_pos_player(t_pos *pos, char **tab, int y, int x)
{
	if (tab[y][x] == 'N' || tab[y][x] == 'S' 
		|| tab[y][x] == 'E' || tab[y][x] == 'O')
	{
		pos->begin.x = x;
		pos->begin.y = y;
		pos->posplayer = tab[y][x];
		tab[pos->begin.y][pos->begin.x] = '0';
	}
}

t_pos	initial_position_player(char **map)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = -1;
	while (map[y][++x] != '\0')
	{
		check_letter_pos_player(&pos, map, y, x);
		//ft_fprintf(1, "%c", map[y][x]);
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			x = -1;
			y++;
		}
	}
	//ft_fprintf(1, "\ny = %d, x = %d\n", pos.begin.y, pos.begin.x);
	//map[pos.begin.y][pos.begin.x] = '0';
	return (pos);
}

void	fill(char **tab, t_point size, t_point cur)
{
	//ft_fprintf(1, "\ns = %s, col = %d, row = %d, cur.x = %d, cur.y = %d\n", *tab, size.x, size.y, cur.x, cur.y);
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

int	zero_position(t_pos *pos, char **tab, int y, int x)
{
	if (tab[y][x] == '0')
	{
		pos->begin.x = x;
		pos->begin.y = y;
		return (1);
	}
	else
	{
		pos->begin.x = -1;
		pos->begin.y = -1;
	}
	return (0);
}

t_pos	initial_pos_zero(char **map)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = -1;
	while (map[y][++x] != '\0')
	{
		if (zero_position(&pos, map, y, x) == 1)
			break ;
		if (map[y][x] == '\n' || map[y][x] == '\0')
		{
			x = -1;
			y++;
		}
	}
	return (pos);
}

int	ft_check_fs(char **map, int x, int y)
{
	if (map[y][x] == 'F')
	{
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'F' && map[y][x + 1] != 'P')
			return (1);
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'F' && map[y + 1][x] != 'P')
			return (1);
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'F' && map[y][x - 1] != 'P')
			return (1);
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'F' && map[y - 1][x] != 'P')
			return (1);
	}
	return (0);
}

int	check_fill_map(t_pos pos, t_data *data)
{
	int		y;
	int		x;
	
	y = 0;
	x = -1;
	while (data->map[y][++x] != '\0')
	{
		//ft_fprintf(1, "%c", data->map[y][x]);
		if (ft_check_fs(data->map, x, y) == 1)
			return (1);
		pos = initial_pos_zero(data->map);
		if (data->map[y][x] == '\n')
		{
			x = -1;
			y++;
		}
	}
	return (0);
}

int	flood_fill(t_data *data, t_point size)
{
	t_pos	pos;
	t_pos	posplayer;
	posplayer = initial_position_player(data->map);
	//Checkear bucle infinito -> funcion zero_position
	while (pos.begin.x != -1 && pos.begin.y != -1)
	{
		pos = initial_pos_zero(data->map);
		fill(data->map, size, pos.begin);
		//data->map[pos.begin.y][pos.begin.x] = 'P';
	}
	return (check_fill_map(pos, data));
}
