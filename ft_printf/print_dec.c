/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 04:18:03 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/12/07 05:01:24 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(long int n, int count)
{
	int	tmp;

	if (n < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		n *= -1;
		count++;
	}
	if (n > 9)
	{
		tmp = ft_printint((n / 10), ++count);
		if (ft_printchar((n % 10) + '0') == -1)
			return (-1);
		return (tmp);
	}
	if (ft_printchar(n + '0') == -1)
		return (-1);
	return (++count);
}

int	ft_printuint(unsigned int n, int count)
{
	int	tmp;

	if (n > 9)
	{
		tmp = ft_printint((n / 10), ++count);
		if (ft_printchar((n % 10) + '0') == -1)
			return (-1);
		return (tmp);
	}
	if (ft_printchar(n + '0') == -1)
		return (-1);
	return (++count);
}
