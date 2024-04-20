/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_trans_create_structures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:09:08 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/20 00:12:09 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
