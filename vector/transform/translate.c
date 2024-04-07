/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:09:27 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 20:16:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	translate_vec2(t_vec2 p, t_vec2 dist)
{
	t_vec2	point;

	point = sum_vec2(p, dist);
	return (point);
}
