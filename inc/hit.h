/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 17:46:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "scene.h"
# include "ray.h"

typedef struct s_hit
{
	char	**map;
	int		mapx;
	int		mapy;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		stepx;
	int		stepy;
	int		rows;
	int		cols;
}	t_hit;

int		hit(t_ray *ray, char **map, int rows, int cols);
int		hit_bonus(t_ray *ray, t_scene scene);
void	record_wall_hit(t_ray *ray, t_hit hit, int side);
int		record_door_hit(t_ray *ray, t_hit hit, int side, t_scene scene);
int		check_door_in_action(t_scene scene, t_ray *ray, t_hit hit, double v);

#endif