/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser?.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:28 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/29 11:04:40 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	read_scene(char *file)
// {
// 	int fd;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error\n");
// 		exit(1);
// 	}
// 	return (fd);
// }

int	process_type(char *line)
{
	if (ft_strcmp("A", line))
		return (process_ambient(line));
	if (ft_strcmp("C", line))
		return (process_camera(line));
	if (ft_strcmp("L", line))
		return (process_light(line));
	if (ft_strcmp("sp", line))
		return (process_sphere(line));
	if (ft_strcmp("pl", line))
		return (process_plane(line));
	if (ft_strcmp("cy", line))
		return (process_cylinder(line));
	return (0);
}

int	process_scene_file(char *file)
{
	int		fd;
	char	*line;

	fd = read_scene(file);
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\n%s\n", " "));
	while (line != NULL)
	{
		line = get_next_line(fd);
		process_type(line);
		free(line);
	}
	close(fd);
	return (0);
}