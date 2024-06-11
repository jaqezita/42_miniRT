/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:43:13 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 04:27:18 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_last_intersections(t_intersections *intersections, t_obj_type type)
{
	t_intersection	*node;

	node = create_intersection(type);
	if (!node)
	{
		printf("\n FALSE - add_last_intersections\n");
		return (FALSE);
	}
	if (intersections->start == NULL)
	{
		intersections->start = node;
		intersections->end = node;
	}
	else
	{
		intersections->end->next = node;
		node->before = intersections->end;
		intersections->end = node;
	}
	return (TRUE);
}

t_discriminant	calc_discriminant_danilo(t_tuple position, t_ray ray, \
t_sphere sphere)
{
	t_discriminant	discriminant;
	t_tuple			sphere_to_position;

	sphere_to_position = subtract_tuples(position, sphere.center);
	discriminant.a = dot_product(ray.direction, ray.direction);
	discriminant.b = 2 * dot_product(ray.direction, sphere_to_position);
	discriminant.c = dot_product(sphere_to_position, sphere_to_position) - 1;
	discriminant.discriminant = pow(discriminant.b, 2) - \
	(4 * discriminant.a * discriminant.c);
	return (discriminant);
}

t_intersec	intersect_danilo(double time, t_ray ray, \
t_intersection *intersection_element)
{
	double				t1;
	double				t2;
	t_intersec			intersec;
	t_discriminant		discriminant;
	t_tuple				ray_position;
	t_sphere			sphere;

	sphere = *(t_sphere *)(intersection_element->obj);
	ray_position = position(ray, time);
	discriminant = calc_discriminant_danilo(ray_position, ray, sphere);
	if (discriminant.discriminant < 0)
	{
		intersection_element->hitcontact = NO_HIT;
		return (intersec);
	}
	if (discriminant.discriminant == 0)
		intersection_element->hitcontact = ONE_HIT;
	if (discriminant.discriminant > 0)
		intersection_element->hitcontact = TWO_HIT;
	intersec.t[0] = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) \
	/ (2.0 * discriminant.a);
	intersec.t[1] = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) \
	/ (2.0 * discriminant.a);
	intersec.count = 2;
	return (intersec);
}

void	calc_intersection(t_ray ray, t_intersection *intersection_element, \
double time)
{
	intersection_element->time = time;
	intersection_element->intersect = intersect_danilo(time, ray, \
	intersection_element);
}
