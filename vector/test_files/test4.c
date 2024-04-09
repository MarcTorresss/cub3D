/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:59:19 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:01:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	test_transpose_matrix(void)
{
	t_mat2	m1;
	t_mat3	m2;

	printf("Test transpose matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	m1 = transpose_mat2(m1);
	print_matrix2d(m1);
	m2 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m2 = transpose_mat3(m2);
	print_matrix3d(m2);
	printf("\n");
}

void	test_inverse_matrix(void)
{
	t_mat2	m1;
	t_mat2	m2;
	t_mat3	m3;
	t_mat3	m4;

	printf("Test inverse matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 2}, (double []){3, 4});
	m2 = inverse_mat2(m1);
	print_matrix2d(m2);
	m1 = dot_mat2(m1, m2);
	print_matrix2d(m1);
	m3 = create_matrix3d_arr((double []){2, 1, 0}, (double []){1, 2, 1}, \
							(double []){0, 1, 2});
	m4 = inverse_mat3(m3);
	print_matrix3d(m4);
	m3 = dot_mat3(m3, m4);
	print_matrix3d(m3);
	printf("\n");
}
