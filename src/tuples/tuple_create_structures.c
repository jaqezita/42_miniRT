/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_create_structures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:15:49 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:53:24 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	create_point(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1.0;
	return (t);
}

t_tuple	create_vector(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0.0;
	return (t);
}
