/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:48:19 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 20:28:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "player.h"

char	**padding_map(char **map, int *rows, int *cols)
{
	char	**new_map;
	int		i;

	*rows += PADDING * 2;
	*cols += PADDING * 2;
	new_map = (char **)malloc(sizeof(char *) * (*rows + 1));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < *rows)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (*cols + 1));
		if (new_map[i] == NULL)
			return (ft_free_split(new_map), NULL);
		ft_memset(new_map[i], ' ', *cols + 1);
		if (i >= PADDING && i < *rows - PADDING)
			ft_strlcpy(new_map[i] + PADDING, map[i - PADDING], *cols + 1);
		new_map[i][*cols] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static void	trim_image_path(t_parser *parser)
{
	parser->elem.NO[ft_strlen(parser->elem.NO) - 1] = '\0';
	parser->elem.SO[ft_strlen(parser->elem.SO) - 1] = '\0';
	parser->elem.EA[ft_strlen(parser->elem.EA) - 1] = '\0';
	parser->elem.WE[ft_strlen(parser->elem.WE) - 1] = '\0';
}

static void	set_scene_image(t_scene *scene, t_parser parser, t_data data)
{
	trim_image_path(&parser);
	scene->screen = get_new_image(scene->mlx, scene->width, scene->height);
	scene->n_wall = get_new_image_xpm(scene->mlx, parser.elem.NO);
	scene->s_wall = get_new_image_xpm(scene->mlx, parser.elem.SO);
	scene->e_wall = get_new_image_xpm(scene->mlx, parser.elem.EA);
	scene->w_wall = get_new_image_xpm(scene->mlx, parser.elem.WE);
	scene->full_map = get_new_image(scene->mlx, \
							scene->rows * GRID_UNIT + MMAP_SIZE * GRID_UNIT, \
							scene->cols * GRID_UNIT + MMAP_SIZE * GRID_UNIT);
	scene->mmap = get_new_image(scene->mlx, \
							MMAP_SIZE * GRID_UNIT, MMAP_SIZE * GRID_UNIT);
	if (scene->screen == NULL || scene->n_wall == NULL || \
		scene->s_wall == NULL || scene->e_wall == NULL || scene->mmap == NULL \
		|| scene->w_wall == NULL || scene->full_map == NULL)
	{
		free_all(&parser, &data);
		free_mlx(scene);
		exit(0);
	}
}

void	set_mlx(t_scene *scene, t_parser parser, t_data data)
{

	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
	{
		free_all(&parser, &data);
		exit(0);
	}
	scene->win = mlx_new_window(scene->mlx, scene->width, \
		scene->height, "cub3D");
	if (scene->win == NULL)
	{
		free_all(&parser, &data);
		exit(0);
	}
}

void	set_scene(t_scene *scene, t_parser parser, t_data data)
{
	scene->rows = data.rowsy;
	scene->cols = data.colsx;
	scene->width = 1920;
	scene->height = 1080;
	scene->map = padding_map(data.map, &scene->rows, &scene->cols);
	scene->player = set_player(scene->map);
	set_mlx(scene, parser, data);
	if (scene->map == NULL)
	{
		free_all(&parser, &data);
		mlx_destroy_window(scene->mlx, scene->win);
		exit(0);
	}
	set_scene_image(scene, parser, data);
}
