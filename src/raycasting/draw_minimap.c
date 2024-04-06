/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 21:08:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"

void	fill_minimap(t_img *mmap, char **map)
{
	int	i;
	int	j;

	i = 0;
}

void	draw_minimap(t_scene scene, t_ray ray)
{
	static int  instance;

	if (!instance)
		nimap(scene.mmap, scene.map);
}