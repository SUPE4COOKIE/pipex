/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:46 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/12/04 17:02:30 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long i)
{
	int	count;

	if (i == 0)
		return (ft_printstr("(nil)"));
	count = ft_printstr("0x");
	if (count == -1)
		return (count);
	count += ft_printhexa(i, LOW_HEXA, 0);
	if (count < 2)
		return (-1);
	return (count);
}
