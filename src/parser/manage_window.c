/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:49:48 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/29 11:11:31 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **line);

void	ft_key(mlx_t *mlx, mlx_key_data_t *keydata)
{
	if (keydata->key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

void manage_window(void)
{
	mlx_t			*mlx;
	mlx_key_data_t	keydata;


	mlx = mlx_init(800, 800, "miniRT", 0);
	ft_key(mlx, &keydata);
	mlx_key_hook(mlx, (void *)ft_key, &keydata);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	read_scene(char *file)
{
	int fd;

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
			break;
		i++;
	}
	print_scene_lines(line, file);
	close(fd);
}

void	print_scene_lines(char **line, char *file)
{
	int i;
	int	count_lines;

	count_lines = count_lines_fd(file);
	i = 0;
	while (i < count_lines)
	{
		printf("%s\n", line[i]);
		i++;
	}
	free_split(line);
}

void	free_split(char **line)
{
	int i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}


