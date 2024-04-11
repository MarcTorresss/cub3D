/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:02:41 by martorre          #+#    #+#             */
/*   Updated: 2024/04/11 13:08:00 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
#include "../inc/scene.h"

void	free_parser(t_parser *parser)
{
	int	y;

	y = 0;
	while (parser && parser->file && parser->file[y])
	{
		free(parser->file[y]);
		y++;
	}
	free(parser->file);
	ft_free_elements(parser);
}

void	free_scene(t_parser *parser, t_scene *scene)
{
	int	y;

	y = 0;
	(void)scene;
	while (scene && scene->map && scene->map[y] != NULL)
	{
		free(scene->map[y]);
		y++;
	}
	free(scene->map);
	free_parser(parser);
}

void	free_data(t_parser *parser, t_data *data, t_scene *scene)
{
	int	y;

	y = 0;
	while (data && data->map && data->map[y])
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	free_scene(parser, scene);
}

void	ft_free_split(char **check_line)
{
	int i;

	i = 0;
	while (check_line[i] != NULL)
	{
		free(check_line[i]);
		i++;
	}
	free(check_line);
}