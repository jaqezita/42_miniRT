/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:43:13 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/17 21:51:47 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	add_last_intersections(t_intersections *intersections, enum e_obj_type type, int id)
{
	t_intersection	*node;

	node = create_intersection(type, id);
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

void	calc_intersection(t_ray ray, t_intersection *intersection_element, double time)
{
	intersection_element->time = time;
	intersection_element->intersect = intersect_danilo(time, ray, intersection_element);
}
