/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:50:36 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 20:56:15 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	print_vector2d(t_vec2 v)
{
	printf("{%.2f, %.2f}\n", v.v[0], v.v[1]);
}

void	print_vector3d(t_vec3 v)
{
	printf("{%.2f, %.2f, %.2f}\n", v.v[0], v.v[1], v.v[2]);
}

void	print_matrix2d(t_mat2 m)
{
	printf("{{%.2f, %.2f},\n", m.arr[0], m.arr[1]);
	printf(" {%.2f, %.2f}}\n", m.arr[2], m.arr[3]);
}

void	print_matrix3d(t_mat3 m)
{
	printf("{{%.2f, %.2f, %.2f},\n", m.arr[0], m.arr[1], m.arr[2]);
	printf(" {%.2f, %.2f, %.2f},\n", m.arr[3], m.arr[4], m.arr[5]);
	printf(" {%.2f, %.2f, %.2f}}\n", m.arr[6], m.arr[7], m.arr[8]);
}
