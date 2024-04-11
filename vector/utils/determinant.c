/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:32:29 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 13:36:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	determinant_mat2(t_mat2 m)
{
	double	res;

	res = m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0];
	return (res);
}

double	determinant_mat3(t_mat3 m)
{
	double	res;

	res = m.m[0][0] * m.m[1][1] * m.m[2][2] + \
			m.m[0][1] * m.m[1][2] * m.m[2][0] + \
			m.m[0][2] * m.m[1][0] * m.m[2][1] - \
			m.m[0][2] * m.m[1][1] * m.m[2][0] - \
			m.m[0][1] * m.m[1][0] * m.m[2][2] - \
			m.m[0][0] * m.m[1][2] * m.m[2][1];
	return (res);
}
