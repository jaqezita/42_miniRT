/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shearing_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:09:08 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/20 00:32:53 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

