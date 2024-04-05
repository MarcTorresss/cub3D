/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:33:18 by junghwle         ###   ########.fr       */
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
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
}	t_hit;

void	hit(t_ray *ray, char **map);

#endif