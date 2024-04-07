/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 19:19:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "image.h"
# include "player.h"
# include "ray.h"

# define BOX_UNIT 0.75f
# define GRID_UNIT 10
# define WALL_COLOR 0x00808080
# define PLAYER_COLOR 0x00FFFF00
# define MMAP_SIZE 20.0F

typedef unsigned int	t_uint;

typedef struct s_scene
{
	t_player	player;
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img		*n_wall;
	t_img		*s_wall;
	t_img		*e_wall;
	t_img		*w_wall;
	t_uint		ccolor;
	t_uint		fcolor;
	t_img		*full_map;
	t_img		*mmap;
}	t_scene;

void	draw(t_scene scene);
void	draw_field(t_scene scene, t_ray ray, int x, double h);
void	draw_full_map(t_img *full_map, char **map);
void	draw_minimap(t_scene scene, t_ray ray, t_player player);
void	draw_square(t_img *img, t_vec2 pmin, t_vec2 pmax, unsigned int color);
void	draw_triangle(t_img *img, t_vec2 pmin[3], unsigned int color);

#endif
