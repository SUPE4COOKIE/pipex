/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:37:53 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/07 19:41:24 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;

	i = 0;
	csrc = (unsigned char *)s;
	while (i < n)
	{
		csrc[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
