/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:22:57 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/16 00:48:34 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (!dest && !src)
		return (NULL);
	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	while (n--)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
