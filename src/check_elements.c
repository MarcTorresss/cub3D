/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 19:47:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "scene.h"

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

int	check_elemet(char **check_line, t_parser *parser)
{
	if (ft_strcmp(check_line[0], "NO") == 0)
	{
		if (parser->elem.NO == NULL)
			parser->elem.NO = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.NO++;
	}
	if (ft_strcmp(check_line[0], "SO") == 0)
	{
		if (parser->elem.SO == NULL)
			parser->elem.SO = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.SO++;
	}
	if (ft_strcmp(check_line[0], "WE") == 0)
	{
		if (parser->elem.WE == NULL)
			parser->elem.WE = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.WE++;
	}
	if (ft_strcmp(check_line[0], "EA") == 0)
	{
		if (parser->elem.EA == NULL)
			parser->elem.EA = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.EA++;
	}
	if (ft_strcmp(check_line[0], "F") == 0)
	{
		if (parser->elem.F == NULL)
			parser->elem.F = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.F++;
	}
	if (ft_strcmp(check_line[0], "C") == 0)
	{
		if (parser->elem.C == NULL)
			parser->elem.C = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.C++;
	}
	return (0);
}

int	count_args(char **check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != NULL)
		i++;
	return (i);
}

int	do_it(t_parser *parser, char *str)
{
	char	**check_line;
	int		qtt_args;

	check_line = ft_split(str, ' ');
	qtt_args = count_args(check_line);
	if (qtt_args == 2)
		check_elemet(check_line, parser);
	else
		check_num(ft_strtrim(check_line[0], " "), parser);
	ft_free_split(check_line);
	return (0);
}

void	convert_hexadecimal(char **sp_f, char **sp_c, t_scene *scene)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = ft_atol(sp_f[0]);
	g = ft_atol(sp_f[1]);
	b = ft_atol(sp_f[2]);
	scene->ccolor = (r << 16) + (g << 8) + b;

	r = ft_atol(sp_c[0]);
	g = ft_atol(sp_c[1]);
	b = ft_atol(sp_c[2]);
	scene->fcolor = (r << 16) + (g << 8) + b;
}

int	check_elements(t_parser *parser, t_scene *scene)
{
	int y;

	y = 0;
	while (parser->file[y] != NULL)
	{
		if (ft_strcmp(parser->file[y], "\n") == 0)
			y++;
		else
		{
			if (do_it(parser, parser->file[y]) == 1)
				return (1);
			y++;
		}
	}
	if (parser->elem.qtt.NO != 1 || parser->elem.qtt.SO != 1
		|| parser->elem.qtt.WE != 1 || parser->elem.qtt.EA != 1
		|| parser->elem.qtt.F != 1 || parser->elem.qtt.C != 1
		|| parser->elem.qtt.is_zero != 0)
		return (1);
	char **sp_f = ft_split(parser->elem.F, ',');
	char **sp_c = ft_split(parser->elem.C, ',');
	if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
		return (1);
	else
		convert_hexadecimal(sp_f, sp_c, scene);
	ft_free_split(sp_f);
	ft_free_split(sp_c);
	return (0);
}

