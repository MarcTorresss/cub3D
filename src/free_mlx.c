/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:42:16 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:50:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "image.h"
#include "mlx.h"
#include <stdlib.h>

static void	free_image(void *mlx, t_img *img)
{
	if (img != NULL)
	{
		mlx_destroy_image(mlx, img->img);
		free(img);
	}
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

void	free_mlx(t_scene *scene)
{
	free_image(scene->mlx, scene->n_wall);
	free_image(scene->mlx, scene->s_wall);
	free_image(scene->mlx, scene->e_wall);
	free_image(scene->mlx, scene->w_wall);
	free_image(scene->mlx, scene->full_map);
	free_image(scene->mlx, scene->mmap);
	free_image(scene->mlx, scene->screen);
	mlx_destroy_window(scene->mlx, scene->win);
	free_map(scene->map);
}