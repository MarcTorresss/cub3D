/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:32:50 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	test_dot_vector(void)
{
	t_vec2	v1;
	t_vec2	v2;
	t_vec3	v3;
	t_vec3	v4;

	printf("Test dot vectors\n");
	v1 = create_vector2d(0, 1);
	v2 = create_vector2d(3, 9);
	printf("val = %.2f\n", dot_vec2(v1, v2));
	v3 = create_vector3d(0, 1, 2);
	v4 = create_vector3d(5, 3, 1);
	printf("val = %.2f\n", dot_vec3(v3, v4));
	printf("\n");
}

void	test_dot_matrix(void)
{
	t_mat2	m1;
	t_mat2	m2;
	t_mat3	m3;
	t_mat3	m4;

	printf("Test dot matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	m2 = create_matrix2d_arr((double []){4, 3}, (double []){2, 1});
	m1 = dot_mat2(m1, m2);
	print_matrix2d(m1);
	m3 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m4 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m3 = dot_mat3(m3, m4);
	print_matrix3d(m3);
	printf("\n");
}

void	test_scalar_product_vector(void)
{
	t_vec2	v1;
	t_vec3	v2;

	printf("Test scalar product vectors\n");
	v1 = create_vector2d(1, 2);
	v1 = scalar_vec2(v1, 3);
	print_vector2d(v1);
	v2 = create_vector3d(2, 4, 8);
	v2 = scalar_vec3(v2, 0.5);
	print_vector3d(v2);
	printf("\n");
}

void	test_scalar_product_matrix(void)
{
	t_mat2	m1;
	t_mat3	m2;

	printf("Test dot matrixes\n");
	m1 = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	m1 = scalar_mat2(m1, 2);
	print_matrix2d(m1);
	m2 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	m2 = scalar_mat3(m2, 1.5);
	print_matrix3d(m2);
	printf("\n");
}

void	test_dot_mat_vec(void)
{
	t_vec2	v1;
	t_mat2	m1;
	t_vec3	v2;
	t_mat3	m2;

	printf("Test dot between mat and vec\n");
	v1 = create_vector2d(2, 4);
	m1 = create_matrix2d_arr((double []){1, 2}, (double []){3, 4});
	v1 = dot_mat2_vec2(m1, v1);
	print_vector2d(v1);
	v2 = create_vector3d(3, 2, 1);
	m2 = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	v2 = dot_mat3_vec3(m2, v2);
	print_vector3d(v2);
	printf("\n");
}
