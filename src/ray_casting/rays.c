/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:07:15 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 04:20:20 by jaqribei         ###   ########.fr       */
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

t_discriminant	calc_discriminant(t_ray r, t_sphere sphere)
{
	t_discriminant	discriminant;

	discriminant.a = dot_product(r.direction, r.direction);
	discriminant.b = 2 * dot_product(r.direction, sphere_to_ray(r, sphere));
	discriminant.c = dot_product(sphere_to_ray(r, sphere), \
	sphere_to_ray(r, sphere)) - 1;
	discriminant.discriminant = pow(discriminant.b, 2) - \
	(4 * discriminant.a * discriminant.c);
	return (discriminant);
}
