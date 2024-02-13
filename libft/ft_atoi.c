/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:01:24 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/14 15:48:41 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r'))
		return (1);
	return (0);
}

static int	return_overflow(long int result, int nptr, int sign)
{
	long int	tmp;

	tmp = (result * 10 + nptr);
	if (result != ((tmp - nptr) / 10))
	{
		if (sign < 0)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit((unsigned char)*nptr))
	{
		if (return_overflow(result, (int)*nptr - '0', sign) != 1)
			return (return_overflow(result, *nptr - '0', sign));
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(result * sign));
}
