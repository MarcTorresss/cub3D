/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:09:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:10:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	scale(t_vec2 p, t_vec2 scale)
{
	t_vec2	point;

    point.x = p.x * scale.x;
    point.y = p.y * scale.y;
	return (point);
}