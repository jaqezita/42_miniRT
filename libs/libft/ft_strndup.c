/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:13:25 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 14:15:36 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char		*new;
	size_t		index;

	new = malloc((n + 1) * sizeof(char));
	if (!new)
		return (NULL);
	index = 0;
	while (s[index] != '\0' && index < n)
	{
		new[index] = s[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
