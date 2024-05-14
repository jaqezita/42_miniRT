/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:28 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/14 01:12:14 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_identifier(char *identifier)
{
	if (ft_strcmp(identifier, "A") == 0 || ft_strcmp(identifier, "C") == 0 \
		|| ft_strcmp(identifier, "L") == 0 || ft_strcmp(identifier, "sp") == 0 \
		|| ft_strcmp(identifier, "pl") == 0 || ft_strcmp(identifier, "cy") == 0)
		return (1);
	return (0);
}

void	validate_identifier(void)
{
	t_mini	*control;
	t_token	*token;

	control = get_mini_control();
	token = control->tokens;
	while (token)
	{
		if (!is_identifier(token->identifier))
		{
			free_tokens();
			exit(ft_printf("Error\n%s\n", "Invalid scene"));
		}
		token = token->next;
	}
}

void	validate_scene(void)
{
	t_mini	*control;

	control = get_mini_control();
	validate_identifier();
}
