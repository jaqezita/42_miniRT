/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:35:28 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 14:27:27 by jaqribei         ###   ########.fr       */
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

void	add_token(char *line)
{
	t_mini	*control;
	t_token	*new;
	t_token	*last;
	
	control = get_mini_control();
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		exit(EXIT_FAILURE);
	new->identifier = ft_strndup(line, 2);
	new->args = ft_split(line + 2, ' ');
	new->next = NULL;
	if (!control->tokens)
		control->tokens = new;
	else
	{
		last = control->tokens;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	process_type_token(char *line)
{
	if (ft_strchr(line, 'A'))
		add_token(line);
	if (ft_strchr(line, 'C'))
		add_token(line);
	if (ft_strchr(line, 'L'))
		add_token(line);
	if (ft_strnstr(line, "sp", ft_strlen(line)))
		add_token(line);
	if (ft_strnstr(line, "pl", ft_strlen(line)))
		add_token(line);
	if (ft_strnstr(line, "cy", ft_strlen(line)))
		add_token(line);
	return ;
}

void	free_tokens(void)
{
	t_mini	*control;
	t_token	*token;
	t_token	*next;

	control = get_mini_control();
	token = control->tokens;
	while (token)
	{
		next = token->next;
		ft_free_string_array(token->args);
		free(token->identifier);
		free(token);
		token = next;
	}
	control->tokens = NULL;
}

void print_tokens(void)
{
    t_mini *control;
    t_token *current;

    control = get_mini_control();
    current = control->tokens;

    while (current != NULL)
    {
        printf("Identifier: %s\n", current->identifier);
        // Assuming args is a null-terminated array of strings
        for (int i = 0; current->args[i] != NULL; i++)
        {
            printf("Arg %d: %s\n", i, current->args[i]);
        }
        current = current->next;
    }
}