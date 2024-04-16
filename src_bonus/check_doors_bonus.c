/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:33:56 by martorre          #+#    #+#             */
/*   Updated: 2024/04/16 13:10:29 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_check_doors(char **map, int x, int y)
{
	if (map[y][x] == 'D' || map[y][x] == 'O')
	{
		// printf("HOLA\n");
		// printf("map[y-1][x] = %c, map[y+1][x] = %c", map[y-1][x], map[y+1][x]);
		if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
			return (0);
		if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
			return (0);
		return (1);
	}
	return (0);
}

int	qtts_okei_bonus(t_parser parser)
{
	if (parser.elem.qtt.no != 1 || parser.elem.qtt.so != 1
		|| parser.elem.qtt.we != 1 || parser.elem.qtt.ea != 1
		|| parser.elem.qtt.f != 1 || parser.elem.qtt.c != 1
		|| parser.elem.qtt.is_zero != 0 || parser.elem.qtt.door != 1)
		return (1);
	return (0);
}
