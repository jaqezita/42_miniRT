/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:49:48 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/14 01:09:56 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_key(mlx_key_data_t keydata, void *p)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)p;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

void	manage_window(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(800, 800, "miniRT", 0);
	mlx_key_hook(mlx, ft_key, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	read_scene(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	return (fd);
}
