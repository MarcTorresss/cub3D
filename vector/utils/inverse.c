/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:38:19 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_mat2	inverse_mat2(t_mat2 m1)
{
	t_mat2	m;
	t_mat2	adj;
	double	det;

	det = determinant_mat2(m1);
	if (det == 0)
		return (create_matrix2d_empty());
	det = 1 / det;
	adj = adjacent_mat2(m1);
	m = scalar_mat2(adj, det);
	return (m);
}

t_mat3	inverse_mat3(t_mat3 m1)
{
	t_mat3	m;
	t_mat3	adj;
	double	det;

	det = determinant_mat3(m1);
	if (det == 0)
		return (create_matrix3d_empty());
	det = 1 / det;
	adj = adjacent_mat3(m1);
	m = scalar_mat3(adj, det);
	return (m);
}
