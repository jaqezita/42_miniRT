/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:36:10 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 14:25:07 by jaqribei         ###   ########.fr       */
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
	process_scene_file(argv[1]);
	print_tokens();
	free_tokens();
	manage_window();
	return (0);
}
