/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:00:41 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 21:00:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	set_ray(t_ray *ray, t_player player, double width, double x)
{
	double	plane_len;

	plane_len = (x / width) * 2 - 1;
	ray->from = player.pos;
	ray->dir.x = player.dir.x + player.plane.x * plane_len;
	ray->dir.y = player.dir.y + player.plane.y * plane_len;
	ray->p_dir = player.dir;
}
