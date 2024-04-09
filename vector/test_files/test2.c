/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:32:50 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:08:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	test_sum_vector(void)
{
	t_vec2	v1;
	t_vec2	v2;
	t_vec3	v3;
	t_vec3	v4;

	printf("Test sum vectors\n");
	v1 = create_vector2d(0, 1);
	v2 = create_vector2d(3, 9);
	v1 = sum_vec2(v1, v2);
	print_vector2d(v1);
	v3 = create_vector3d(0, 1, 2);
	v4 = create_vector3d(5, 3, 1);
	v3 = sum_vec3(v3, v4);
	print_vector3d(v3);
	printf("\n");
}

void	test_sum_matrix(void)
{
	t_mat2	m1;
	t_mat2	m2;
	t_mat3	m3;
	t_mat3	m4;

	printf("Test sum matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	m2 = create_matrix2d_arr((double []){4, 3}, (double []){2, 1});
	m1 = sum_mat2(m1, m2);
	print_matrix2d(m1);
	m3 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m4 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m3 = sum_mat3(m3, m4);
	print_matrix3d(m3);
	printf("\n");
}

void	test_sub_vector(void)
{
	t_vec2	v1;
	t_vec2	v2;
	t_vec3	v3;
	t_vec3	v4;

	printf("Test sub vectors\n");
	v1 = create_vector2d(0, 1);
	v2 = create_vector2d(3, 9);
	v1 = sub_vec2(v1, v2);
	print_vector2d(v1);
	v3 = create_vector3d(0, 1, 2);
	v4 = create_vector3d(5, 3, 1);
	v3 = sub_vec3(v3, v4);
	print_vector3d(v3);
	printf("\n");
}

void	test_sub_matrix(void)
{
	t_mat2	m1;
	t_mat2	m2;
	t_mat3	m3;
	t_mat3	m4;

	printf("Test sub matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	m2 = create_matrix2d_arr((double []){4, 3}, (double []){2, 1});
	m1 = sub_mat2(m1, m2);
	print_matrix2d(m1);
	m3 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m4 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m3 = sub_mat3(m3, m4);
	print_matrix3d(m3);
	printf("\n");
}
