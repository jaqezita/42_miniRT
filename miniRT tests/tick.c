/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:27:14 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/09 13:39:27 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
//#include "MLX42/include/MLX42/MLX42.h"
#include "minilibx-linux/mlx.h"

typedef struct	s_env
{
	t_tuple		gravity;
	t_tuple		wind;
}				t_env;

typedef struct	s_proj
{
	t_tuple		position;
	t_tuple		velocity;
}				t_proj;


t_proj	create_proj(t_tuple position, t_tuple velocity)
{
	t_proj	proj;
	
	proj.position = position;
	proj.velocity = velocity;

	return(proj);
}

t_env	create_env(t_tuple gravity, t_tuple wind)
{
	t_env	env;
	
	env.gravity = gravity;
	env.wind = wind;

	return(env);
}

t_proj	tick(t_env env, t_proj proj)
{
	t_proj	new_proj;
	t_tuple	aux;

	new_proj.position = add_tuples(proj.position, proj.velocity);
	// new_proj.position.y = -1 * new_proj.position.y;
	aux = add_tuples(proj.velocity, env.gravity); 
	new_proj.velocity = add_tuples(aux, env.wind);
	
	return (new_proj);
}


int	main(void)
{
	t_proj	new_proj;
	t_env	e;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 550, "Projectile Simulation");

	// new_proj = create_proj(create_point(0, 1, 0), vector_norm(create_vector(1, 1, 0)));
	// e = create_env(create_vector(0, -0.1, 0), create_vector(-0.01, 0, 0));
	
	new_proj = create_proj(create_point(0, 1, 0), multiply_tuples_scalar( (vector_norm(create_vector(1, 1.8, 0))), 11.25));
	e = create_env(create_vector(0, -0.1, 0), create_vector(-0.01, 0, 0));
	
	int ticks = 0;
	while (new_proj.position.y > 0) 
	{
		new_proj = tick(e, new_proj);
		ticks++;
		printf("Tick %d: Position = (%.2f, %.2f, %.2f)\n", ticks, new_proj.position.x, new_proj.position.y, new_proj.position.z);
		mlx_pixel_put(mlx, win, new_proj.position.x, -new_proj.position.y + 550, 0x00FF00);
		mlx_loop_hook(mlx, 0, 0);
	}

	printf("The projectile hit the ground after %d ticks.\n", ticks);
	mlx_loop(mlx);
	return 0;
}