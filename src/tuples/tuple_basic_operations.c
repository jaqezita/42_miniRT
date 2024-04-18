/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_basic_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:48 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 12:53:06 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

t_tuple	deny_tuples(t_tuple a)
{
	t_tuple	result;

	result.x = -1 * (a.x);
	result.y = -1 * (a.y);
	result.z = -1 * (a.z);
	result.w = -1 * (a.w);
	return (result);
}

t_tuple	multiply_tuples_scalar(t_tuple a, double number)
{
	t_tuple	result;

	result.x = number * (a.x);
	result.y = number * (a.y);
	result.z = number * (a.z);
	result.w = number * (a.w);
	return (result);
}

t_tuple	divide_tuple_scalar(t_tuple a, double number)
{
	t_tuple	result;

	result.x = (a.x) / number;
	result.y = (a.y) / number;
	result.z = (a.z) / number;
	result.w = (a.w) / number;
	return (result);
}
