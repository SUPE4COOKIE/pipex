/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtasi <mwojtasi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:29:00 by mwojtasi          #+#    #+#             */
/*   Updated: 2023/11/23 01:19:58 by mwojtasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*result;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(total_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, (size_t)total_len);
	ft_strlcat(result, (char *)s2, (size_t)total_len);
	return (result);
}
