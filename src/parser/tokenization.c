/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:50:05 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 18:57:39 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_token(char *line)
{
	t_mini	*control;
	t_token	*new;
	t_token	*last;

	if (!line)
		return ;
	control = get_mini_control();
	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		exit(EXIT_FAILURE);
	new->identifier = ft_substr(line, 0, (ft_strchr(line, ' ') - line));
	new->args = ft_split(line + (ft_strchr(line, ' ') - line), ' ');
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
		ft_free_string_array(token->args);
		free(token->identifier);
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

int	process_type_token(char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp("A", line, 1) == 0)
		add_token(line);
	else if (ft_strncmp("C", line, 1) == 0)
		add_token(line);
	else if (ft_strncmp("L", line, 1) == 0)
		add_token(line);
	else if (ft_strncmp("sp", line, 2) == 0)
		add_token(line);
	else if (ft_strncmp("pl", line, 2) == 0)
		add_token(line);
	else if (ft_strncmp("cy", line, 2) == 0)
		add_token(line);
	return (0);
}

void	tokenize_scene(char *file)
{
	int		fd;
	char	*line;

	fd = read_scene(file);
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf("Error\n%s\n", "Empty scene"));
	while (line != NULL)
	{
		process_type_token(line);
		// if (process_type_token(line) == 0)
		// {
		// 	free_tokens();
		// 	exit(ft_printf("Error\n%s\n", "Invalid scene"));
		// }
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}

