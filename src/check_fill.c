/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:24:18 by martorre          #+#    #+#             */
/*   Updated: 2024/04/03 15:39:33 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	fill(char **tab, t_point size, t_point cur)
{
	//ft_fprintf(1, "s = %s, col = %d, row = %d, cur.x = %d, cur.y = %d\n", *tab, size.x, size.y, cur.x, cur.y);
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	check_letter_pos(t_pos *pos, char **tab, int y, int x)
{
	if (tab[y][x] == 'N' || tab[y][x] == 'S' 
		|| tab[y][x] == 'E' || tab[y][x] == 'O')
	{
		pos->begin.x = x;
		pos->begin.y = y;
		pos->posplayer = tab[y][x];
		tab[pos->begin.y][pos->begin.x] = '0';
		//ft_fprintf(1, "\ny = %d, x = %d\n", y, x);
		//ft_fprintf(1, "\ny = %d, x = %d\n", pos->begin.y, pos->begin.x);
	}
}

t_pos	init_pos_char(char **tab)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = -1;
	while (tab[y][++x] != '\0')
	{
		check_letter_pos(&pos, tab, y, x);
		//ft_fprintf(1, "%c", tab[y][x]);
		if (tab[y][x] == '\n' || tab[y][x] == '\0')
		{
			x = -1;
			y++;
		}
	}
	//ft_fprintf(1, "\ny = %d, x = %d\n", pos.begin.y, pos.begin.x);
	//tab[pos.begin.y][pos.begin.x] = '0';
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
	(void) pos;
	while (data->mapcpy[y][++x] != '\0')
	{
		ft_fprintf(1, "%c", data->mapcpy[y][x]);
		if (ft_check_fs(data->mapcpy, x, y) == 1)
			return (ft_fprintf(2, ERR_MAP));
		pos = init_pos_char(data->mapcpy);
		if (data->mapcpy[y][x] == '\n')
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

	pos = init_pos_char(data->mapcpy);
	//size.posplayer = pos.posplayer;
	fill(data->mapcpy, size, pos.begin);
	data->mapcpy[pos.begin.y][pos.begin.x] = 'P';
	if (check_fill_map(pos, data) == 1)
		return (/*ft_free_map(data), */ft_fprintf(2, "Invalid map\n"), 1);
	return (0);
}