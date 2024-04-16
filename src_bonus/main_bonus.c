/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/16 17:17:19 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"
#include <mlx.h>
#include <stdlib.h>

void	set_scene(t_scene *scene, t_parser parser, t_data data);

int	main(int argc, char **argv)
{
	t_data		data;
	t_parser	parser;
	t_scene		scene;
	t_keys		keys;

	if (argc != 2)
		return (ft_fprintf(2, "Bad arguments :\\\n"), 2);
	parser_init(argv[1], &parser);
	if (parser.file == NULL)
		return (free_parser(&parser), 1);
	if (check_elements_bonus(&parser, &scene) == 1)
		return (ft_fprintf(2, ERR_FILE), free_parser(&parser), 1);
	if (init_map(&data, &parser) == 1)
		return (ft_fprintf(2, ERR_MAP), free_data(&parser, &data, &scene), 1);
	set_scene(&scene, parser, data);
	if (check_map_bonus(&parser, scene))
	{
		ft_fprintf(2, ERR_MAP);
		free_data(&parser, &data, &scene);
		exit(0);
	}
	ft_memset(&keys, 0, sizeof(t_keys));
	listen_input(&scene, &keys);
	mlx_loop_hook(scene.mlx, render, (void *[]){&scene, &keys});
	mlx_loop(scene.mlx);
}
