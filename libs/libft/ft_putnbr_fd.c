/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:15:09 by jaqribei          #+#    #+#             */
/*   Updated: 2023/08/09 21:02:54 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(int n, int fd)
{
	char	charnumber;

	if (n / 10 == 0)
	{
		charnumber = (n % 10) + '0';
		write (fd, &charnumber, 1);
		return ;
	}
	ft_recursive(n / 10, fd);
	charnumber = (n % 10) + '0';
	write (fd, &charnumber, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write (fd, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
		ft_recursive(n, fd);
	}
	else
		ft_recursive(n, fd);
}
