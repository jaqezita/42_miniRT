/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:27:45 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 04:29:55 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*did_hit(t_intersections *intersections)
{
	t_intersection	*loop;
	t_intersection	*hitted_obj;
	double			hitted_t;

	loop = intersections->start;
	hitted_obj = loop;
	hitted_t = hitted_obj->intersect.t[0];
	while (loop)
	{
		if (loop->hitcontact == ONE_HIT || loop->hitcontact == TWO_HIT)
		{
			if (hitted_t > loop->intersect.t[0] && loop->intersect.t[0] >= 0)
			{
				hitted_obj = loop;
				hitted_t = hitted_obj->intersect.t[0];
			}
			else if (hitted_t > loop->intersect.t[1] \
			&& loop->intersect.t[1] >= 0)
			{
				hitted_obj = loop;
				hitted_t = hitted_obj->intersect.t[1];
			}
		}
		loop = loop->next;
	}
	return (hitted_obj);
}
