/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:45:46 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/06 03:14:26 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	is_point(t_tuple t)
{
	return (t.w == 1.0);
}

bool	is_vector(t_tuple t)
{
	return (t.w == 0.0);
}


void round_matrix(t_matrix *m)
{
	int i, j;
	for (i = 0; i < m->size; i++) 
	{
		for (j = 0; j < m->size; j++) 
		{
			m->grid[i][j] = roundf(m->grid[i][j] * 1e5) / 1e5;
		}
	}
}

	
int	main(void)
{
	// t_tuple a = {atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])};
	t_tuple a = {4.3, -4.2, 3.1, 1.0};
	t_tuple b = {4.3, -4.2, 3.1, 0.0};
	
	printf("\033[1;35mchecking point/vector\033[0m\n");
	if (is_point(a))
		printf("t_tuple a = {4.3, -4.2, 3.1, 1.0} is a point\n");
	if (is_point(b))
		printf("t_tuple b = {4.3, -4.2, 3.1, 0.0} is not a point\n");
	if (is_vector(a))
		printf("t_tuple a = {4.3, -4.2, 3.1, 1.0} is not a vector\n");
	if (is_vector(b))
		printf("t_tuple b = {4.3, -4.2, 3.1, 0.0} is a vector\n");
	
	printf("\n\033[1;35mchecking create points/vector\033[0m");
	t_tuple p = create_point(4, -4, 3);
		printf("\npoint: x %f, y %f, z %f, w %f\n", p.x, p.y, p.z, p.w);
	t_tuple v = create_vector(4, -4, 3);
		printf("vector: x %f, y %f, z %f, w %f\n\n", v.x, v.y, v.z, v.w);
	
	printf("\033[1;35mchecking if tuples are equals\033[0m\n");
	if (check_tuple_equality(a, b))
		printf("a and b are equal\n");
	else
		printf("a and b are not equal\n");

	printf("\n\033[1;35madding tuples\033[0m\n");
	t_tuple a1 = {3, -2, 5, 1};
	t_tuple a2 = {-2, 3, 1, 0};
	t_tuple expect = {1, 1, 6, 1};
	t_tuple result = add_tuples(a1, a2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect.x, expect.y, expect.z, expect.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result.x, result.y, result.z, result.w);
	if (check_tuple_equality(expect, result))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
		
	printf("\n\033[1;35msubtracting a vector from a point\033[0m\n");
	t_tuple p1 = {3, 2, 1, 1};
	t_tuple p2 = {5, 6, 7, 1};
	t_tuple expect_s = {-2, -4, -6};
	t_tuple result_s = subtract_tuples(p1, p2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_s.x, expect_s.y, expect_s.z, expect_s.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_s.x, result_s.y, result_s.z, result_s.w);
	if (check_tuple_equality(expect_s, result_s))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
	
	printf("\n\033[1;35mSubtracting a vector from a point\033[0m\n");
	t_tuple point = {3, 2, 1, 1};
	t_tuple vector = {5, 6, 7, 0};
	t_tuple expect_r = {-2, -4, -6, 1};
	t_tuple result_r = subtract_tuples(point, vector);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_r.x, expect_r.y, expect_r.z, expect_r.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_r.x, result_r.y, result_r.z, result_r.w);
	if (check_tuple_equality(expect_r, result_r))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
		
	printf("\n\033[1;35msubtracting two vectors\033[0m\n");
	t_tuple v1 = {3, 2, 1, 0};
	t_tuple v2 = {5, 6, 7, 0};
	t_tuple expect_v = {-2, -4, -6};
	t_tuple result_v = subtract_tuples(v1, v2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_v.x, expect_v.y, expect_v.z, expect_v.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_v.x, result_v.y, result_v.z, result_v.w);
	if (check_tuple_equality(expect_v, result_v))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mSubtracting a vector from the zero vector\033[0m\n");
	t_tuple zero = {0, 0, 0, 0};
	t_tuple vzero = {1, -2, 3, 0};
	t_tuple expect_z = {-1, 2, -3};
	t_tuple result_z = subtract_tuples(zero, vzero);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_z.x, expect_z.y, expect_z.z, expect_z.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_z.x, result_z.y, result_z.z, result_z.w);
	if (check_tuple_equality(expect_z, result_z))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mNegating a tuple\033[0m\n");
	t_tuple neg = {1, -2, 3, -4};
	t_tuple expect_n = {-1, 2, -3, 4};
	t_tuple result_n = deny_tuples(neg);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_n.x, expect_n.y, expect_n.z, expect_n.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_n.x, result_n.y, result_n.z, result_n.w);
	if (check_tuple_equality(expect_n, result_n))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mMultiplying a tuple by a scalar\033[0m\n");
	double scalar = 3.5;
	t_tuple m = {1, -2, 3, -4};
	t_tuple expect_m = {3.5, -7, 10.5, -14};
	t_tuple result_m = multiply_tuples_scalar(m, scalar);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_m.x, expect_m.y, expect_m.z, expect_m.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_m.x, result_m.y, result_m.z, result_m.w);
	if (check_tuple_equality(expect_m, result_m))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mMultiplying a tuple by a fraction\033[0m\n");
	double fr = 0.5;
	t_tuple frac = {1, -2, 3, -4};
	t_tuple expect_f = {0.5, -1, 1.5, -2};
	t_tuple result_f = multiply_tuples_scalar(frac, fr);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_f.x, expect_f.y, expect_f.z, expect_f.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_f.x, result_f.y, result_f.z, result_f.w);
	if (check_tuple_equality(expect_f, result_f))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mDividing a tuple by a scalar\033[0m\n");
	double div = 2;
	t_tuple dividend = {1, -2, 3, -4};
	t_tuple expect_div = {0.5, -1, 1.5, -2};
	t_tuple result_div = divide_tuple_scalar(dividend, div);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_div.x, expect_div.y, expect_div.z, expect_div.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_div.x, result_div.y, result_div.z, result_div.w);
	if (check_tuple_equality(expect_div, result_div))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
	
	printf("\n\033[1;35mComputing the magnitude of vector\033[0m\n");
	
	t_tuple mag0 = {1, 0, 0, 0};
	t_tuple mag1 = {0, 1, 0, 0};
	t_tuple mag2 = {0, 0, 1, 0};
	t_tuple mag3 = {1, 2, 3, 0};
	t_tuple mag4 = {-1, -2, -3, 0};
	
	double	expect_mag0 = 1;
	double	mag0_v = vector_magnitude(mag0);
	printf ("expect: %.1f\n", expect_mag0);
	printf ("result: %.1f\n", mag0_v);
	if (fabs(expect_mag0 - mag0_v ) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	double	expect_mag1 = 1;
	double	mag1_v = vector_magnitude(mag1);
	printf ("expect: %.1f\n", expect_mag1);
	printf ("result: %.1f\n", mag1_v);
	if (fabs(expect_mag1 - mag1_v ) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	double	expect_mag2 = 1;
	double	mag2_v = vector_magnitude(mag2);
	printf ("expect: %.1f\n", expect_mag2);
	printf ("result: %.1f\n", mag2_v);
	if (fabs(expect_mag2 - mag2_v ) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	double	expect_mag3 = sqrt(14);
	double	mag3_v = vector_magnitude(mag3);
	printf ("expect: %.1f\n", expect_mag3);
	printf ("result: %.1f\n", mag3_v);
	if (fabs(expect_mag3 - mag3_v ) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	double	expect_mag4 = sqrt(14);
	double	mag4_v = vector_magnitude(mag4);
	printf ("expect: %.1f\n", expect_mag4);
	printf ("result: %.1f\n", mag4_v);
	if (fabs(expect_mag4 - mag4_v ) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");	


	printf("\n\033[1;35mNormalizing vector\033[0m\n");
	t_tuple	vec_n = {4, 0, 0, 0};
	t_tuple	expec_n = {1, 0, 0, 0};
	t_tuple	res_n = vector_norm(vec_n);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expec_n.x, expec_n.y, expec_n.z, expec_n.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", res_n.x, res_n.y, res_n.z, res_n.w);
	if (check_tuple_equality(expec_n, res_n))
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");

	t_tuple	vec_n1 = {1, 2, 3, 0};
	t_tuple	expec_n1 = {1/sqrt(14), 2/sqrt(14), 3/sqrt(14), 0};
	t_tuple	res_n1 = vector_norm(vec_n1);
	printf ("expect: %f, %f, %f, %f\n", expec_n1.x, expec_n1.y, expec_n1.z, expec_n1.w);
	printf ("result: %f, %f, %f, %f\n", res_n1.x, res_n1.y, res_n1.z, res_n1.w);
	if (check_tuple_equality(expec_n1, res_n1))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
	
	
	printf("\n\033[1;35mThe magnitude of a normalized vector\033[0m\n");
	t_tuple	vec_nm = {1, 2, 3, 0};
	t_tuple	norm = vector_norm(vec_nm);
	double	expec_norm_m = 1;
	double	res_norm_m = vector_magnitude(norm);
	printf ("expect: %.1f\n", expec_norm_m);
	printf ("result: %.1f\n", res_norm_m);
	if (fabs(expec_norm_m - res_norm_m) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	printf("\n\033[1;35mThe dot product of two tuples\033[0m\n");
	t_tuple	d1 = {1, 2, 3, 0};
	t_tuple	d2 = {2, 3, 4, 0};
	double	expec_dp = 20;
	double	res_dp = dot_product(d1, d2);
	printf ("expect: %.1f\n", expec_dp);
	printf ("result: %.1f\n", res_dp);
	if (fabs(expec_dp - res_dp) < EPSILON)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mThe cross product of two vectors\033[0m\n");
	t_tuple	v_cp = {1, 2, 3, 0};
	t_tuple	v_cp1 = {2, 3, 4, 0};
	t_tuple	expec_cp_ab = {-1, 2, -1, 0};
	t_tuple	res_cp_ab = cross_product(v_cp, v_cp1);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expec_cp_ab.x, expec_cp_ab.y, expec_cp_ab.z, expec_cp_ab.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", res_cp_ab.x, res_cp_ab.y, res_cp_ab.z, res_cp_ab.w);
	if (check_tuple_equality(expec_cp_ab, res_cp_ab))
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");

	t_tuple	expec_cp_ba = {1, -2, 1, 0};
	t_tuple	res_cp_ba = cross_product(v_cp1, v_cp);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expec_cp_ba.x, expec_cp_ba.y, expec_cp_ba.z, expec_cp_ba.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", res_cp_ba.x, res_cp_ba.y, res_cp_ba.z, res_cp_ba.w);
	if (check_tuple_equality(expec_cp_ba, res_cp_ba))
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");

	
	printf("\n\033[1;35mConstructing and inspecting a 4x4 matrix\033[0m\n");
	double mat_result[] = {1.0, 2.0, 3.0, 4.0, 5.5, 6.5, 7.5, 8.5 , 9.0, 10.0, 11.0, 12.0, 13.5, 14.5, 15.5, 16.5};
	double mat_expect[4][4] = {
	{1.0, 2.0, 3.0, 4.0},
	{5.5, 6.5, 7.5, 8.5},
	{9.0, 10.0, 11.0, 12.0},
	{13.5, 14.5, 15.5, 16.5}};
	t_matrix matrix = create_matrix(4, mat_result);
	printf("expect: matrix[0][0]: %.2f\n", mat_expect[0][0]);
	printf("result: matrix[0][0]: %.2f\n", matrix.grid[0][0]);
	if (fabs(mat_expect[0][0] - matrix.grid[0][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[0][3]: %.2f\n", mat_expect[0][3]);
	printf("result: matrix[0][3]: %.2f\n", matrix.grid[0][3]);
	if (fabs(mat_expect[0][3] - matrix.grid[0][3]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[1][0]: %.2f\n", mat_expect[1][0]);
	printf("result: matrix[1][0]: %.2f\n", matrix.grid[1][0]);
	if (fabs(mat_expect[1][0] - matrix.grid[1][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[1][2]: %.2f\n", mat_expect[1][2]);
	printf("result: matrix[1][2]: %.2f\n", matrix.grid[1][2]);
	if (fabs(mat_expect[1][2] - matrix.grid[1][2]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[2][2]: %.2f\n", mat_expect[2][2]);
	printf("result: matrix[2][2]: %.2f\n", matrix.grid[2][2]);
	if (fabs(mat_expect[2][2] - matrix.grid[2][2]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[3][0]: %.2f\n", mat_expect[3][0]);
	printf("result: matrix[3][0]: %.2f\n", matrix.grid[3][0]);
	if (fabs(mat_expect[3][0] - matrix.grid[3][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[3][2]: %.2f\n", mat_expect[3][2]);
	printf("result: matrix[3][2]: %.2f\n", matrix.grid[3][2]);
	if (fabs(mat_expect[3][2] - matrix.grid[3][2]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	
	printf("\n\033[1;35mA 2x2 matrix ought to be representable\033[0m\n");
	double mat_expec[2][2] = {
	{-3, 5,},
	{1, -2}
	};
	double mat_res[] = {-3, 5, 1, -2};
	t_matrix matrix1 = create_matrix(2, mat_res);
	printf("expect: matrix[0][0]: %.2f\n", mat_expec[0][0]);
	printf("result: matrix[0][0]: %.2f\n", matrix1.grid[0][0]);
	if (fabs(mat_expec[0][0] - matrix1.grid[0][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[0][1]: %.2f\n", mat_expec[0][1]);
	printf("result: matrix[0][1]: %.2f\n", matrix1.grid[0][1]);
	if (fabs(mat_expec[0][1] - matrix1.grid[0][1]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[1][0]: %.2f\n", mat_expec[1][0]);
	printf("result: matrix[1][0]: %.2f\n", matrix1.grid[1][0]);
	if (fabs(mat_expec[1][0] - matrix1.grid[1][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[1][1]: %.2f\n", mat_expec[1][1]);
	printf("result: matrix[1][1]: %.2f\n", matrix1.grid[1][1]);
	if (fabs(mat_expec[1][1] - matrix1.grid[1][1]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	

	printf("\n\033[1;35mA 3x3 matrix ought to be representable\033[0m\n");
	double mat_e[3][3] = {
	{-3, 5, 0},
	{1, -2, -7},
	{0, 1, 1}
	};
	double mat_r[] = {-3, 5, 0, 1, -2, -7, 0, 1, 1};
	t_matrix matrix2 = create_matrix(3, mat_r);
	printf("expect: matrix[0][0]: %.2f\n", mat_e[0][0]);
	printf("result: matrix[0][0]: %.2f\n", matrix2.grid[0][0]);
	if (fabs(mat_e[0][0] - matrix2.grid[0][0]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[1][1]: %.2f\n", mat_e[1][1]);
	printf("result: matrix[1][1]: %.2f\n", matrix2.grid[1][1]);
	if (fabs(mat_e[1][1] - matrix2.grid[1][1]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	printf("expect: matrix[2][2]: %.2f\n", mat_e[2][2]);
	printf("result: matrix[2][2]: %.2f\n", matrix2.grid[2][2]);
	
	if (fabs(mat_e[2][2] - matrix2.grid[2][2]) < EPSILON)
		printf("\33[1;32mOK\033[0m\n\n");
	else
		printf("\33[1;31mFAIL\033[0m\n\n");
	quick_test_double(init_instance_default(NULL), mat_e[2][2], matrix2.grid[2][2]);
	

	printf("\n\033[1;35mMatrix equality with identical matrices\033[0m\n");
	double mat_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	double mat_b[] = {1, 2, 3, 4 ,5, 6, 7, 8 ,9, 8, 7, 6 ,5, 4, 3, 2};
	t_matrix matrix_a = create_matrix(4, mat_a);
	t_matrix matrix_b = create_matrix(4, mat_b);
	if (matrix_equality(matrix_a, matrix_b))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");

	printf("\n\033[1;35mMatrix equality with different matrices\033[0m\n");
	double mat_a1[] = {1, 2, 3, 4,5, 6, 7, 8,9, 8, 7, 6,5, 4, 3, 2};
	double mat_b1[] = {2, 3, 4, 5,6, 7, 8, 9,8, 7, 6, 5,4, 3, 2, 1};
	t_matrix matrix_a1 = create_matrix(4, mat_a1);
	t_matrix matrix_b1 = create_matrix(4, mat_b1);
	if (!matrix_equality(matrix_a1, matrix_b1))
		printf("\33[1;32mOK\nA != B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA = B\033[0m\n");

	printf("\n\033[1;35mMultiplying two matrices\033[0m\n");
	double mat_m1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	double mat_m2[] = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};
	t_matrix	matrix_m1 = create_matrix(4,mat_m1);
	t_matrix	matrix_m2 = create_matrix(4,mat_m2);
	t_matrix	result_mm = multiply_matrices(matrix_m1, matrix_m2);
	double		expec_mm[] = {20, 22, 50, 48, 44, 54, 114, 108 , 40, 58, 110, 102, 16, 26, 46, 42};
	t_matrix	expect_mm = create_matrix(4, expec_mm);
	if (matrix_equality(result_mm, expect_mm))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");


	printf("\n\033[1;35mMultiplying two matrices- exemple 2\033[0m\n");
	double exp1[] = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7};
	double exp2[] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};
	t_matrix	matrix_exp1 = create_matrix(4, exp1);
	t_matrix	matrix_exp2 = create_matrix(4, exp2);
	t_matrix	result_exp = multiply_matrices(matrix_exp1, matrix_exp2);
	double		expec_exp[] = {24, 49, 98, 196, 31, 64, 128, 256, 38, 79, 158, 316, 45, 94, 188, 376};
	t_matrix	expect_exp = create_matrix(4, expec_exp);
	printf("expect: matrix[1][0]: %.2f\n", expect_exp.grid[1][0]);
	printf("result: matrix[1][0]: %.2f\n", result_exp.grid[1][0]);
	if (matrix_equality(result_exp, expect_exp))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");

	printf("\n\033[1;35mA matrix multiplied by a tuple\033[0m\n");
	double mp[] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
	t_tuple	tup = {1, 2, 3, 1};
	t_matrix	matrix_mp = create_matrix(4, mp);
	t_tuple	result_mp = multiply_matrix_by_tuple(matrix_mp, tup);
	t_tuple	expect_mp = {18, 24, 33, 1};
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_mp.x, expect_mp.y, expect_mp.z, expect_mp.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_mp.x, result_mp.y, result_mp.z, result_mp.w);
	if (check_tuple_equality(expect_mp, result_mp))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mMultiplying a matrix by the identity matrix\033[0m\n");
	double id[] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};
	t_matrix	matrix_id = create_matrix(4, id);
	t_matrix	matrix_identity = create_matrix_identity(4);
	t_matrix	result_id = multiply_matrices(matrix_id, matrix_identity);
	if (matrix_equality(result_id, matrix_id))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");


	printf("\n\033[1;35mMultiplying the identity matrix by a tuple\033[0m\n");

	t_tuple		tup_id = {1, 2, 3, 4};
	t_tuple		expect_idt = tup_id;
	t_tuple		result_idt = multiply_matrix_id_by_tuple(tup_id);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_idt.x, expect_idt.y, expect_idt.z, expect_idt.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_idt.x, result_idt.y, result_idt.z, result_idt.w);
	if (check_tuple_equality(expect_idt, result_idt))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mTransposing a matrix\033[0m\n");
	double tr1[] = {0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8};
	double expec_tr2[] = {0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8};
	t_matrix	matrix_tr1 = create_matrix(4, tr1);
	t_matrix	matrix_expec_tr2 = create_matrix(4, expec_tr2);
	t_matrix	result_tr2 = transpose_matrix(matrix_tr1);
	if (matrix_equality(result_tr2, matrix_expec_tr2))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");


	printf("\n\033[1;35mTransposing the identity matrix\033[0m\n");
	t_matrix	matrix_tr_id = create_matrix_identity(4);
	t_matrix	result_tr_id = transpose_matrix(matrix_tr_id);
	if (matrix_equality(result_tr_id, matrix_tr_id))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");


	printf("\n\033[1;35mCalculating the determinant of a 2x2 matrix\033[0m\n");
	double det2[] = {1, 5, -3, 2};
	t_matrix	matrix_det2 = create_matrix(2, det2);
	double	result_det2 = calc_determinant(2, matrix_det2);
	double	expect_det2 = 17.0;
	if (fabs(result_det2 - expect_det2) < EPSILON)
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");


	printf("\n\033[1;35mA submatrix of a 3x3 matrix is a 2x2 matrix\033[0m\n");
	double sub1[] = {1, 5, 0, -3, 2, 7, 0, 6, -3};
	double expec_sub[] = {-3, 2, 0, 6};
	t_matrix	matrix_sub1 = create_matrix(3, sub1);
	t_matrix	matrix_expec_sub = create_matrix(2, expec_sub);
	t_matrix	result_sub = create_submatrix(matrix_sub1, 0, 2);
	if (matrix_equality(result_sub, matrix_expec_sub ))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");
	
	printf("\n\033[1;35mA submatrix of a 4x4 matrix is a 3x3 matrix\033[0m\n");
	double sub2[] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};
	double expec_sub1[] = {-6, 1, 6, -8, 8, 6, -7, -1, 1};
	t_matrix	matrix_sub2 = create_matrix(4, sub2);
	t_matrix	matrix_expec_sub1= create_matrix(3, expec_sub1);
	t_matrix	result_sub1 = create_submatrix(matrix_sub2, 2, 1);
	if (matrix_equality(result_sub1, matrix_expec_sub1))
		printf("\33[1;32mOK\nA = B \033[0m\n");
	else
		printf("\33[1;31mFAIL\nA != B\033[0m\n");
	


	printf("\n\033[1;35mCalculating a minor of a 3x3 matrix\033[0m\n");
	double		minor_a[] = {3, 5, 0, 2, -1, -7, 6, -1, 5};
	t_matrix	matrix_minor_a = create_matrix(3, minor_a);
	t_matrix	sub_minor_a = create_submatrix(matrix_minor_a, 1, 0);
	double		det_minor_a = calc_determinant(2, sub_minor_a);
	double	result_minor_a = calc_minor(matrix_minor_a.size, matrix_minor_a, 1, 0);
	printf("expect: %.1f\n", det_minor_a);
	printf("result: %.1f\n", result_minor_a);
	if (fabs(det_minor_a - result_minor_a) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");


	printf("\n\033[1;35mCalculating a cofactor of a 3x3 matrix\033[0m\n");
	double		cof_a[] = {3, 5, 0, 2, -1, -7, 6, -1, 5};
	t_matrix	matrix_cof_a = create_matrix(3, cof_a);
	double		expect_minor_cof_a = -12;
	double		minor_cof_a = calc_minor(matrix_cof_a.size, matrix_cof_a, 0, 0);
	
	double		expect_cof_a = -12;
	double		result_cof_a = cofactor(matrix_cof_a.size, matrix_cof_a, 0, 0);	
	
	double		expect_minor_cof_a1 = 25;
	double		minor_cof_a1 = calc_minor(matrix_cof_a.size, matrix_cof_a, 1, 0);
	double		expect_cof_a1 = -25;
	double		result_cof_a1 = cofactor(matrix_cof_a.size, matrix_cof_a, 1, 0);
	printf("expect minor (A, 0, 0): %.1f\n", expect_minor_cof_a);
	printf("result minor (A, 0, 0): %.1f\n", minor_cof_a);
	printf("expect cofactor (A, 0, 0): %.1f\n", expect_cof_a);
	printf("result cofactor (A, 0, 0): %.1f\n", result_cof_a);
	printf("expect minor (A, 1, 0): %.1f\n", expect_minor_cof_a1);
	printf("result minor (A, 1, 0): %.1f\n", minor_cof_a1);
	printf("expect cofactor (A, 1, 0): %.1f\n", expect_cof_a1);
	printf("result cofactor (A, 1, 0): %.1f\n", result_cof_a1);

	if (fabs(expect_minor_cof_a - result_cof_a) < EPSILON && fabs(expect_minor_cof_a1 - minor_cof_a1) < EPSILON && fabs(expect_cof_a1 - result_cof_a1) < EPSILON && fabs(expect_cof_a - result_cof_a) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");


	printf("\n\033[1;35mCalculating the determinant of a 3x3 matrix\033[0m\n");
	double		det_3[] = {1, 2, 6, -5, 8, -4, 2, 6, 4};
	t_matrix	matrix_det_3 = create_matrix(3, det_3);
	double		cof_3_0 = cofactor(matrix_det_3.size, matrix_det_3, 0, 0);
	double		expec_cof_3_0 = 56;
	double		cof_3_1 = cofactor(matrix_det_3.size, matrix_det_3, 0, 1);
	double		expec_cof_3_1 = 12;
	double		cof_3_2 = cofactor(matrix_det_3.size, matrix_det_3, 0, 2);
	double		expec_cof_3_2 = -46;
	double		det_3_0 = calc_determinant(3, matrix_det_3);
	double		expec_det_3_0 = -196;

	printf("expect cofactor (A, 0, 0): %.1f\n", expec_cof_3_0);
	printf("result cofactor (A, 0, 0): %.1f\n", cof_3_0);
	printf("expect cofactor (A, 0, 1): %.1f\n", expec_cof_3_1);
	printf("result cofactor (A, 0, 1): %.1f\n", cof_3_1);
	printf("expect cofactor (A, 0, 2): %.1f\n", expec_cof_3_2);
	printf("result cofactor (A, 0, 2): %.1f\n", cof_3_2);
	printf("expect determinant A: %.1f\n", expec_det_3_0);
	printf("result determinant A: %.1f\n", det_3_0);

	if (fabs(expec_cof_3_0 - cof_3_0) < EPSILON && fabs(expec_cof_3_1 - cof_3_1) < EPSILON && fabs(expec_cof_3_2 - cof_3_2) < EPSILON && fabs(expec_det_3_0 - det_3_0) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");
	


	printf("\n\033[1;35mCalculating the determinant of a 4x4 matrix\033[0m\n");
	double	det_4[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
	t_matrix	matrix_det_4 = create_matrix(4, det_4);
	double		cof_4_0 = cofactor(matrix_det_4.size, matrix_det_4, 0, 0);
	double		expec_cof_4_0 = 690;
	double		cof_4_1 = cofactor(matrix_det_4.size, matrix_det_4, 0, 1);
	double		expec_cof_4_1 = 447;
	double		cof_4_2 = cofactor(matrix_det_4.size, matrix_det_4, 0, 2);
	double		expec_cof_4_2 = 210;
	double		cof_4_3 = cofactor(matrix_det_4.size, matrix_det_4, 0, 3);
	double		expec_cof_4_3 = 51;
	double		det_4_0 = calc_determinant(4, matrix_det_4);
	double		expec_det_4_0 = -4071;

	printf("expect cofactor (A, 0, 0): %.1f\n", expec_cof_4_0);
	printf("result cofactor (A, 0, 0): %.1f\n", cof_4_0);
	printf("expect cofactor (A, 0, 1): %.1f\n", expec_cof_4_1);
	printf("result cofactor (A, 0, 1): %.1f\n", cof_4_1);
	printf("expect cofactor (A, 0, 2): %.1f\n", expec_cof_4_2);
	printf("result cofactor (A, 0, 2): %.1f\n", cof_4_2);
	printf("expect cofactor (A, 0, 3): %.1f\n", expec_cof_4_3);
	printf("result cofactor (A, 0, 3): %.1f\n", cof_4_3);
	printf("expect determinant A: %.1f\n", expec_det_4_0);
	printf("result determinant A: %.1f\n", det_4_0);
	

	if (fabs(expec_cof_4_0 - cof_4_0) < EPSILON && fabs(expec_cof_4_1 - cof_4_1) < EPSILON && fabs(expec_cof_4_2 - cof_4_2) < EPSILON && fabs(expec_cof_4_3 - cof_4_3) < EPSILON && fabs(expec_det_4_0 - det_4_0) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");


	printf("\n\033[1;35mTesting an invertible matrix for invertibility\033[0m\n");
	double	inv[] = {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6};
	t_matrix	matrix_inv = create_matrix(4, inv);
	double	det_inv = calc_determinant(4, matrix_inv);
	double	expec_det_inv = -2120;
	printf("expect determinant A: %.1f\n", expec_det_inv);
	printf("result determinant A: %.1f\n", det_inv);
	printf("\33[1;32mA is invertible\n\033[0m");
	if (fabs(det_inv - expec_det_inv) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");

	printf("\n\033[1;35mTesting a noninvertible matrix for invertibility\033[0m\n");
	double	noninv[] = {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0};
	t_matrix	matrix_noninv = create_matrix(4, noninv);
	double	det_noninv = calc_determinant(4, matrix_noninv);
	double	expec_det_noninv = 0;
	printf("expect determinant A: %.1f\n", expec_det_noninv);
	printf("result determinant A: %.1f\n", det_noninv);
	printf("\33[1;32mA is not invertible\n\033[0m");
	if (fabs(det_noninv - expec_det_noninv) < EPSILON)
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");

	printf("\033[1;33m\033[4mDeterminant != 0: matrix is invertible\nDeterminant == 0: matrix is not invertible\n\033[0m");


	printf("\n\033[1;35mCalculating the inverse of a matrix\033[0m\n");
	double	inv1[] = {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};
	t_matrix	matrix_inv1 = create_matrix(4, inv1);
	t_matrix	inverse_inv1 = calc_inverse_matrix(matrix_inv1);
	round_matrix(&inverse_inv1);
	double		det_inv1 = calc_determinant(4, matrix_inv1);
	double		expec_det_inv1 = 532;
	printf("expect determinant A: %.1f\n", expec_det_inv1);
	printf("result determinant A: %.1f\n", det_inv1);
	double		cof_inv1_0 = cofactor(matrix_inv1.size, matrix_inv1, 2, 3);
	double		expec_cof_inv1_0 = -160;
	printf("Expect cofactor A[2,3] = %.1f\n", expec_cof_inv1_0);
	printf("Result cofactor A[2,3] = %.1f\n", cof_inv1_0);
	printf("Expect B[3,2] = %.1f\n", -160.0 / 532.0);
	printf("Result B[3,2] = %.1f\n", inverse_inv1.grid[3][2]);
	double		cof_inv1_1 = cofactor(matrix_inv1.size, matrix_inv1, 3, 2);
	double		expec_cof_inv1_1 = 105;
	printf("Expect cofactor A[3,2] = %.1f\n", expec_cof_inv1_1);
	printf("Result cofactor A[3,2] = %.1f\n", cof_inv1_1);
	printf("Expect B[2,3] = %.1f\n", 105.0 / 532.0);
	printf("Result B[2,3] = %.1f\n", inverse_inv1.grid[2][3]);
	double		expect_inverse_inv1[] = {0.21805, 0.45113, 0.24060, -0.04511, -0.80827, -1.45677, -0.44361, 0.52068, -0.07895, -0.22368, -0.05263, 0.19737, -0.52256, -0.81391, -0.30075, 0.30639};
	t_matrix	expect_inv_inv1 = create_matrix(4, expect_inverse_inv1);
	printf("expect line 0: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv1.grid[0][0], expect_inv_inv1.grid[0][1], expect_inv_inv1.grid[0][2], expect_inv_inv1.grid[0][3]);
	printf("result line 0: %.5f, %.5f, %.5f, %.5f\n", inverse_inv1.grid[0][0], inverse_inv1.grid[0][1], inverse_inv1.grid[0][2], inverse_inv1.grid[0][3]);
	printf("expect line 1: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv1.grid[1][0], expect_inv_inv1.grid[1][1], expect_inv_inv1.grid[1][2], expect_inv_inv1.grid[1][3]);
	printf("result line 1: %.5f, %.5f, %.5f, %.5f\n", inverse_inv1.grid[1][0], inverse_inv1.grid[1][1], inverse_inv1.grid[1][2], inverse_inv1.grid[1][3]);
	
	printf("expect line 2: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv1.grid[2][0], expect_inv_inv1.grid[2][1], expect_inv_inv1.grid[2][2], expect_inv_inv1.grid[2][3]);
	printf("result line 2: %.5f, %.5f, %.5f, %.5f\n", inverse_inv1.grid[2][0], inverse_inv1.grid[2][1], inverse_inv1.grid[2][2], inverse_inv1.grid[2][3]);

	printf("expect line 3: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv1.grid[3][0], expect_inv_inv1.grid[3][1], expect_inv_inv1.grid[3][2], expect_inv_inv1.grid[3][3]);
	printf("result line 3: %.5f, %.5f, %.5f, %.5f\n", inverse_inv1.grid[3][0], inverse_inv1.grid[3][1], inverse_inv1.grid[3][2], inverse_inv1.grid[3][3]);

	
	
	if (fabs(det_inv1 - expec_det_inv1) < EPSILON && fabs(expec_cof_inv1_0 - cof_inv1_0) < EPSILON && fabs(expec_cof_inv1_1 - cof_inv1_1) < EPSILON && matrix_equality(inverse_inv1, expect_inv_inv1))
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");




	printf("\n\033[1;35mCalculating the inverse of another matrix\033[0m\n");
	double	inv2[] = {8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4};
	t_matrix	matrix_inv2 = create_matrix(4, inv2);
	t_matrix	inverse_inv2 = calc_inverse_matrix(matrix_inv2);
	round_matrix(&inverse_inv2);
	double		expect_inverse_inv2[] = {-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308, 0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231, -0.69231, -0.76923, -1.92308};
	t_matrix	expect_inv_inv2 = create_matrix(4, expect_inverse_inv2);
	printf("expect line 0: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv2.grid[0][0], expect_inv_inv2.grid[0][1], expect_inv_inv2.grid[0][2], expect_inv_inv2.grid[0][3]);
	printf("result line 0: %.5f, %.5f, %.5f, %.5f\n", inverse_inv2.grid[0][0], inverse_inv2.grid[0][1], inverse_inv2.grid[0][2], inverse_inv2.grid[0][3]);
	printf("expect line 1: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv2.grid[1][0], expect_inv_inv2.grid[1][1], expect_inv_inv2.grid[1][2], expect_inv_inv2.grid[1][3]);
	printf("result line 1: %.5f, %.5f, %.5f, %.5f\n", inverse_inv2.grid[1][0], inverse_inv2.grid[1][1], inverse_inv2.grid[1][2], inverse_inv2.grid[1][3]);
	printf("expect line 2: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv2.grid[2][0], expect_inv_inv2.grid[2][1], expect_inv_inv2.grid[2][2], expect_inv_inv2.grid[2][3]);
	printf("result line 2: %.5f, %.5f, %.5f, %.5f\n", inverse_inv2.grid[2][0], inverse_inv2.grid[2][1], inverse_inv2.grid[2][2], inverse_inv2.grid[2][3]);
	printf("expect line 3: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv2.grid[3][0], expect_inv_inv2.grid[3][1], expect_inv_inv2.grid[3][2], expect_inv_inv2.grid[3][3]);
	printf("result line 3: %.5f, %.5f, %.5f, %.5f\n", inverse_inv2.grid[3][0], inverse_inv2.grid[3][1], inverse_inv2.grid[3][2], inverse_inv2.grid[3][3]);
	if (matrix_equality(inverse_inv2, expect_inv_inv2))
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");
	



	printf("\n\033[1;35mCalculating the inverse of a third matrix\033[0m\n");
	double	inv3[] = {9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2};
	t_matrix	matrix_inv3 = create_matrix(4, inv3);
	t_matrix	inverse_inv3 = calc_inverse_matrix(matrix_inv3);
	round_matrix(&inverse_inv3);
	double		expect_inverse_inv3[] = {-0.04074, -0.07778, 0.14444, -0.22222, -0.07778, 0.03333, 0.36667, -0.33333, -0.02901, -0.14630, -0.10926, 0.12963, 0.17778, 0.06667, -0.26667, 0.33333};
	t_matrix	expect_inv_inv3 = create_matrix(4, expect_inverse_inv3);
	printf("expect line 0: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv3.grid[0][0], expect_inv_inv3.grid[0][1], expect_inv_inv3.grid[0][2], expect_inv_inv3.grid[0][3]);
	printf("result line 0: %.5f, %.5f, %.5f, %.5f\n", inverse_inv3.grid[0][0], inverse_inv3.grid[0][1], inverse_inv3.grid[0][2], inverse_inv3.grid[0][3]);
	printf("expect line 1: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv3.grid[1][0], expect_inv_inv3.grid[1][1], expect_inv_inv3.grid[1][2], expect_inv_inv3.grid[1][3]);
	printf("result line 1: %.5f, %.5f, %.5f, %.5f\n", inverse_inv3.grid[1][0], inverse_inv3.grid[1][1], inverse_inv3.grid[1][2], inverse_inv3.grid[1][3]);
	printf("expect line 2: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv3.grid[2][0], expect_inv_inv3.grid[2][1], expect_inv_inv3.grid[2][2], expect_inv_inv3.grid[2][3]);
	printf("result line 2: %.5f, %.5f, %.5f, %.5f\n", inverse_inv3.grid[2][0], inverse_inv3.grid[2][1], inverse_inv3.grid[2][2], inverse_inv3.grid[2][3]);
	printf("expect line 3: %.5f, %.5f, %.5f, %.5f\n", expect_inv_inv3.grid[3][0], expect_inv_inv3.grid[3][1], expect_inv_inv3.grid[3][2], expect_inv_inv3.grid[3][3]);
	printf("result line 3: %.5f, %.5f, %.5f, %.5f\n", inverse_inv3.grid[3][0], inverse_inv3.grid[3][1], inverse_inv3.grid[3][2], inverse_inv3.grid[3][3]);
	if (matrix_equality(inverse_inv3, expect_inv_inv3))
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");



	printf("\n\033[1;35mMultiplying a product by its inverse\033[0m\n");
	double	prod_A[] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	t_matrix	matrix_prod_A = create_matrix(4, prod_A);
	double	prod_B[] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};
	t_matrix	matrix_prod_B = create_matrix(4, prod_B);
	t_matrix	result_prod = multiply_matrices(matrix_prod_A, matrix_prod_B);
	t_matrix	matrix_inv_prod_B = calc_inverse_matrix(matrix_prod_B);
	t_matrix	expect_prod = multiply_matrices(result_prod, matrix_inv_prod_B);
	round_matrix(&expect_prod);
	printf("expect line 0: %.5f, %.5f, %.5f, %.5f\n", expect_prod.grid[0][0], expect_prod.grid[0][1], expect_prod.grid[0][2], expect_prod.grid[0][3]);
	printf("result line 0: %.5f, %.5f, %.5f, %.5f\n", matrix_prod_A.grid[0][0], matrix_prod_A.grid[0][1], matrix_prod_A.grid[0][2], matrix_prod_A.grid[0][3]);
	printf("expect line 1: %.5f, %.5f, %.5f, %.5f\n", expect_prod.grid[1][0], expect_prod.grid[1][1], expect_prod.grid[1][2], expect_prod.grid[1][3]);
	printf("result line 1: %.5f, %.5f, %.5f, %.5f\n", matrix_prod_A.grid[1][0], matrix_prod_A.grid[1][1], matrix_prod_A.grid[1][2], matrix_prod_A.grid[1][3]);
	printf("expect line 2: %.5f, %.5f, %.5f, %.5f\n", expect_prod.grid[2][0], expect_prod.grid[2][1], expect_prod.grid[2][2], expect_prod.grid[2][3]);
	printf("result line 2: %.5f, %.5f, %.5f, %.5f\n", matrix_prod_A.grid[2][0], matrix_prod_A.grid[2][1], matrix_prod_A.grid[2][2], matrix_prod_A.grid[2][3]);
	printf("expect line 3: %.5f, %.5f, %.5f, %.5f\n", expect_prod.grid[3][0], expect_prod.grid[3][1], expect_prod.grid[3][2], expect_prod.grid[3][3]);
	printf("result line 3: %.5f, %.5f, %.5f, %.5f\n", matrix_prod_A.grid[3][0], matrix_prod_A.grid[3][1], matrix_prod_A.grid[3][2], matrix_prod_A.grid[3][3]);
	
	if (matrix_equality(matrix_prod_A, expect_prod))
		printf("\33[1;32mOK\n \033[0m\n");
	else
		printf("\33[1;31mFAIL\n\033[0m\n");
	



	printf("\n\033[1;35mMultiplying by a translation matrix\033[0m\n");
	t_matrix	transform = create_translation_matrix(5, -3, 2);
	t_tuple		point_trans = create_point(-3, 4, 5);
	t_tuple		result_trans = multiply_matrix_by_tuple(transform, point_trans);
	t_tuple		expect_trans = create_point(2, 1, 7);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_trans.x, expect_trans.y, expect_trans.z, expect_trans.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_trans.x, result_trans.y, result_trans.z, result_trans.w);
	if (check_tuple_equality(expect_trans, result_trans))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mMultiplying by the inverse of a translation matrix\033[0m\n");
	t_matrix	transform_inv = create_translation_matrix(5, -3, 2);
	t_matrix	transform_inv_inv = calc_inverse_matrix(transform_inv);
	t_tuple		point_inv = create_point(-3, 4, 5);
	t_tuple		result_inv = multiply_matrix_by_tuple(transform_inv_inv, point_inv);
	t_tuple		expect_inv = create_point(-8, 7, 3);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_inv.x, expect_inv.y, expect_inv.z, expect_inv.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_inv.x, result_inv.y, result_inv.z, result_inv.w);
	if (check_tuple_equality(expect_inv, result_inv))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mTranslation does not affect vectors\033[0m\n");
	t_matrix	transform_vec = create_translation_matrix(5, -3, 2);
	t_tuple		vector_trans = create_vector(-3, 4, 5);
	t_tuple		result_vec = multiply_matrix_by_tuple(transform_vec, vector_trans);
	t_tuple		expect_vec = create_vector(-3, 4, 5);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_vec.x, expect_vec.y, expect_vec.z, expect_vec.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_vec.x, result_vec.y, result_vec.z, result_vec.w);
	if (check_tuple_equality(expect_vec, result_vec))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mA scaling matrix applied to a point\033[0m\n");
	t_matrix	scale = create_scaling_matrix(2, 3, 4);
	t_tuple		point_scale = create_point(-4, 6, 8);
	t_tuple		result_scale = multiply_matrix_by_tuple(scale, point_scale);
	t_tuple		expect_scale = create_point(-8, 18, 32);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_scale.x, expect_scale.y, expect_scale.z, expect_scale.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_scale.x, result_scale.y, result_scale.z, result_scale.w);
	if (check_tuple_equality(expect_scale, result_scale))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
	



	printf("\n\033[1;35mA scaling matrix applied to a vector\033[0m\n");
	t_matrix	scale_vec = create_scaling_matrix(2, 3, 4);
	t_tuple		vector_scale = create_vector(-4, 6, 8);
	t_tuple		result_scale_vec = multiply_matrix_by_tuple(scale_vec, vector_scale);
	t_tuple		expect_scale_vec = create_vector(-8, 18, 32);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_scale_vec.x, expect_scale_vec.y, expect_scale_vec.z, expect_scale_vec.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_scale_vec.x, result_scale_vec.y, result_scale_vec.z, result_scale_vec.w);
	if (check_tuple_equality(expect_scale_vec, result_scale_vec))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mMultiplying by the inverse of a scaling matrix\033[0m\n");
	t_matrix	scale_inv = create_scaling_matrix(2, 3, 4);
	t_matrix	scale_inv_inv = calc_inverse_matrix(scale_inv);
	t_tuple		vector_scale_inv = create_vector(-4, 6, 8);
	t_tuple		result_scale_inv = multiply_matrix_by_tuple(scale_inv_inv, vector_scale_inv);
	t_tuple		expect_scale_inv = create_vector(-2, 2, 2);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_scale_inv.x, expect_scale_inv.y, expect_scale_inv.z, expect_scale_inv.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_scale_inv.x, result_scale_inv.y, result_scale_inv.z, result_scale_inv.w);
	if (check_tuple_equality(expect_scale_inv, result_scale_inv))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");





	printf("\n\033[1;35mReflection is scaling by a negative value\033[0m\n");
	t_matrix	reflect = create_scaling_matrix(-1, 1, 1);
	t_tuple		point_reflect = create_point(2, 3, 4);
	t_tuple		result_reflect = multiply_matrix_by_tuple(reflect, point_reflect);
	t_tuple		expect_reflect = create_point(-2, 3, 4);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_reflect.x, expect_reflect.y, expect_reflect.z, expect_reflect.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_reflect.x, result_reflect.y, result_reflect.z, result_reflect.w);
	if (check_tuple_equality(expect_reflect, result_reflect))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mRotating a point around the x axis\033[0m\n");
	t_tuple	point_rot_x = create_point(0, 1, 0);
	t_matrix	rotate_x_pi_4 = create_rotation_matrix_x(M_PI / 4);
	t_matrix	rotate_x_pi_2 = create_rotation_matrix_x(M_PI / 2);
	t_tuple	result_rot_x_pi_4 = multiply_matrix_by_tuple(rotate_x_pi_4, point_rot_x);
	t_tuple	result_rot_x_pi_2 = multiply_matrix_by_tuple(rotate_x_pi_2, point_rot_x);

	
	t_tuple	expect_rot_x_PI_4 = create_point(0, sqrt(2) / 2, sqrt(2) / 2);
	t_tuple	expect_rot_x_pi_2 = create_point(0, 0, 1);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_x_PI_4.x, expect_rot_x_PI_4.y, expect_rot_x_PI_4.z, expect_rot_x_PI_4.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_x_pi_4.x, result_rot_x_pi_4.y, result_rot_x_pi_4.z, result_rot_x_pi_4.w);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_x_pi_2.x, expect_rot_x_pi_2.y, expect_rot_x_pi_2.z, expect_rot_x_pi_2.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_x_pi_2.x, result_rot_x_pi_2.y, result_rot_x_pi_2.z, result_rot_x_pi_2.w);
	if (check_tuple_equality(expect_rot_x_PI_4, result_rot_x_pi_4) && check_tuple_equality(expect_rot_x_pi_2, result_rot_x_pi_2))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mThe inverse of an x-rotation rotates in the opposite direction\033[0m\n");
	t_tuple	point_rot_x_inv = create_point(0, 1, 0);
	t_matrix	rotate_x_pi_4_inv = create_rotation_matrix_x(M_PI / 4);
	t_matrix	rotate_x_pi_4_inv_inv = calc_inverse_matrix(rotate_x_pi_4_inv);
	t_tuple	result_rot_x_pi_4_inv = multiply_matrix_by_tuple(rotate_x_pi_4_inv_inv, point_rot_x_inv);
	t_tuple	expect_rot_x_PI_4_inv = create_point(0, sqrt(2) / 2, -sqrt(2) / 2);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_x_PI_4_inv.x, expect_rot_x_PI_4_inv.y, expect_rot_x_PI_4_inv.z, expect_rot_x_PI_4_inv.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_x_pi_4_inv.x, result_rot_x_pi_4_inv.y, result_rot_x_pi_4_inv.z, result_rot_x_pi_4_inv.w);
	if (check_tuple_equality(expect_rot_x_PI_4_inv, result_rot_x_pi_4_inv))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mRotating a point around the y axis\033[0m\n");
	t_tuple	point_rot_y = create_point(0, 0, 1);
	t_matrix	rotate_y_pi_4 = create_rotation_matrix_y(M_PI / 4);
	t_matrix	rotate_y_pi_2 = create_rotation_matrix_y(M_PI / 2);
	t_tuple	result_rot_y_pi_4 = multiply_matrix_by_tuple(rotate_y_pi_4, point_rot_y);
	t_tuple	result_rot_y_pi_2 = multiply_matrix_by_tuple(rotate_y_pi_2, point_rot_y);
	t_tuple	expect_rot_y_PI_4 = create_point(sqrt(2) / 2, 0, sqrt(2) / 2);
	t_tuple	expect_rot_y_pi_2 = create_point(1, 0, 0);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_y_PI_4.x, expect_rot_y_PI_4.y, expect_rot_y_PI_4.z, expect_rot_y_PI_4.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_y_pi_4.x, result_rot_y_pi_4.y, result_rot_y_pi_4.z, result_rot_y_pi_4.w);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_y_pi_2.x, expect_rot_y_pi_2.y, expect_rot_y_pi_2.z, expect_rot_y_pi_2.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_y_pi_2.x, result_rot_y_pi_2.y, result_rot_y_pi_2.z, result_rot_y_pi_2.w);
	if (check_tuple_equality(expect_rot_y_PI_4, result_rot_y_pi_4) && check_tuple_equality(expect_rot_y_pi_2, result_rot_y_pi_2))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mRotating a point around the z axis\033[0m\n");
	t_tuple	point_rot_z = create_point(0, 1, 0);
	t_matrix	rotate_z_pi_4 = create_rotation_matrix_z(M_PI / 4);
	t_matrix	rotate_z_pi_2 = create_rotation_matrix_z(M_PI / 2);
	t_tuple	result_rot_z_pi_4 = multiply_matrix_by_tuple(rotate_z_pi_4, point_rot_z);
	t_tuple	result_rot_z_pi_2 = multiply_matrix_by_tuple(rotate_z_pi_2, point_rot_z);
	t_tuple	expect_rot_z_PI_4 = create_point(-sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple	expect_rot_z_pi_2 = create_point(-1, 0, 0);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_z_PI_4.x, expect_rot_z_PI_4.y, expect_rot_z_PI_4.z, expect_rot_z_PI_4.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_z_pi_4.x, result_rot_z_pi_4.y, result_rot_z_pi_4.z, result_rot_z_pi_4.w);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_rot_z_pi_2.x, expect_rot_z_pi_2.y, expect_rot_z_pi_2.z, expect_rot_z_pi_2.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_rot_z_pi_2.x, result_rot_z_pi_2.y, result_rot_z_pi_2.z, result_rot_z_pi_2.w);
	if (check_tuple_equality(expect_rot_z_PI_4, result_rot_z_pi_4) && check_tuple_equality(expect_rot_z_pi_2, result_rot_z_pi_2))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
		
	
//sheraring

	printf("\n\033[1;35mA shearing transformation moves x in proportion to y\033[0m\n");
	double	proportions_xy[6] = {1, 0, 0, 0, 0, 0};
	t_matrix	shear = create_shearing_matrix(proportions_xy);
	t_tuple	point_shear = create_point(2, 3, 4);
	t_tuple	result_shear = multiply_matrix_by_tuple(shear, point_shear);
	t_tuple	expect_shear = create_point(5, 3, 4);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear.x, expect_shear.y, expect_shear.z, expect_shear.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear.x, result_shear.y, result_shear.z, result_shear.w);
	if (check_tuple_equality(expect_shear, result_shear))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mA shearing transformation moves x in proportion to z\033[0m\n");
	double	proportions_xz[6] = {0, 1, 0, 0, 0, 0};
	t_matrix	shear_z = create_shearing_matrix(proportions_xz);
	t_tuple	point_shear_z = create_point(2, 3, 4);
	t_tuple	result_shear_z = multiply_matrix_by_tuple(shear_z, point_shear_z);
	t_tuple	expect_shear_z = create_point(6, 3, 4);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear_z.x, expect_shear_z.y, expect_shear_z.z, expect_shear_z.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear_z.x, result_shear_z.y, result_shear_z.z, result_shear_z.w);
	if (check_tuple_equality(expect_shear_z, result_shear_z))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mA shearing transformation moves y in proportion to x\033[0m\n");
	double	proportions_yx[6] = {0, 0, 1, 0, 0, 0};
	t_matrix	shear_y = create_shearing_matrix(proportions_yx);
	t_tuple	point_shear_y = create_point(2, 3, 4);
	t_tuple	result_shear_y = multiply_matrix_by_tuple(shear_y, point_shear_y);
	t_tuple	expect_shear_y = create_point(2, 5, 4);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear_y.x, expect_shear_y.y, expect_shear_y.z, expect_shear_y.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear_y.x, result_shear_y.y, result_shear_y.z, result_shear_y.w);
	if (check_tuple_equality(expect_shear_y, result_shear_y))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mA shearing transformation moves y in proportion to z\033[0m\n");
	double	proportions_yz[6] = {0, 0, 0, 1, 0, 0};
	t_matrix	shear_y_z = create_shearing_matrix(proportions_yz);
	t_tuple	point_shear_y_z = create_point(2, 3, 4);
	t_tuple	result_shear_y_z = multiply_matrix_by_tuple(shear_y_z, point_shear_y_z);
	t_tuple	expect_shear_y_z = create_point(2, 7, 4);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear_y_z.x, expect_shear_y_z.y, expect_shear_y_z.z, expect_shear_y_z.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear_y_z.x, result_shear_y_z.y, result_shear_y_z.z, result_shear_y_z.w);
	if (check_tuple_equality(expect_shear_y_z, result_shear_y_z))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mA shearing transformation moves z in proportion to x\033[0m\n");
	double	proportions_zx[6] = {0, 0, 0, 0, 1, 0};
	t_matrix	shear_z_x = create_shearing_matrix(proportions_zx);
	t_tuple	point_shear_z_x = create_point(2, 3, 4);
	t_tuple	result_shear_z_x = multiply_matrix_by_tuple(shear_z_x, point_shear_z_x);
	t_tuple	expect_shear_z_x = create_point(2, 3, 6);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear_z_x.x, expect_shear_z_x.y, expect_shear_z_x.z, expect_shear_z_x.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear_z_x.x, result_shear_z_x.y, result_shear_z_x.z, result_shear_z_x.w);
	if (check_tuple_equality(expect_shear_z_x, result_shear_z_x))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");


	printf("\n\033[1;35mA shearing transformation moves z in proportion to y\033[0m\n");
	double	proportions_zy[6] = {0, 0, 0, 0, 0, 1};
	t_matrix	shear_z_y = create_shearing_matrix(proportions_zy);
	t_tuple	point_shear_z_y = create_point(2, 3, 4);
	t_tuple	result_shear_z_y = multiply_matrix_by_tuple(shear_z_y, point_shear_z_y);
	t_tuple	expect_shear_z_y = create_point(2, 3, 7);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_shear_z_y.x, expect_shear_z_y.y, expect_shear_z_y.z, expect_shear_z_y.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_shear_z_y.x, result_shear_z_y.y, result_shear_z_y.z, result_shear_z_y.w);
	if (check_tuple_equality(expect_shear_z_y, result_shear_z_y))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mIndividual transformations are applied in sequence\033[0m\n");
	t_tuple		point_seq = create_point(1, 0, 1);
	t_matrix	rotate_seq = create_rotation_matrix_x(M_PI / 2);
	t_matrix	scale_seq = create_scaling_matrix(5, 5, 5);
	t_matrix	translate_seq = create_translation_matrix(10, 5, 7);
	t_tuple	result_seq = multiply_matrix_by_tuple(translate_seq, multiply_matrix_by_tuple(scale_seq, multiply_matrix_by_tuple(rotate_seq, point_seq)));
	t_tuple	expect_seq = create_point(15, 0, 7);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_seq.x, expect_seq.y, expect_seq.z, expect_seq.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_seq.x, result_seq.y, result_seq.z, result_seq.w);
	if (check_tuple_equality(expect_seq, result_seq))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mChained transformations must be applied in reverse order\033[0m\n");
	t_tuple		point_chain = create_point(1, 0, 1);
	t_matrix	rotate_chain = create_rotation_matrix_x(M_PI / 2);
	t_matrix	scale_chain = create_scaling_matrix(5, 5, 5);
	t_matrix	translate_chain = create_translation_matrix(10, 5, 7);
	t_matrix	transform_chain = multiply_matrices(translate_chain, multiply_matrices(scale_chain, rotate_chain));
	t_tuple	result_chain = multiply_matrix_by_tuple(transform_chain, point_chain);
	t_tuple	expect_chain = create_point(15, 0, 7);
	printf("expect: %.2f, %.2f, %.2f, %.2f\n", expect_chain.x, expect_chain.y, expect_chain.z, expect_chain.w);
	printf("result: %.2f, %.2f, %.2f, %.2f\n", result_chain.x, result_chain.y, result_chain.z, result_chain.w);
	if (check_tuple_equality(expect_chain, result_chain))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mCreating and querying a ray\033[0m\n");
	t_tuple	origin_ray = create_point(1, 2, 3);
	t_tuple	direction_ray = create_vector(4, 5, 6);
	t_ray	ray = create_ray(origin_ray, direction_ray);
	printf("origin: %.2f, %.2f, %.2f, %.2f\n", ray.origin.x, ray.origin.y, ray.origin.z, ray.origin.w);
	printf("direction: %.2f, %.2f, %.2f, %.2f\n", ray.direction.x, ray.direction.y, ray.direction.z, ray.direction.w);
	if (check_tuple_equality(origin_ray, ray.origin) && check_tuple_equality(direction_ray, ray.direction))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mComputing a point from a distance\033[0m\n");
	t_ray	ray_dist = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0));
	t_tuple	point_dist_0 = position(ray_dist, 0);
	t_tuple	point_dist_1 = position(ray_dist, 1);
	t_tuple	point_dist_2 = position(ray_dist, -1);
	t_tuple	point_dist_3 = position(ray_dist, 2.5);

	t_tuple	expect_dist_0 = create_point(2, 3, 4);
	t_tuple	expect_dist_1 = create_point(3, 3, 4);
	t_tuple	expect_dist_2 = create_point(1, 3, 4);
	t_tuple	expect_dist_3 = create_point(4.5, 3, 4);
	printf("expect_0: %.2f, %.2f, %.2f, %.2f\n", expect_dist_0.x, expect_dist_0.y, expect_dist_0.z, expect_dist_0.w);
	printf("result_0: %.2f, %.2f, %.2f, %.2f\n", point_dist_0.x, point_dist_0.y, point_dist_0.z, point_dist_0.w);
	printf("expect_1: %.2f, %.2f, %.2f, %.2f\n", expect_dist_1.x, expect_dist_1.y, expect_dist_1.z, expect_dist_1.w);
	printf("result_1: %.2f, %.2f, %.2f, %.2f\n", point_dist_1.x, point_dist_1.y, point_dist_1.z, point_dist_1.w);
	printf("expect_2: %.2f, %.2f, %.2f, %.2f\n", expect_dist_2.x, expect_dist_2.y, expect_dist_2.z, expect_dist_2.w);
	printf("result_2: %.2f, %.2f, %.2f, %.2f\n", point_dist_2.x, point_dist_2.y, point_dist_2.z, point_dist_2.w);
	printf("expect_3: %.2f, %.2f, %.2f, %.2f\n", expect_dist_3.x, expect_dist_3.y, expect_dist_3.z, expect_dist_3.w);
	printf("result_3: %.2f, %.2f, %.2f, %.2f\n", point_dist_3.x, point_dist_3.y, point_dist_3.z, point_dist_3.w);
	if (check_tuple_equality(expect_dist_0, point_dist_0) && check_tuple_equality(expect_dist_1, point_dist_1) && check_tuple_equality(expect_dist_2, point_dist_2) && check_tuple_equality(expect_dist_3, point_dist_3))
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");

	
	
	printf("\n\033[1;35mA ray intersects a sphere at two points\033[0m\n");
	t_rt rt;
	t_ray	ray_sphere = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_sphere	sphere = create_sphere();
	t_discriminant	discriminant = calc_discriminant(ray_sphere, sphere);
	t_intersec	intersec_sphere = intersect(ray_sphere, sphere, discriminant);
	printf("intersections: %d\n", intersec_sphere.count);
	printf("t1: %.2f\n", intersec_sphere.t[0]);
	printf("t2: %.2f\n", intersec_sphere.t[1]);
	if (intersec_sphere.count == 2 && intersec_sphere.t[0] == 4.0 && intersec_sphere.t[1] == 6.0)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");




	printf("\n\033[1;35mA ray intersects a sphere at a tangent\033[0m\n");
	t_ray	ray_tangent = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	t_intersec	intersec_tangent = intersect(ray_tangent, sphere, discriminant);
	printf("intersections: %d\n", intersec_tangent.count);
	printf("t1: %.2f\n", intersec_tangent.t[0]);
	printf("t2: %.2f\n", intersec_tangent.t[1]);
	if (intersec_tangent.count == 2 && intersec_tangent.t[0] == 5.0 && intersec_tangent.t[1] == 5.0)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
		


	printf("\n\033[1;35mA ray misses a sphere\033[0m\n");
	t_ray	ray_miss = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	t_sphere	sphere_miss = create_sphere();
	t_intersec	intersec_miss = intersect(ray_miss, sphere_miss, discriminant);
	printf("intersections: %d\n", intersec_miss.count);
	if (intersec_miss.count == 0)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
	
	
	printf("\n\033[1;35mA ray originates inside a sphere\033[0m\n");
	t_ray	ray_inside = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	t_sphere	sphere_inside = create_sphere();
	t_intersec	intersec_inside = intersect(ray_inside, sphere_inside, discriminant);
	printf("intersections: %d\n", intersec_inside.count);
	printf("t1: %.2f\n", intersec_inside.t[0]);
	printf("t2: %.2f\n", intersec_inside.t[1]);
	if (intersec_inside.count == 2 && intersec_inside.t[0] == -1.0 && intersec_inside.t[1] == 1.0)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");



	printf("\n\033[1;35mA sphere is behind a ray\033[0m\n");
	t_ray	ray_behind = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	t_sphere	sphere_behind = create_sphere();
	t_intersec	intersec_behind = intersect(ray_behind, sphere_behind, discriminant);
	printf("intersections: %d\n", intersec_behind.count);
	printf("t1: %.2f\n", intersec_behind.t[0]);
	printf("t2: %.2f\n", intersec_behind.t[1]);
	if (intersec_behind.count == 2 && intersec_behind.t[0] == -6.0 && intersec_behind.t[1] == -4.0)
		printf("\33[1;32mOK\033[0m\n");
	else
		printf("\33[1;31mFAIL\033[0m\n");
		

	
	return (0);
}

