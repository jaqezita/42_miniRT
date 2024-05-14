/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:36:10 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/14 01:10:38 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_mini	*get_mini_control(void)
{
	static t_mini	control;

	return (&control);
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	tokenize_scene(argv[1]);
	validate_scene();
	print_tokens();
	free_tokens();
	manage_window();
	return (0);
}
