/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tuple_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:46:21 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:58:55 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
