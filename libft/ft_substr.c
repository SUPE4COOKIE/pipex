/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:08 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/23 00:23:40 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		result[i] = (char)s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
