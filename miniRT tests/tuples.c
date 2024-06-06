/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:36:12 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/09 18:28:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	create_point(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1.0;
	return (t);
}

t_tuple	create_vector(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0.0;
	return (t);
}

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
// classic arithmetic operations

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}


t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

t_tuple	deny_tuples(t_tuple a)
{
	t_tuple	result;

	result.x = -1 * (a.x);
	result.y = -1 * (a.y);
	result.z = -1 * (a.z);
	result.w = -1 * (a.w);
	return (result);
}

t_tuple	multiply_tuples_scalar(t_tuple a, double number)
{
	t_tuple	result;

	result.x = number * (a.x);
	result.y = number * (a.y);
	result.z = number * (a.z);
	result.w = number * (a.w);
	return (result);
}

t_tuple	divide_tuple_scalar(t_tuple a, double number)
{
	t_tuple	result;

	result.x = (a.x) / number;
	result.y = (a.y) / number;
	result.z = (a.z) / number;
	result.w = (a.w) / number;
	return (result);
}


//other arithmetic operations

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
	
	res =  create_vector(x, y, z);
	return (res);
}