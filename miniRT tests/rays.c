/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:12:23 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/10 18:43:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_ray		create_ray(t_tuple origin, t_tuple direction) // create a ray
{
	t_ray	ray;

	ray.origin = create_point(origin.x, origin.y, origin.z);
	ray.direction = create_vector(direction.x, direction.y, direction.z);
	return (ray);
}

t_tuple		position(t_ray ray, double t) // position of the ray at time t
{
	t_tuple	position;

	position = add_tuples(ray.origin, multiply_tuples_scalar(ray.direction, t));
	return (position);
}

t_sphere	create_sphere() // create a sphere at the origin
{
	t_sphere	sphere;
	static int	id = 0;

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1.0;
	sphere.id = id++;
	return (sphere);
}

t_tuple sphere_to_ray(t_ray ray, t_sphere sphere)
{
	t_tuple	result;

	result = subtract_tuples(ray.origin, sphere.center);
	return (result);
}

t_discriminant	calc_discriminant(t_ray ray, t_sphere sphere)
{
	t_discriminant	discriminant;
	
	discriminant.a = dot_product(ray.direction, ray.direction);
	discriminant.b = 2 * dot_product(ray.direction, sphere_to_ray(ray, sphere));
	discriminant.c = dot_product(sphere_to_ray(ray, sphere), sphere_to_ray(ray, sphere)) - 1;
	discriminant.discriminant = pow(discriminant.b, 2) - (4 * discriminant.a * discriminant.c);
	return (discriminant);
}

t_intersec	intersect(t_ray ray, t_sphere sphere, t_discriminant discriminant)
{
	double				t1;
	double				t2;
	t_intersec			intersec;

	discriminant = calc_discriminant(ray, sphere);
	if (discriminant.discriminant < 0)
		return (intersec);
	t1 = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	t2 = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.t[0] = t1;
	intersec.t[1] = t2;
	intersec.count = 2;
	return (intersec);
}

// t_intersections	intersection(double t, t_sphere *s)
// {
// 	t_intersections i;
	
// 	i.type = 1;
// 	i.t = t;
// 	i.sphere = s;
// 	i.ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
// 	i.point = position(i.ray, i.t);
// 	return (i);
// }

t_intersections *intersection(double t, t_sphere *s)
{
    t_intersections *intersection = malloc(sizeof(t_intersections));

    // Inicializa a intersecção com zeros ou valores padrão
    intersection->type = 0; // Tipo de intersecção não definido
    intersection->t = 0.0; // Parâmetro de intersecção inicializado como zero
    intersection->sphere = s; // Ponteiro para a esfera dada
    intersection->ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1)); // Raio inicializado com um valor padrão
    intersection->point = position(intersection->ray, t); // Ponto de intersecção calculado
    intersection->next = NULL; // Inicializa o ponteiro next como NULL

    // Aqui você pode adicionar lógica para calcular o tipo de intersecção e o valor de t
    // baseado na intersecção entre o raio e a esfera s

    return intersection;
}