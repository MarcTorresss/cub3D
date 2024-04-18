/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/18 12:48:34 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "scene.h"

int	check_is_good_line(char **check_line)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (check_line && check_line[y] != NULL)
	{
		if (ft_strchr("01 \nNSWE", check_line[y][x]) == NULL
			&& check_line[y][x] != '\0')
			return (1);
		if (check_line[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		x++;
	}
	return (0);
}

int	check_more_elements(char **check_line, t_parser *parser)
{
	if (ft_strcmp(check_line[0], "EA") == 0)
	{
		if (parser->elem.ea == NULL)
			parser->elem.ea = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.ea++;
	}
	else if (ft_strcmp(check_line[0], "F") == 0)
	{
		if (parser->elem.f == NULL)
			parser->elem.f = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.f++;
	}
	else if (ft_strcmp(check_line[0], "C") == 0)
	{
		if (parser->elem.c == NULL)
			parser->elem.c = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.c++;
	}
	else
		return (check_is_good_line(check_line));
	return (0);
}

int	check_elemet(char **check_line, t_parser *parser)
{
	if (ft_strcmp(check_line[0], "NO") == 0)
	{
		if (parser->elem.no == NULL)
			parser->elem.no = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.no++;
	}
	else if (ft_strcmp(check_line[0], "SO") == 0)
	{
		if (parser->elem.so == NULL)
			parser->elem.so = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.so++;
	}
	else if (ft_strcmp(check_line[0], "WE") == 0)
	{
		if (parser->elem.we == NULL)
			parser->elem.we = ft_substr(check_line[1], 0,
					ft_strlen(check_line[1]));
		parser->elem.qtt.we++;
	}
	else
		return (check_more_elements(check_line, parser));
	return (0);
}

int	do_it(t_parser *parser, char *str)
{
	char	**check_line;
	int		qtt_args;

	check_line = ft_split(str, ' ');
	qtt_args = count_args(check_line);
	if (qtt_args == 2)
	{
		if (check_elemet(check_line, parser) == 1)
			return (1);
	}
	else
		check_num(ft_strtrim(check_line[0], " "), parser);
	ft_free_split(check_line);
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
	if (parser->elem.qtt.no != 1 || parser->elem.qtt.so != 1
		|| parser->elem.qtt.we != 1 || parser->elem.qtt.ea != 1
		|| parser->elem.qtt.f != 1 || parser->elem.qtt.c != 1
		|| parser->elem.qtt.is_zero != 0)
		return (1);
	if (check_f_c(parser, scene) == 1)
		return (1);
	return (0);
}
