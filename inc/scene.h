/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:54:10 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "image.h"
# include "player.h"
# include "ray.h"
# include <stdio.h>

# define BOX_UNIT 0.5f
# define GRID_UNIT 10
# define WALL_COLOR 0x00808080
# define PLAYER_COLOR 0x00FFFF00
# define MMAP_SIZE 20.0F
# define FRQ 0.03f

typedef unsigned int	t_uint;

typedef char	t_byte;

typedef struct s_scene
{
	t_player	player;
	char		**map;
	int			rows;
	int			cols;
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
	t_byte		left_m;
	t_byte		right_m;
	t_vec2		prev_point;
}	t_scene;

int		render(void **pack);

void	draw(t_scene scene);
void	draw_field(t_scene scene, t_ray ray, int x, double h);
void	draw_full_map(t_img *full_map, char **map);
void	draw_minimap(t_scene scene, t_player player);
void	draw_square(t_img *img, t_vec2 pmin, t_vec2 pmax, t_uint color);
void	draw_triangle(t_img *img, t_vec2 vertices[3], t_uint color);

void	free_mlx(t_scene *scene);

#endif
