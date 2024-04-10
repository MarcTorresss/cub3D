/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/10 17:05:07 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "scene.h"

void	check_more_elements(char **check_line, t_parser *parser)
{
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
}

void	check_elemet(char **check_line, t_parser *parser)
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
	check_more_elements(check_line, parser);
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

int	qtts_okei(t_parser parser)
{
	if (parser.elem.qtt.NO != 1 || parser.elem.qtt.SO != 1
		|| parser.elem.qtt.WE != 1 || parser.elem.qtt.EA != 1
		|| parser.elem.qtt.F != 1 || parser.elem.qtt.C != 1
		|| parser.elem.qtt.is_zero != 0)
		return (1);
	return (0);
}

int	check_elements(t_parser *parser, t_scene *scene)
{
	int	y;

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
	if (qtts_okei(*parser) == 1)
		return (1);
	if (check_f_c(parser, scene) == 1)
		return (1);
	return (0);
}
