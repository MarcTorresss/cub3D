/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:48:19 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:46:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "player.h"
#include "scene.h"

char	**padding_map(char **map, int *rows, int *cols)
{
	char	**new_map;
	int		i;

	delete_enter(map);
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
	parser->elem.no[ft_strlen(parser->elem.no) - 1] = '\0';
	parser->elem.so[ft_strlen(parser->elem.so) - 1] = '\0';
	parser->elem.ea[ft_strlen(parser->elem.ea) - 1] = '\0';
	parser->elem.we[ft_strlen(parser->elem.we) - 1] = '\0';
	parser->elem.door[ft_strlen(parser->elem.door) - 1] = '\0';
}

static void	set_scene_image(t_scene *scene, t_parser parser, t_data data)
{
	trim_image_path(&parser);
	scene->screen = get_new_image(scene->mlx, scene->width, scene->height);
	scene->n_wall = get_new_image_xpm(scene->mlx, parser.elem.no);
	scene->s_wall = get_new_image_xpm(scene->mlx, parser.elem.so);
	scene->e_wall = get_new_image_xpm(scene->mlx, parser.elem.ea);
	scene->w_wall = get_new_image_xpm(scene->mlx, parser.elem.we);
	scene->door = get_new_image_xpm(scene->mlx, parser.elem.door);
	scene->full_map = get_new_image(scene->mlx, scene->rows * GRID_UNIT
			+ MMAP_SIZE * GRID_UNIT, scene->cols * GRID_UNIT + MMAP_SIZE
			* GRID_UNIT);
	scene->mmap = get_new_image(scene->mlx, MMAP_SIZE * GRID_UNIT, MMAP_SIZE
			* GRID_UNIT);
	if (scene->screen == NULL || scene->n_wall == NULL || scene->s_wall == NULL
		|| scene->e_wall == NULL || scene->mmap == NULL || scene->w_wall == NULL
		|| scene->full_map == NULL || scene->door == NULL)
	{
		free_data(&parser, &data, scene);
		ft_fprintf(2, ERR_IMG);
		exit(0);
	}
}

void	set_mlx(t_scene *scene, t_parser parser, t_data data)
{
	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
	{
		free_data(&parser, &data, scene);
		exit(0);
	}
	scene->win = mlx_new_window(scene->mlx, scene->width, scene->height,
			"cub3D");
	if (scene->win == NULL)
	{
		free_data(&parser, &data, scene);
		exit(0);
	}
}

void	set_scene(t_scene *scene, t_parser parser, t_data *data)
{

	calc_x_y(data);
	scene->rows = data->rowsy;
	scene->cols = data->colsx;
	scene->width = 1920;
	scene->height = 1080;
	scene->map = padding_map(data->map, &scene->rows, &scene->cols);
	scene->player = set_player(scene->map);
	scene->doors = init_door(scene->map);
	scene->prev_frame = 0;
	set_mlx(scene, parser, *data);
	if (scene->map == NULL)
	{
		free_data(&parser, data, scene);
		mlx_destroy_window(scene->mlx, scene->win);
		exit(0);
	}
	set_scene_image(scene, parser, *data);
}
