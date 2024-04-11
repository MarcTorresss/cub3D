/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:45 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 20:16:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef union u_vec2
{
	double	v[2];
	struct
	{
		double	x;
		double	y;
	};
}	t_vec2;

typedef union u_vec3
{
	double	v[3];
	struct
	{
		double	x;
		double	y;
		double	z;
	};
}	t_vec3;

typedef union u_mat2
{
	double	m[2][2];
	t_vec2	v[2];
	double	arr[4];
}	t_mat2;

typedef union u_mat3
{
	double	m[3][3];
	t_vec3	v[3];
	double	arr[9];
}	t_mat3;

t_vec2	create_vector2d(double x, double y);
t_vec2	create_vector2d_arr(double arr[2]);
t_vec2	create_vector2d_vec3d(t_vec3 v);

t_vec3	create_vector3d(double x, double y, double z);
t_vec3	create_vector3d_arr(double arr[3]);
t_vec3	create_vector3d_vec2d(t_vec2 v);

t_mat2	create_matrix2d_empty(void);
t_mat2	create_matrix2d_identity(void);
t_mat2	create_matrix2d_vec3d(t_vec3 v1, t_vec3 v2);
t_mat2	create_matrix2d_vec(t_vec2 v1, t_vec2 v2);
t_mat2	create_matrix2d_arr(double arr1[2], double arr2[2]);

t_mat3	create_matrix3d_empty(void);
t_mat3	create_matrix3d_identity(void);
t_mat3	create_matrix3d_vec2d(t_vec2 v1, t_vec2 v2, t_vec2 v3);
t_mat3	create_matrix3d_vec(t_vec3 v1, t_vec3 v2, t_vec3 v3);
t_mat3	create_matrix3d_arr(double arr1[3], double arr2[3], double arr3[3]);

t_vec2	sum_vec2(t_vec2 v1, t_vec2 v2);
t_vec3	sum_vec3(t_vec3 v1, t_vec3 v2);
t_mat2	sum_mat2(t_mat2 m1, t_mat2 m2);
t_mat3	sum_mat3(t_mat3 m1, t_mat3 m2);

t_vec2	sub_vec2(t_vec2 v1, t_vec2 v2);
t_vec3	sub_vec3(t_vec3 v1, t_vec3 v2);
t_mat2	sub_mat2(t_mat2 m1, t_mat2 m2);
t_mat3	sub_mat3(t_mat3 m1, t_mat3 m2);

double	dot_vec2(t_vec2 v1, t_vec2 v2);
double	dot_vec3(t_vec3 v1, t_vec3 v2);
t_mat2	dot_mat2(t_mat2 m1, t_mat2 m2);
t_mat3	dot_mat3(t_mat3 m1, t_mat3 m2);
t_vec2	dot_mat2_vec2(t_mat2 m1, t_vec2 v1);
t_vec3	dot_mat3_vec3(t_mat3 m1, t_vec3 v1);

t_vec2	scalar_vec2(t_vec2 v, double nb);
t_vec3	scalar_vec3(t_vec3 v, double nb);
t_mat2	scalar_mat2(t_mat2 m, double nb);
t_mat3	scalar_mat3(t_mat3 m, double nb);

t_mat2	transpose_mat2(t_mat2 m1);
t_mat3	transpose_mat3(t_mat3 m1);

double	length_vec2(t_vec2 v);
double	length_vec3(t_vec3 v);

double	distance_vec2(t_vec2 p1, t_vec2 p2);
double	distance_vec3(t_vec3 p1, t_vec3 p2);

t_vec2	normalize_vec2(t_vec2 v);
t_vec3	normalize_vec3(t_vec3 v);

double	cross_vec2(t_vec2 v1, t_vec2 v2);
t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2);

double	determinant_mat2(t_mat2 m);
double	determinant_mat3(t_mat3 m);

t_mat2	adjacent_mat2(t_mat2 m);
t_mat3	adjacent_mat3(t_mat3 m);

t_mat2	inverse_mat2(t_mat2 m1);
t_mat3	inverse_mat3(t_mat3 m1);

t_vec2	translate_vec2(t_vec2 p, t_vec2 dist);
t_vec2	rotate_vec2(t_vec2 p, double angle);
t_vec2	scale_vec2(t_vec2 p, t_vec2 scale);

void	print_vector2d(t_vec2 v);
void	print_vector3d(t_vec3 v);
void	print_matrix2d(t_mat2 m);
void	print_matrix3d(t_mat3 m);

#endif
