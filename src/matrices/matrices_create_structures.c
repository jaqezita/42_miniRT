/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_create_structures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:41:25 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:58:13 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
			cof_matrix.grid[i][j] = calc_cofactor(m, i, j);
			j++;
		}
		i++;
	}
	return (cof_matrix);
}
