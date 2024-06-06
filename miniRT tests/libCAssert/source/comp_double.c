/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:02:38 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/21 21:49:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

int	le_double(double a, double b)
{
	return (a <= b);
}

int	lt_double(double a, double b)
{
	return (a < b);
}

int	eq_double(double a, double b)
{
	return (a == b);
}

int	gt_double(double a, double b)
{
	return (a > b);
}

int	ge_double(double a, double b)
{
	return (a >= b);
}
