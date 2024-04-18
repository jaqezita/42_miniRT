/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:03:22 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:18:55 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (s_copy != NULL && *s_copy)
	{
		if (*s_copy == (char)c)
			return (s_copy);
		s_copy++;
	}
	if ((unsigned char)c == '\0')
		return (s_copy);
	return (0);
}
