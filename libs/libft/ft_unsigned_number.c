/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:47:24 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:36:54 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_numbers(unsigned int number)
{
	int	count;

	count = 0;
	if (number <= 0)
	{
		count = count + 1;
	}
	while (number != 0)
	{
		count++;
		number = number / 10;
	}
	return (count);
}

static void	ft_recursive(size_t n)
{
	char	char_number;

	if (n / 10 == 0)
	{
		char_number = (n % 10) + '0';
		write (1, &char_number, 1);
		return ;
	}
	ft_recursive(n / 10);
	char_number = (n % 10) + '0';
	write (1, &char_number, 1);
}

size_t	ft_putnbr_unsigned(size_t n)
{
	if (n < 0)
	{
		n = n + (4294967295 + 1);
		ft_recursive(n);
	}
	else
		ft_recursive(n);
	return (n);
}

size_t	ft_unsigned_number(va_list args)
{
	unsigned int	n;
	int				count_nbr;

	n = va_arg(args, unsigned int);
	ft_putnbr_unsigned(n);
	count_nbr = ft_count_numbers(n);
	return (count_nbr);
}
