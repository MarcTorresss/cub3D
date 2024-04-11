/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 21:53:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

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
void	record_wall_hit(t_ray *ray, t_hit hit, int side);
int		record_door_hit(t_ray *ray, t_hit hit, int side);

#endif