/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:25 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/09 21:03:30 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (*little == 0)
		return ((char *)big);
	while (b < len && big[b] != '\0')
	{
		if (big[b] == little[0])
		{
			l = 0;
			while (big[b + l] == little[l] && (b + l < len))
			{
				if (little[l + 1] == '\0')
					return ((char *)&big[b]);
				l++;
			}
		}
		b++;
	}
	return (NULL);
}
