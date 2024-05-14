/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:50:05 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/14 01:11:47 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_token(char *line)
{
	t_mini	*control;
	t_token	*new;
	t_token	*last;
	char	**splitted;

	if (!line)
		return ;
	control = get_mini_control();
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		exit(EXIT_FAILURE);
	splitted = ft_split(line, ' ');
	new->identifier = ft_strdup(splitted[0]);
	ft_free_string_array(splitted);
	new->args = ft_split(line + ft_strlen(new->identifier), ' ');
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
		free(token->identifier);
		ft_free_string_array(token->args);
		free(token);
		token = next;
	}
	control->tokens = NULL;
}

void	print_tokens(void)
{
	t_mini	*control;
	t_token	*current;
	int		i;

	control = get_mini_control();
	current = control->tokens;
	while (current != NULL)
	{
		printf("Identifier: %s\n", current->identifier);
		i = 0;
		while (current->args[i] != NULL)
		{
			printf("Arg %d: %s\n", i, current->args[i]);
			i++;
		}
		current = current->next;
	}
}

void	tokenize_scene(char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = read_scene(file);
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\n%s\n", "Empty scene"));
	while (line != NULL)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\n')
			i++;
		if (line[i])
			add_token(line + i);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}
