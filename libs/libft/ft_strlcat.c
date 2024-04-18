/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:02:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/07 03:26:19 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len;
	size_t	result;

	if (dst != 0)
		len = ft_strlen(dst);
	else
		len = 0;
	index = 0;
	result = (len + ft_strlen(src));
	if (size > len)
	{
		while (src[index] && len < (size - 1))
		{
			dst[len] = src[index];
			len++;
			index++;
		}
		dst[len] = '\0';
		return (result);
	}
	return (ft_strlen(src) + size);
}
