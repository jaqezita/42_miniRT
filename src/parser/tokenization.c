/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:50:05 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 14:55:23 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	int i;

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