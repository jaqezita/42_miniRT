/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_advanced_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:20:39 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:50:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_tuple_equality(t_tuple a, t_tuple b)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = fabs(a.x - b.x);
	y = fabs(a.y - b.y);
	z = fabs(a.z - b.z);
	w = fabs(a.w - b.w);
	if ((x < EPSILON) && (y < EPSILON) && (z < EPSILON) && (w < EPSILON))
		return (1);
	return (0);
}

double	vector_magnitude(t_tuple a)
{
	double	magnitude_v;

	magnitude_v = sqrt((pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2)));
	return (magnitude_v);
}

t_tuple	vector_norm(t_tuple a)
{
	t_tuple	result;
	double	mag_v;

	mag_v = vector_magnitude(a);
	result.x = (a.x) / mag_v;
	result.y = (a.y) / mag_v;
	result.z = (a.z) / mag_v;
	result.w = (a.w) / mag_v;
	return (result);
}

double	dot_product(t_tuple a, t_tuple b)
{
	double	r;

	r = ((a.x) * (b.x)) + ((a.y) * (b.y)) + ((a.z) * (b.z)) + ((a.w) * (b.w));
	return (r);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	res;
	double	x;
	double	y;
	double	z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	res = create_vector(x, y, z);
	return (res);
}
