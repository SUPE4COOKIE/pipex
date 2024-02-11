/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:57:44 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/08 01:14:34 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printall(const char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(args, int), 0));
	else if (c == 'u')
		return (ft_printuint(va_arg(args, unsigned int), 0));
	else if (c == 'x')
		return (ft_printhexa(va_arg(args, unsigned int), LOW_HEXA, 0));
	else if (c == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), UP_HEXA, 0));
	else if (c == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		tmp;
	size_t	i;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			tmp = ft_printall(s[++i], args);
			if (tmp == -1)
				return (va_end(args), -1);
			count += tmp;
		}
		else if (++count && ft_printchar((int)s[i]) == -1)
			return (va_end(args), -1);
		i++;
	}
	va_end(args);
	return (count);
}
