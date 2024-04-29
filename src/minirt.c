/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:36:10 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/27 20:39:07 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// t_rt	*get_data(void)
// {
// 	static t_rt	control;

// 	return (&control);
// }

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	split_scene_lines(read_scene(argv[1]), argv[1]);
	// manage_window();
	return (0);
}
