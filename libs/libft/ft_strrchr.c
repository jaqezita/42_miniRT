/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:17:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/27 20:10:41 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*s_copy;

	s_copy = (char *)s;
	index = (ft_strlen(s_copy));
	while (index >= 0)
	{
		if (s_copy[index] == (char)c)
			return (s_copy + index);
		index--;
	}
	return (NULL);
}
