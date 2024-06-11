/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:25:46 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 01:44:15 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*create_intersection(e_obj_type type)
{
	t_intersection	*intersection;

	intersection = (t_intersection *)malloc(sizeof(t_intersection));
	if (intersection == NULL)
	{
		printf("\nErro ao alocar memória para t_intersection\n");
		return (NULL);
	}
	intersection->objtype = type;
	if (type == CUBE)
		intersection->obj = create_t_cube();
	else if (type == PYRAMID)
		intersection->obj = create_t_pyramid();
	else if (type == PLANE)
		intersection->obj = create_t_plane();
	else if (type == SPHERE)
		intersection->obj = create_t_sphere();
	else
	{
		printf("\nTipo de objeto inválido em init_intersection\n");
		free(intersection);
		return (NULL);
	}
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
	intersections->start = NULL;
	intersections->end = NULL;
	return (intersections);
}

void	*get_last_intersected_obj(void)
{
	t_intersections	*intersections;

	intersections = get_list_intersections(1);
	return (intersections->end->obj);
}

t_intersection	*get_last_intersec(void)
{
	t_intersections	*intersections;

	intersections = get_list_intersections(1);
	return (intersections->end);
}

t_intersections	*get_list_intersections(int action)
{
	static t_intersections	*intersections;

	if (action == 0)
	{
		intersections = create_intersections();
		if (!intersections)
			return (NULL);
		else
			return (intersections);
	}
	if (action > 0)
		return (intersections);
	free(intersections);
	intersections = NULL;
	return (NULL);
}
