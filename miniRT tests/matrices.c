/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:42 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/20 01:16:56 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_matrix	create_matrix(int size, double numbers[])
{
	int			i;
	int			j;
	int			k;
	t_matrix	m;

	m.size = size;
	i = 0;
	k = -1;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			m.grid[i][j] = numbers[++k];
			j++;
		}
		i++;
	}
	return (m);
}

int	matrix_equality(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (0);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (a.grid[i][j] != b.grid[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			i;
	int			j;

	result.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			result.grid[i][j] = (a.grid[i][0] * b.grid[0][j] \
								+ a.grid[i][1] * b.grid[1][j] \
								+ a.grid[i][2] * b.grid[2][j] \
								+ a.grid[i][3] * b.grid[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

t_tuple	multiply_matrix_by_tuple(t_matrix m, t_tuple p)
{
	t_tuple	result;
	t_tuple	tuples[4];
	int		i;

	i = 0;
	while (i < m.size)
	{
		tuples[i] = create_tuple(m.grid[i][0], m.grid[i][1], m.grid[i][2], \
								m.grid[i][3]);
		i++;
	}
	result.x = dot_product(tuples[0], p);
	result.y = dot_product(tuples[1], p);
	result.z = dot_product(tuples[2], p);
	result.w = dot_product(tuples[3], p);
	return (result);
}

t_matrix	create_matrix_identity(int size)
{
	int			i;
	int			j;
	t_matrix	m;

	m.size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				m.grid[i][j] = 1;
			else
				m.grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_tuple	multiply_matrix_id_by_tuple(t_tuple p)
{
	t_matrix	m;
	t_tuple		result;
	t_tuple		tuples[4];
	int			i;

	i = 0;
	m = create_matrix_identity(4);
	while (i < 4)
	{
		tuples[i] = create_tuple(m.grid[i][0], m.grid[i][1], m.grid[i][2], \
								m.grid[i][3]);
		i++;
	}
	result.x = dot_product(tuples[0], p);
	result.y = dot_product(tuples[1], p);
	result.z = dot_product(tuples[2], p);
	result.w = dot_product(tuples[3], p);
	return (result);
}

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

void	fill_submatrix(t_matrix m, t_matrix *sub, int del_row, int del_col)
{
	int	row;
	int	col;
	int	x;
	int	y;

	x = 0;
	row = 0;
	while (row < m.size)
	{
		if (row != del_row)
		{
			y = 0;
			col = 0;
			while (col < m.size)
			{	
				if (col != del_col)
					sub->grid[x][y++] = m.grid[row][col];
				col++;
			}
			x++;
		}
		row++;
	}
}

t_matrix	create_submatrix(t_matrix m, int del_row, int del_col)
{
	t_matrix	submatrix;

	submatrix.size = m.size - 1;
	fill_submatrix(m, &submatrix, del_row, del_col);
	return (submatrix);
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

double	calc_minor(int size, t_matrix m, int row, int col)
{
	t_matrix	submatrix;
	double		minor;
	double		determinant;

	submatrix = create_submatrix(m, row, col);
	determinant = calc_determinant(submatrix.size, submatrix);
	minor = determinant;
	return (minor);
}

double	cofactor(int size, t_matrix m, int row, int col)
{
	double	minor;
	double	cofactor;

	minor = calc_minor(size, m, row, col);
	if ((row + col) % 2 != 0)
		cofactor = -minor;
	else
		cofactor = minor;
	return (cofactor);
}

t_matrix	create_cof_matrix(t_matrix m)
{
	t_matrix	cof_matrix;
	int			i;
	int			j;

	i = 0;
	cof_matrix.size = m.size;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			cof_matrix.grid[i][j] = cofactor(m.size, m, i, j);
			j++;
		}
		i++;
	}
	return (cof_matrix);
}

t_matrix	multiply_matrix_by_scalar(t_matrix m, double scalar)
{
	t_matrix	result;
	int			i;
	int			j;

	result.size = m.size;
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			result.grid[i][j] = m.grid[i][j] * scalar;
			j++;
		}
		i++;
	}
	return (result);
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
		exit(printf("Determinant is 0, matrix is not invertible\n"));
	cof_matrix = create_cof_matrix(m);
	cof_transpose = transpose_matrix(cof_matrix);
	inv = multiply_matrix_by_scalar(cof_transpose, 1 / det);
	return (inv);
}




// M_PI is a constant defined in math.h that represents the value of pi. It is used in various mathematical calculations involving circles, trigonometry, and other geometric shapes. For example, it can be used to calculate the circumference of a circle or the area of a circle. It is a useful constant in many mathematical and scientific applications.



t_matrix	create_translation_matrix(double x, double y, double z)
{
	t_matrix	translation;

	translation = create_matrix_identity(4);
	translation.grid[0][3] = x;
	translation.grid[1][3] = y;
	translation.grid[2][3] = z;
	return (translation);
}

t_matrix	create_scaling_matrix(double x, double y, double z)
{
	t_matrix	scaling;

	scaling = create_matrix_identity(4);
	scaling.grid[0][0] = x;
	scaling.grid[1][1] = y;
	scaling.grid[2][2] = z;
	return (scaling);
}

t_matrix	create_rotation_matrix_x(double rad)
{
	t_matrix	rotation;

	rotation = create_matrix_identity(4);
	rotation.grid[1][1] = cos(rad);
	rotation.grid[1][2] = -sin(rad);
	rotation.grid[2][1] = sin(rad);
	rotation.grid[2][2] = cos(rad);
	return (rotation);
}

t_matrix	create_rotation_matrix_y(double rad)
{
	t_matrix	rotation;

	rotation = create_matrix_identity(4);
	rotation.grid[0][0] = cos(rad);
	rotation.grid[0][2] = sin(rad);
	rotation.grid[2][0] = -sin(rad);
	rotation.grid[2][2] = cos(rad);
	return (rotation);
}

t_matrix	create_rotation_matrix_z(double rad)
{
	t_matrix	rotation;

	rotation = create_matrix_identity(4);
	rotation.grid[0][0] = cos(rad);
	rotation.grid[0][1] = -sin(rad);
	rotation.grid[1][0] = sin(rad);
	rotation.grid[1][1] = cos(rad);
	return (rotation);
}

t_matrix	create_shearing_matrix(double proportion[6])
{
	t_matrix	shearing;

	shearing = create_matrix_identity(4);
	shearing.grid[0][1] = proportion[0];
	shearing.grid[0][2] = proportion[1];
	shearing.grid[1][0] = proportion[2];
	shearing.grid[1][2] = proportion[3];
	shearing.grid[2][0] = proportion[4];
	shearing.grid[2][1] = proportion[5];
	return (shearing);
}