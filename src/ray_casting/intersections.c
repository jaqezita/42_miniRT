/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:25:46 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/17 21:57:02 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_discriminant	calc_discriminant(t_ray ray, t_sphere sphere)
{
	t_discriminant	discriminant;

	discriminant.a = dot_product(ray.direction, ray.direction);
	discriminant.b = 2 * dot_product(ray.direction, sphere_to_ray(ray, sphere));
	discriminant.c = dot_product(sphere_to_ray(ray, sphere), sphere_to_ray(ray, sphere)) - 1;
	discriminant.discriminant = pow(discriminant.b, 2) - \
	(4 * discriminant.a * discriminant.c);
	return (discriminant);
}

t_intersec	intersect(t_ray r, t_sphere s, t_discriminant discriminant) // calculate the intersections of a ray and a sphere (before modifications)
{
	double				t1;
	double				t2;
	t_intersec			intersec;

	intersec.count = 0;
	intersec.t[0] = 0;
	intersec.t[1] = 0;
	discriminant = calc_discriminant(r, s);
	if (discriminant.discriminant < 0)
		return (intersec);
	t1 = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	t2 = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.t[0] = t1;
	intersec.t[1] = t2;
	intersec.count = 2;
	return (intersec);
}

t_intersection	*create_intersection(enum e_obj_type type, int idx)
{
	t_intersection	*intersection;

	intersection = (t_intersection *)malloc(sizeof(t_intersection));
	if (intersection == NULL)
	{
		printf("\nErro ao alocar memória para t_intersection\n");
		return (NULL);
	}
	intersection->id = idx;
	// Define o tipo de objeto
	intersection->objtype = type;
	// Inicializa o objeto específico com base no tipo
	// if(type == PLANE)
	// 	intersection->obj = create_t_cube();
	// else if(type == PYRAMID)
	// 	intersection->obj = create_t_pyramid();
	// else if(type == PLANE)
	// 	intersection->obj = create_t_plane();
	if (type == SPHERE)
		intersection->obj = create_t_sphere();
	else
	{
		printf("\nTipo de objeto inválido em init_intersection\n");
		free(intersection);
		return (NULL);
	}
	// Inicializa outros campos, se houver
	intersection->time = 0.0;
	intersection->next = NULL;
	intersection->before = NULL;
	return (intersection);
}

t_intersections	*create_intersections(void)
{
	t_intersections	*intersections;

	intersections = (t_intersections *)malloc(sizeof(t_intersections));
	if (!intersections)
		return (NULL);
	// Inicializa os ponteiros start e end como NULL
	intersections->start = NULL;
	intersections->end = NULL;
	return (intersections);
}

// t_discriminant calc_discriminant_danilo(t_tuple position, t_ray ray, t_sphere sphere) {
//     t_discriminant discriminant;
//     t_tuple sphere_to_position = subtract_tuples(ray.origin, sphere.center);

//     discriminant.a = dot_product(ray.direction, ray.direction);
//     discriminant.b = 2 * dot_product(ray.direction, sphere_to_position);
//     discriminant.c = dot_product(sphere_to_position, sphere_to_position) - (sphere.radius * sphere.radius);
//     discriminant.discriminant = pow(discriminant.b, 2) - (4 * discriminant.a * discriminant.c);
//     return discriminant;
// }

t_intersec	intersect_danilo(double time, t_ray ray, t_intersection *intersection_element)
{
	t_intersec		intersec;
	t_discriminant	discriminant;
	t_tuple			ray_position;
	t_sphere		sphere;

	intersec.count = 0;
	intersec.t[0] = 0;
	intersec.t[1] = 0;
	// if(intersection_element->objtype == SPHERE)
	sphere = *(t_sphere *)(intersection_element->obj);
	ray_position = position(ray, time);
	discriminant = calc_discriminant(ray, sphere);
	if (discriminant.discriminant < 0)
	{
		intersection_element->hitcontact = NO_HIT;
		return(intersec);
	}
	if(discriminant.discriminant == 0)
		intersection_element->hitcontact = ONE_HIT;
	if(discriminant.discriminant > 0)
		intersection_element->hitcontact = TWO_HIT;

	intersec.t[0] = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.t[1] = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.count = 2;
	return(intersec);
}

