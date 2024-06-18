/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 04:27:45 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/17 21:48:39 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*did_hit(t_intersections *intersections)
{
	t_intersection	*loop;
	t_intersection	*hitted_obj;
	double			hitted_t;
	double			min_t;

	loop = intersections->start;
	hitted_obj = NULL;
	hitted_t = __DBL_MAX__;
	min_t = __DBL_MAX__;
	while (loop)
	{
		if (loop->hitcontact != NO_HIT) 
		{
			if (loop->hitcontact == ONE_HIT)
				min_t = loop->intersect.t[0];
			else if (loop->hitcontact == TWO_HIT)
				min_t = fmin(loop->intersect.t[0], loop->intersect.t[1]);
			if (min_t >= 0 && min_t < hitted_t)
			{
				hitted_obj = loop;
				hitted_t = min_t;
			}
		}
		loop = loop->next;
	}
	return (hitted_obj);
}
