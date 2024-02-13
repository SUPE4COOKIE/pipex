/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:36:18 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/14 03:34:51 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
		write(fd, &(char){nb + '0'}, 1);
	else
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		write(fd, &(char){(nb % 10) + '0'}, 1);
	}
}
