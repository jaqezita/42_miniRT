/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:49:48 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 13:59:29 by jaqribei         ###   ########.fr       */
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

int	count_lines_fd(char *file)
{
	int		fd;
	char	*str;
	int		count_lines;

	count_lines = 0;
	fd = read_scene(file);
	str = get_next_line(fd);
	if (!str)
		exit(ft_printf("Error\n%s\n", " "));
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		count_lines++;
	}
	close(fd);
	return (count_lines);
}

void	split_scene_lines(int fd, char *file)
{
	char	**line;
	int		i;

	i = 0;
	line = malloc((count_lines_fd(file) + 1) * sizeof(char *));
	if (!line)
	{
		printf("Error\n");
		exit(1);
	}
	while (1)
	{
		line[i] = get_next_line(fd);
		if (!line[i])
			break ;
		i++;
	}
	print_scene_lines(line, file);
	close(fd);
}

void	print_scene_lines(char **line, char *file)
{
	int	i;
	int	count_lines;

	count_lines = count_lines_fd(file);
	i = 0;
	while (i < count_lines)
	{
		printf("%s", line[i]);
		i++;
	}
	ft_free_string_array(line);
}

void	process_type(char *line)
{
	if (ft_strchr(line, 'A'))
		process_ambient(line);
	if (ft_strchr(line, 'C'))
		process_camera(line);
	if (ft_strchr(line, 'L'))
		process_light(line);
	if (ft_strnstr(line, "sp", ft_strlen(line)))
		process_sphere(line);
	if (ft_strnstr(line, "pl", ft_strlen(line)))
		process_plane(line);
	if (ft_strnstr(line, "cy", ft_strlen(line)))
		process_cylinder(line);
	return ;
}

void	process_ambient(char *line)
{
	char	**split;
	int		i;
	// t_node	*node;
	i = 0;
	split = ft_split(line + i, ' ');
	if (!split)
		exit(ft_printf("Error\n%s\n", " "));
	// ft_lstadd_back(&node, ft_lstnew(ft_atof(split[1])));
	printf("\033[1;36mIdentifier: %s\n", split[0]);
	printf("Ratio: %s\n", split[1]);
	printf("Color: %s\n", split[2]);
	ft_free_string_array(split);
}

void	process_camera(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line + i, ' ');
	printf("Identifier: %s\n", split[0]);
	printf("Coordinates: %s\n", split[1]);
	printf("Orientation: %s\n", split[2]);
	printf("FOV: %s\n", split[3]);
	ft_free_string_array(split);
}

void	process_light(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line + i, ' ');
	printf("Identifier: %s\n", split[0]);
	printf("Coordinates: %s\n", split[1]);
	printf("brightness: %s\n", split[2]);
	printf("Color: %s\n", split[3]);
	ft_free_string_array(split);
}

void	process_sphere(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line + i, ' ');
	printf("Identifier: %s\n", split[0]);
	printf("Coordinates: %s\n", split[1]);
	printf("Diameter: %s\n", split[2]);
	printf("Color: %s\n", split[3]);
	ft_free_string_array(split);
	// create_sphere();
}

void	process_plane(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line + i, ' ');
	printf("Identifier: %s\n", split[0]);
	printf("Coordinates: %s\n", split[1]);
	printf("3d normalized normal vector: %s\n", split[2]);
	printf("Color: %s\n", split[3]);
	ft_free_string_array(split);
	// create_plane();
}

void	process_cylinder(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line + i, ' ');
	printf("Identifier: %s\n", split[0]);
	printf("Coordinates: %s\n", split[1]);
	printf("3d normalized vector of axis of cylinder.: %s\n", split[2]);
	printf("Diameter: %s\n", split[3]);
	printf("Height: %s\n", split[4]);
	printf("Color: %s\n\033[0m", split[5]);
	ft_free_string_array(split);
	// create_cylinder();
}

int	process_scene_file(char *file)
{
	int		fd;
	char	*line;

	fd = read_scene(file);
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\n%s\n", " "));
	// process_type(line);
	process_type_token(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		// process_type(line);
		process_type_token(line);
	}
	close(fd);
	return (0);
}
