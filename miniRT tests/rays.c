/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:12:23 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/13 17:51:36 by jaqribei         ###   ########.fr       */
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

void *create_t_plane(){}
void *create_t_cylinder(){}
void *create_t_cube(){} 
void *create_t_pyramid(){}

void* create_t_sphere() {
    t_sphere* sphere = (t_sphere*)malloc(sizeof(t_sphere));
    if (sphere == NULL) {
        fprintf(stderr, "Erro ao alocar memória para t_sphere\n");
        return NULL;
    }
    sphere->center = create_point(0, 0, 0);
    sphere->radius = 1.0;
    return(void*)sphere; // Converte o ponteiro de t_sphere para void*
}

t_intersection* create_intersection(t_obj_type type) {
    t_intersection* intersection = (t_intersection*)malloc(sizeof(t_intersection));
    if (intersection == NULL) {
        printf("\nErro ao alocar memória para t_intersection\n");
        return NULL;
    }

    // Define o tipo de objeto
    intersection->objtype = type;

    // Inicializa o objeto específico com base no tipo
	if(type == CUBE){
		intersection->obj = create_t_cube();
	}else if(type == PYRAMID){
		intersection->obj = create_t_pyramid();
	}else if(type == PLANE){
		intersection->obj = create_t_plane();
	}else if(type == SPHERE){
		intersection->obj = create_t_sphere();
	}else{
		printf("\nTipo de objeto inválido em init_intersection\n");
		free(intersection);
		return NULL;
	}

    // Inicializa outros campos, se houver
    intersection->time = 0.0;
    intersection->next = NULL;
    intersection->before = NULL;

	return intersection;
}

t_intersections* create_intersections() {
    t_intersections* intersections = (t_intersections*)malloc(sizeof(t_intersections));
    if (!intersections)
        return NULL;

    // Inicializa os ponteiros start e end como NULL
    intersections->start = NULL;
    intersections->end = NULL;

    return (intersections);
}

void *get_last_intersected_obj(){

	t_intersections* intersections;

	intersections = get_list_intersections(1);
	return(intersections->end->obj);
}

t_intersection *get_last_intersec(){

	t_intersections* intersections;

	intersections = get_list_intersections(1);
	return(intersections->end);
}

t_intersections* get_list_intersections(int action) {
    static t_intersections* intersections;

    if (action == 0){
		intersections = create_intersections();
		if (!intersections)
			return NULL;
		else
			return intersections;
	}
	if (action > 0)
        return intersections;

    free(intersections);
    intersections = NULL;
    return(NULL);
}

int add_last_intersections(t_intersections *intersections, t_obj_type type){
	t_intersection *node;

	node = create_intersection(type);


	if(!node){
		printf("\n FALSE - add_last_intersections\n");
		return(FALSE);
	}
	if (intersections->start == NULL) {
        intersections->start = node;
        intersections->end = node;
    } else {
        intersections->end->next = node;
        node->before = intersections->end;
        intersections->end = node;
    }
	return(TRUE);
}


t_discriminant calc_discriminant_danilo(t_tuple position, t_ray ray, t_sphere sphere) {
    t_discriminant discriminant;
    t_tuple sphere_to_position = subtract_tuples(position, sphere.center);

    discriminant.a = dot_product(ray.direction, ray.direction);
    discriminant.b = 2 * dot_product(ray.direction, sphere_to_position);
    discriminant.c = dot_product(sphere_to_position, sphere_to_position) - 1;
    discriminant.discriminant = pow(discriminant.b, 2) - (4 * discriminant.a * discriminant.c);
    return discriminant;
}


t_intersec	intersect_danilo(double time, t_ray ray, t_intersection *intersection_element){
	double				t1, t2;
	t_intersec			intersec;
	t_discriminant		discriminant;
	t_tuple 			ray_position;
	

	// if(intersection_element->objtype == SPHERE)
		t_sphere sphere = *(t_sphere *)(intersection_element->obj);

	ray_position = position(ray, time);
	discriminant = calc_discriminant_danilo(ray_position, ray, sphere);
	if (discriminant.discriminant < 0)
	{
		intersection_element->hitcontact = NO_HIT;
		return(intersec);
	}
	if(discriminant.discriminant == 0)
		intersection_element->hitcontact = ONE_HIT;
	if(discriminant.discriminant> 0)
		intersection_element->hitcontact = TWO_HIT;

	intersec.t[0] = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.t[1] = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.count = 2;
	return(intersec);
}

void calc_intersection(t_ray ray, t_intersection *intersection_element, double time){
	intersection_element->time = time;
	intersection_element->intersect = intersect_danilo(time, ray, intersection_element);
}

t_intersection *did_hit(t_intersections *intersections){

	t_intersection	*loop = intersections->start;
	t_intersection	*hitted_obj;
	double	hitted_t;

	hitted_obj = loop;
	hitted_t = hitted_obj->intersect.t[0];
	while(loop)
	{
		if(loop->hitcontact == ONE_HIT || loop->hitcontact == TWO_HIT)
		{
			if(hitted_t > loop->intersect.t[0] && loop->intersect.t[0] >= 0){
				hitted_obj = loop;
				hitted_t = hitted_obj->intersect.t[0];
			}else if(hitted_t > loop->intersect.t[1] && loop->intersect.t[1] >= 0){
				hitted_obj = loop;
				hitted_t = hitted_obj->intersect.t[1];
			}
		}
		loop = loop->next;
	}
	return (hitted_obj);
}


// Função que recebe dois arrays e uma função como argumentos
t_ray *transform(t_ray *ray, t_matrix matrix, char *action) {

	t_ray *transformation;

	transformation = (t_ray*)malloc(sizeof(t_ray));
	if(!transformation)
		return(NULL);
	
	// Translação
	if(ft_strcmp(action, "translate")){
		transformation->origin = multiply_matrix_by_tuple(matrix, transformation->origin);
		transformation->direction = multiply_matrix_by_tuple(matrix, transformation->direction);
	}

	

	return(transformation);
}