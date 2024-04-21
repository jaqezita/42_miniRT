/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:36:10 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/21 00:15:22 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx;

	check_args(argc, argv);
	mlx = mlx_init(800, 800, "miniRT", 0);
	mlx_loop(mlx);
	return (0);
}
