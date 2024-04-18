/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:13:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "player.h"
# include "door.h"

typedef struct s_ray
{
	t_vec2	from;
	t_vec2	dir;
	t_vec2	p_dir;
	double	perp_dist;
	char	w_dir;
	t_vec2	hpoint;
	int		v_dist;
	t_door	*door;
}	t_ray;

void	set_ray(t_ray *ray, t_player player, double width, double x);

#endif
