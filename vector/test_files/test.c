/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:45:45 by junghwle          #+#    #+#             */
/*   Updated: 2024/03/28 13:59:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_init_vector(void);
void	test_init_matrix_2d(void);
void	test_init_matrix_3d(void);
void	test_sum_vector(void);
void	test_sum_matrix(void);
void	test_sub_vector(void);
void	test_sub_matrix(void);
void	test_dot_vector(void);
void	test_dot_matrix(void);
void	test_scalar_product_vector(void);
void	test_scalar_product_matrix(void);
void	test_dot_mat_vec(void);
void	test_transpose_matrix(void);
void	test_inverse_matrix(void);

int	main(void)
{
	test_init_vector();
	test_init_matrix_2d();
	test_init_matrix_3d();
	test_sum_vector();
	test_sum_matrix();
	test_sub_vector();
	test_sub_matrix();
	test_dot_vector();
	test_dot_matrix();
	test_scalar_product_vector();
	test_scalar_product_matrix();
	test_dot_mat_vec();
	test_transpose_matrix();
	test_inverse_matrix();
	return (0);
}
