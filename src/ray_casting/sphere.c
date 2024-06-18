/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:37:30 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/17 21:47:30 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	create_sphere(void) // create a sphere at the origin
{
	t_sphere	sphere;
	static int	id = 0;

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1.0;
	sphere.id = id++;
	return (sphere);
}

void	*create_t_sphere(void)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
	{
		printf("Erro ao alocar memória para t_sphere\n");
		return (NULL);
	}
	sphere->center = create_point(0, 0, 0);
	sphere->radius = 1.0;
	return ((void *)sphere);
}
