/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:33:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "image.h"
# include "player.h"
# include "ray.h"

# define BOX_UNIT 0.75f
# define GRID_UNIT 16
# define WALL_COLOR 0x00964B00
# define PLAYER_COLOR 0x00FFFF00

typedef unsigned int t_uint;

typedef struct s_scene
{
	t_player	player;
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img   	*Nwall;
	t_img		*Swall;
	t_img		*Ewall;
	t_img		*Wwall;
	t_uint		ccolor;
	t_uint		fcolor;
	t_img		*mmap;
}	t_scene;

void	draw(t_scene scene);
void	draw_field(t_scene scene, t_ray ray, int x, double h);

#endif
