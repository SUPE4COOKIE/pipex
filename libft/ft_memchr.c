/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:32:37 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/08 05:34:15 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;

	i = 0;
	csrc = (unsigned char *)s;
	while (i < n)
	{
		if (*csrc == (unsigned char)c)
			return ((void *)csrc);
		csrc++;
		i++;
	}
	return (NULL);
}
