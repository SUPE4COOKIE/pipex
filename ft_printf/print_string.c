/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 04:14:08 by mwojtasi          #+#    #+#             */
/*   Updated: 2024/01/08 01:19:27 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return ((int)count);
}

int	ft_printstr(char *s)
{
	int	count;

	if (!s)
		return (ft_printstr("(null)"));
	count = ft_strlen(s);
	if (count < 0)
		return (-1);
	if (write(1, s, count) == -1)
		return (-1);
	return (count);
}
