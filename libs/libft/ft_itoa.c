/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:13:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/09 21:01:56 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int number)
{
	unsigned int	len;

	len = 0;
	if (number <= 0)
	{
		len = len + 1;
	}
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*charnumber;
	int		len;
	long	n_aux;

	len = ft_nlen(n);
	n_aux = n;
	charnumber = malloc ((len + 1) * sizeof(char));
	if (!charnumber)
		return (NULL);
	if (n_aux == 0)
		charnumber[0] = '0';
	if (n_aux < 0)
	{
		charnumber[0] = '-';
		n_aux = n_aux * (-1);
	}
	charnumber[len] = '\0';
	len = len - 1;
	while (n_aux != 0)
	{
		charnumber[len] = n_aux % 10 + '0';
		n_aux = n_aux / 10;
		len--;
	}
	return (charnumber);
}
