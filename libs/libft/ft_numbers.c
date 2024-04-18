/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:36:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:31:12 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_numbers(int number)
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

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write (1, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
		ft_recursive(n);
	}
	else
		ft_recursive(n);
	return (n);
}

int	ft_numbers(va_list args)
{
	int	n;
	int	count_nbr;

	count_nbr = 0;
	n = va_arg(args, int);
	count_nbr += ft_count_numbers(n);
	ft_putnbr(n);
	return (count_nbr);
}
