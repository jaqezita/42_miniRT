/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_basic_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:46:15 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:53:32 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
