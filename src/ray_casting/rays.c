/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:55:27 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/17 21:48:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = create_point(origin.x, origin.y, origin.z);
	ray.direction = create_vector(direction.x, direction.y, direction.z);
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	position;

	position = add_tuples(ray.origin, multiply_tuples_scalar(ray.direction, t));
	return (position);
}

t_tuple	sphere_to_ray(t_ray ray, t_sphere sphere)
{
	t_tuple	result;

	result = subtract_tuples(ray.origin, sphere.center);
	return (result);
}

// t_ray	transform_ray(t_ray ray, t_matrix matrix)
// {
// 	_ray	result;

// 	result.origin = multiply_matrix_by_tuple(matrix, ray.origin);
// 	result.direction = multiply_matrix_by_tuple(matrix, ray.direction);
// 	return (result);
// }
