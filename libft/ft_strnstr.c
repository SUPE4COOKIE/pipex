/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:32 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/09 18:14:10 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lsize;

	if (!*little)
		return ((char *)big);
	i = 0;
	lsize = ft_strlen((char *)little) - 1;
	while (big[i] && i < len)
	{
		j = 0;
		while ((little[j] == big[i + j]) && (i + j) < len)
		{
			if (j == lsize)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
