/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:20:27 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/18 15:56:58 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_file_extension(char *file_name)
{
	if (!ft_strnstr(file_name, ".rt", ft_strlen(file_name)))
		exit(printf("ERROR: INVALID FILE EXTENSION"));
	return (0);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		exit(printf("ERROR: INVALID NUMBER OF ARGUMENTS"));
	check_file_extension(argv[1]);
}
