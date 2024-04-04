/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:31:54 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/27 21:13:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	test_init_vector(void)
{
	t_vec2	v1;
	t_vec3	v2;

	printf("Test init vectors\n");
	v1 = create_vector2d(0, 0);
	print_vector2d(v1);
	v1 = create_vector2d_arr((double []){1, 1});
	print_vector2d(v1);
	v2 = create_vector3d(2, 2, 2);
	print_vector3d(v2);
	v2 = create_vector3d_arr((double []){3, 3, 3});
	print_vector3d(v2);
	v1 = create_vector2d_vec3d(v2);
	print_vector2d(v1);
	v2 = create_vector3d_vec2d(create_vector2d(1, 1));
	print_vector3d(v2);
	printf("\n");
}

void	test_init_matrix_2d(void)
{
	t_mat2	m;

	printf("Test init matrix 2d\n");
	m = create_matrix2d_empty();
	print_matrix2d(m);
	m = create_matrix2d_identity();
	print_matrix2d(m);
	m = create_matrix2d_arr((double []){1, 1}, (double []){2, 2});
	print_matrix2d(m);
	m = create_matrix2d_vec(create_vector2d(0, 1), create_vector2d(2, 3));
	print_matrix2d(m);
	m = create_matrix2d_vec3d(create_vector3d(0, 1, 2), \
								create_vector3d(3, 4, 5));
	print_matrix2d(m);
	printf("\n");
}

void	test_init_matrix_3d(void)
{
	t_mat3	m;

	printf("Test init matrix 3d\n");
	m = create_matrix3d_empty();
	print_matrix3d(m);
	m = create_matrix3d_identity();
	print_matrix3d(m);
	m = create_matrix3d_arr((double []){1, 1, 1}, (double []){2, 2, 2}, \
							(double []){3, 3, 3});
	print_matrix3d(m);
	m = create_matrix3d_vec(create_vector3d(0, 1, 2), create_vector3d(0, 1, 2), \
							create_vector3d(0, 1, 2));
	print_matrix3d(m);
	m = create_matrix3d_vec2d(create_vector2d(0, 1), create_vector2d(2, 3), \
								create_vector2d(4, 5));
	print_matrix3d(m);
	printf("\n");
}
