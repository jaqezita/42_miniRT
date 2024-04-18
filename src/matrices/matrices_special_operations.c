/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_special_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:04:53 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 16:03:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	transpose_matrix(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	result;

	result.size = m.size;
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			result.grid[j][i] = m.grid[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

double	calc_determinant(int size, t_matrix m)
{
	t_matrix	submatrix;
	double		det;
	int			i;

	det = 0;
	i = 0;
	if (size == 2)
		return (m.grid[0][0] * m.grid[1][1] - m.grid[0][1] * m.grid[1][0]);
	while (i < size)
	{
		submatrix = create_submatrix(m, 0, i);
		if (i % 2 == 0)
			det += m.grid[0][i] * calc_determinant(submatrix.size, submatrix);
		else
			det -= m.grid[0][i] * calc_determinant(submatrix.size, submatrix);
		i++;
	}
	return (det);
}

double	calc_minor(t_matrix m, int row, int col)
{
	t_matrix	submatrix;
	double		minor;
	double		determinant;

	submatrix = create_submatrix(m, row, col);
	determinant = calc_determinant(submatrix.size, submatrix);
	minor = determinant;
	return (minor);
}

double	calc_cofactor(t_matrix m, int row, int col)
{
	double	minor;
	double	cofactor;

	minor = calc_minor(m, row, col);
	if ((row + col) % 2 != 0)
		cofactor = -minor;
	else
		cofactor = minor;
	return (cofactor);
}

t_matrix	calc_inverse_matrix(t_matrix m)
{
	t_matrix	cof_transpose;
	t_matrix	inv;
	t_matrix	cof_matrix;
	double		det;

	inv.size = m.size;
	det = calc_determinant(m.size, m);
	if (det == 0)
	{
		(printf("Determinant is 0, matrix is not invertible\n"));
		return (m);
	}
	cof_matrix = create_cof_matrix(m);
	cof_transpose = transpose_matrix(cof_matrix);
	inv = multiply_matrix_by_scalar(cof_transpose, 1 / det);
	return (inv);
}
