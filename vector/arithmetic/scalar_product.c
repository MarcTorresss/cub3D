/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:36:46 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 12:46:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	scalar_vec2(t_vec2 v, double nb)
{
	v.x *= nb;
	v.y *= nb;
	return (v);
}

t_vec3	scalar_vec3(t_vec3 v, double nb)
{
	v.x *= nb;
	v.y *= nb;
	v.z *= nb;
	return (v);
}

t_mat2	scalar_mat2(t_mat2 m, double nb)
{
	int	i;

	i = 0;
	while (i < 4)
		m.arr[i++] *= nb;
	return (m);
}

t_mat3	scalar_mat3(t_mat3 m, double nb)
{
	int	i;

	i = 0;
	while (i < 9)
		m.arr[i++] *= nb;
	return (m);
}
