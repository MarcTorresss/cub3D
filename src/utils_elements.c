/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:52:29 by martorre          #+#    #+#             */
/*   Updated: 2024/04/11 12:39:59 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "scene.h"

int	count_args(char **check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != NULL)
		i++;
	return (i);
}

int	check_rgb_rang(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return (0);
	return (1);
}

int	check_rgb_nums(char **mat)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (mat[y] != NULL)
	{
		x = 0;
		while (mat[y][x] != '\0')
		{
			if (!ft_isdigit(mat[y][x]) && (mat[y][x] != '\0'
				&& mat[y][x] != '\n'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	convert_hexadecimal(char **sp_f, char **sp_c, t_scene *scene)
{
	int	r;
	int	g;
	int	b;

	r = ft_atol(sp_f[0]);
	g = ft_atol(sp_f[1]);
	b = ft_atol(sp_f[2]);
	if (check_rgb_rang(r, g, b) == 1)
		return (1);
	scene->ccolor = (r << 16) + (g << 8) + b;
	r = ft_atol(sp_c[0]);
	g = ft_atol(sp_c[1]);
	b = ft_atol(sp_c[2]);
	if (check_rgb_rang(r, g, b) == 1)
		return (1);
	scene->fcolor = (r << 16) + (g << 8) + b;
	return (0);
}

int	check_f_c(t_parser *parser, t_scene *scene)
{
	char	**sp_f;
	char	**sp_c;

	sp_f = ft_split(parser->elem.f, ',');
	sp_c = ft_split(parser->elem.c, ',');
	if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
		return (ft_free_split(sp_f), ft_free_split(sp_c), 1);
	else
	{
		if (check_rgb_nums(sp_f) == 0 && check_rgb_nums(sp_c) == 0)
		{
			if (convert_hexadecimal(sp_f, sp_c, scene) == 1)
				return (ft_free_split(sp_f), ft_free_split(sp_c), 1);
		}
		else
			return (ft_free_split(sp_f), ft_free_split(sp_c), 1);
	}
	ft_free_split(sp_f);
	ft_free_split(sp_c);
	return (0);
}
